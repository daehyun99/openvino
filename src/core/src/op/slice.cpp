// Copyright (C) 2018-2026 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "openvino/op/slice.hpp"

#include "common_op_table.hpp"
#include "common_translators.hpp"
#include "helper_ops/complex_type_mark.hpp"
#include "openvino/op/add.hpp"
#include "openvino/op/broadcast.hpp"
#include "openvino/op/convert_like.hpp"
#include "openvino/op/less.hpp"
#include "openvino/op/select.hpp"
#include "openvino/op/shape_of.hpp"
#include "utils.hpp"
#include "openvino/op/constant.hpp"

using namespace std;
using namespace ov::op;

namespace ov {
namespace frontend {
namespace tensorflow {
namespace op {

OutputVector translate_slice_op(const NodeContext& node) {
    default_op_checks(node, 3, {"Slice", "SLICE"}, true);

    auto input = node.get_input(0);
    auto start = node.get_input(1);
    auto size  = node.get_input(2);

    auto complex_mark = as_type_ptr<ComplexTypeMark>(input.get_node_shared_ptr());

    // 1) complex면 underlying FP 텐서로 "data"를 교체
    Output<Node> data = input;
    element::Type complex_part_type;
    if (complex_mark) {
        complex_part_type = complex_mark->get_complex_part_type();
        // issue 예제 스타일과 맞추려면 input_value(0) 사용 권장 :contentReference[oaicite:5]{index=5}
        data = complex_mark->input_value(0);  // 또는 get_data()가 동일 동작이면 그걸 써도 OK
    }

    auto const_one  = create_same_type_const_scalar<int32_t>(start, 1);
    auto const_zero = create_same_type_const_scalar<int32_t>(start, 0);

    auto stop_pos = std::make_shared<v1::Add>(start, size);

    // 2) stop_neg는 ShapeOf(data)로 계산 (절대 ShapeOf(input) 쓰지 않기!)
    Output<Node> stop_neg = std::make_shared<v3::ShapeOf>(data);

    // len(start) = ShapeOf(start) = [N] (1D 텐서)
    auto start_shape = std::make_shared<v3::ShapeOf>(start);

    // start/stop/step은 1D + 동일 타입이어야 함 :contentReference[oaicite:6]{index=6}
    auto ind_et = start_shape->get_output_element_type(0); // 보통 i64
    auto idx0 = v0::Constant::create(ind_et, Shape{1}, {0});
    auto idx1 = v0::Constant::create(ind_et, Shape{1}, {1});

    // stop_neg = ShapeOf(data)[0 : len(start)]  -> complex 표현에서 마지막 축(2) 제거 목적
    stop_neg = std::make_shared<v8::Slice>(stop_neg, idx0, start_shape, idx1);
    stop_neg = std::make_shared<v1::ConvertLike>(stop_neg, size);

    auto negative_sizes_mask = std::make_shared<v1::Less>(size, const_zero);
    auto stop = std::make_shared<v1::Select>(negative_sizes_mask, stop_neg, stop_pos);

    auto step = std::make_shared<v3::Broadcast>(const_one, start_shape);

    auto slice = std::make_shared<v8::Slice>(data, start, stop, step);
    set_node_name(node.get_name(), slice);

    if (complex_mark) {
        auto complex_slice = std::make_shared<ComplexTypeMark>(slice->output(0), complex_part_type);
        return complex_slice->outputs();
    }

    return slice->outputs();
}
}  // namespace op
}  // namespace tensorflow
}  // namespace frontend
}  // namespace ov
