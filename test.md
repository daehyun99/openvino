
```sh
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
Running main() from /content/openvino/src/frontends/tests/frontend/shared/gtest_main_manifest/main.cpp:20
Note: Google Test filter = *onnx_col2im_default:-:ONNXLoadTest/FrontEndLoadFromTest.testLoadFromTwoFiles/onnx:ONNXLoadTest/FrontEndLoadFromTest.testLoadFromTwoStreams/onnx
[==========] Running 3 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 1 test from INTERPRETER
[ RUN      ] INTERPRETER.onnx_col2im_default
[New Thread 0x1555511ff640 (LWP 109608)]
[New Thread 0x155550ffe640 (LWP 109609)]
[New Thread 0x155550dfd640 (LWP 109610)]
[   INFO   ] Verifying match of <= 22 mantissa bits (24 bits precision - 2 tolerance). 0 value(s) below min_signal: 0 Loosest match found is 24 mantissa bits.
[Thread 0x155550dfd640 (LWP 109610) exited]
[Thread 0x155550ffe640 (LWP 109609) exited]
[Thread 0x1555511ff640 (LWP 109608) exited]
[       OK ] INTERPRETER.onnx_col2im_default (2196 ms)
[----------] 1 test from INTERPRETER (2196 ms total)

[----------] 1 test from IE_GPU
[ RUN      ] IE_GPU.onnx_col2im_default
unknown file: Failure
C++ exception with description "Exception from src/inference/src/cpp/core.cpp:116:
Exception from src/inference/src/dev/plugin.cpp:53:
Check 'contexts.count(device_id)' failed at src/plugins/intel_gpu/src/plugin/plugin.cpp:287:
[GPU] Context was not initialized for 0 device


" thrown in the test body.
[  FAILED  ] IE_GPU.onnx_col2im_default (51695 ms)
[----------] 1 test from IE_GPU (51695 ms total)

[----------] 1 test from IE_CPU
[ RUN      ] IE_CPU.onnx_col2im_default
[New Thread 0x1555511ff640 (LWP 109963)]
[Thread 0x1555511ff640 (LWP 109963) exited]
[New Thread 0x1555511ff640 (LWP 109964)]
[New Thread 0x155550ffe640 (LWP 109965)]
[New Thread 0x155550dfd640 (LWP 109966)]
[New Thread 0x1555507f8640 (LWP 109967)]
[Thread 0x155550ffe640 (LWP 109965) exited]
[Thread 0x1555511ff640 (LWP 109964) exited]
[New Thread 0x1555505f7640 (LWP 109968)]
[New Thread 0x155539f3f640 (LWP 109969)]
[New Thread 0x155539b3e640 (LWP 109970)]

Thread 1 "ov_onnx_fronten" received signal SIGSEGV, Segmentation fault.
0x000015553a3245a8 in std::__fill_a1<float*, float> (__first=0x0, __last=0x24, __value=@0x7fffffffc1c0: 0) at /usr/include/c++/11/bits/stl_algobase.h:924
924		*__first = __tmp;
#0  0x000015553a3245a8 in std::__fill_a1<float*, float> (__first=0x0, __last=0x24, __value=@0x7fffffffc1c0: 0) at /usr/include/c++/11/bits/stl_algobase.h:924
#1  0x000015553a3244f8 in std::__fill_a<float*, float> (__first=0x0, __last=0x24, __value=@0x7fffffffc1c0: 0) at /usr/include/c++/11/bits/stl_algobase.h:969
#2  0x000015553a7cb36b in std::__fill_n_a<float*, long, float> (__first=0x0, __n=9, __value=@0x7fffffffc1c0: 0) at /usr/include/c++/11/bits/stl_algobase.h:1120
#3  0x000015553a7ca90d in std::fill_n<float*, long, float> (__first=0x0, __n=9, __value=@0x7fffffffc1c0: 0) at /usr/include/c++/11/bits/stl_algobase.h:1149
#4  0x000015553a7ca270 in ov::reference::col2im<float, int> (data=0x555556ba57b0, data_shape=..., output_size=0x15554c00b880, kernel_size=0x15554c00b8a0, out=0x0, strides=..., dilations=..., pads_begin=..., pads_end=...) at /content/openvino/src/core/reference/include/openvino/reference/col2im.hpp:30
#5  0x000015553a7c9cf6 in ov::intel_cpu::node::Col2Im::executeImpl<float, int> (this=0x15554c006750) at /content/openvino/src/plugins/intel_cpu/src/nodes/col2im.cpp:94
#6  0x000015553a7c98c7 in ov::intel_cpu::node::Col2Im::Col2ImExecute<std::tuple<float, int> >::operator() (this=0x7fffffffc306, ctx=...) at /content/openvino/src/plugins/intel_cpu/src/nodes/col2im.cpp:117
#7  0x000015553a7c9582 in openvino::cc::internal::match<ov::intel_cpu::node::Col2Im::Col2ImExecute, ov::intel_cpu::node::(anonymous namespace)::Col2ImContext&, std::tuple<ov::element::Type&, ov::element::Type&>&, openvino::cc::internal::case_wrapper<std::tuple<ov::element::Type, ov::element::Type>, std::tuple<float, int> > > (ctx=..., val=std::tuple containing = {...}, cs=...) at /content/openvino/src/common/conditional_compilation/include/openvino/cc/selective_build.h:96
#8  0x000015553a7c918c in openvino::cc::internal::match<ov::intel_cpu::node::Col2Im::Col2ImExecute, ov::intel_cpu::node::(anonymous namespace)::Col2ImContext&, std::tuple<ov::element::Type&, ov::element::Type&>, openvino::cc::internal::case_wrapper<std::tuple<ov::element::Type, ov::element::Type>, std::tuple<float, int> >, openvino::cc::internal::case_wrapper<std::tuple<ov::element::Type, ov::element::Type>, std::tuple<ov::float16, int> >, openvino::cc::internal::case_wrapper<std::tuple<ov::element::Type, ov::element::Type>, std::tuple<ov::bfloat16, int> >, openvino::cc::internal::case_wrapper<std::tuple<ov::element::Type, ov::element::Type>, std::tuple<int, int> >, openvino::cc::internal::case_wrapper<std::tuple<ov::element::Type, ov::element::Type>, std::tuple<signed char, int> >, openvino::cc::internal::case_wrapper<std::tuple<ov::element::Type, ov::element::Type>, std::tuple<unsigned char, int> > > (ctx=..., val=..., cs=...) at /content/openvino/src/common/conditional_compilation/include/openvino/cc/selective_build.h:102
#9  0x000015553a7c8e35 in ov::intel_cpu::node::Col2Im::execute (this=0x15554c006750, strm=...) at /content/openvino/src/plugins/intel_cpu/src/nodes/col2im.cpp:126
#10 0x000015553a7c8ab6 in ov::intel_cpu::node::Col2Im::executeDynamicImpl (this=0x15554c006750, strm=...) at /content/openvino/src/plugins/intel_cpu/src/nodes/col2im.cpp:89
#11 0x000015553a719719 in ov::intel_cpu::Node::executeDynamic (this=0x15554c006750, strm=..., numaId=0) at /content/openvino/src/plugins/intel_cpu/src/node.cpp:838
#12 0x000015553a71964f in ov::intel_cpu::Node::execute (this=0x15554c006750, strm=..., numaId=0) at /content/openvino/src/plugins/intel_cpu/src/node.cpp:824
#13 0x000015553a624667 in ov::intel_cpu::Graph::ExecuteNode (this=0x555556cd2fd0, node=std::shared_ptr<ov::intel_cpu::Node> (use count 2, weak count 4) = {...}, request=0x555556c8e700, numaId=0) at /content/openvino/src/plugins/intel_cpu/src/graph.cpp:1614
#14 0x000015553a624770 in ov::intel_cpu::Graph::ExecuteNodeWithCatch (this=0x555556cd2fd0, node=std::shared_ptr<ov::intel_cpu::Node> (use count 2, weak count 4) = {...}, request=0x555556c8e700, numaId=0) at /content/openvino/src/plugins/intel_cpu/src/graph.cpp:1621
#15 0x000015553a62d791 in ov::intel_cpu::Graph::InferDynamic<ov::intel_cpu::(anonymous namespace)::UpdateNodesSeq> (this=0x555556cd2fd0, request=0x555556c8e700, numaId=0, update=...) at /content/openvino/src/plugins/intel_cpu/src/graph.cpp:1638
#16 0x000015553a624ba5 in ov::intel_cpu::Graph::Infer (this=0x555556cd2fd0, request=0x555556c8e700) at /content/openvino/src/plugins/intel_cpu/src/graph.cpp:1665
#17 0x000015553a6acc23 in ov::intel_cpu::SyncInferRequest::infer (this=0x555556c8e700) at /content/openvino/src/plugins/intel_cpu/src/infer_request.cpp:140
#18 0x00001555537d2d94 in operator() (__closure=0x5555569b0850) at /content/openvino/src/inference/src/dev/iasync_infer_request.cpp:54
#19 0x00001555537dd424 in std::__invoke_impl<void, ov::IAsyncInferRequest::IAsyncInferRequest(const std::shared_ptr<ov::IInferRequest>&, const std::shared_ptr<ov::threading::ITaskExecutor>&, const std::shared_ptr<ov::threading::ITaskExecutor>&)::<lambda()>&>(std::__invoke_other, struct {...} &) (__f=...) at /usr/include/c++/11/bits/invoke.h:61
#20 0x00001555537dbf3d in std::__invoke_r<void, ov::IAsyncInferRequest::IAsyncInferRequest(const std::shared_ptr<ov::IInferRequest>&, const std::shared_ptr<ov::threading::ITaskExecutor>&, const std::shared_ptr<ov::threading::ITaskExecutor>&)::<lambda()>&>(struct {...} &) (__fn=...) at /usr/include/c++/11/bits/invoke.h:111
#21 0x00001555537da74b in std::_Function_handler<void(), ov::IAsyncInferRequest::IAsyncInferRequest(const std::shared_ptr<ov::IInferRequest>&, const std::shared_ptr<ov::threading::ITaskExecutor>&, const std::shared_ptr<ov::threading::ITaskExecutor>&)::<lambda()> >::_M_invoke(const std::_Any_data &) (__functor=...) at /usr/include/c++/11/bits/std_function.h:290
#22 0x00001555537d59aa in std::function<void ()>::operator()() const (this=0x5555569b0850) at /usr/include/c++/11/bits/std_function.h:590
#23 0x00001555537d3f93 in operator() (__closure=0x5555569807b0, callbackExecutor=std::shared_ptr<ov::threading::ITaskExecutor> (empty) = {...}) at /content/openvino/src/inference/src/dev/iasync_infer_request.cpp:139
#24 0x00001555537df9a3 in std::__invoke_impl<void, ov::IAsyncInferRequest::make_next_stage_task(std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::shared_ptr<ov::threading::ITaskExecutor>)::<lambda(std::shared_ptr<ov::threading::ITaskExecutor>&)>&, std::shared_ptr<ov::threading::ITaskExecutor>&>(std::__invoke_other, struct {...} &) (__f=...) at /usr/include/c++/11/bits/invoke.h:61
#25 0x00001555537df389 in std::__invoke<ov::IAsyncInferRequest::make_next_stage_task(std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::shared_ptr<ov::threading::ITaskExecutor>)::<lambda(std::shared_ptr<ov::threading::ITaskExecutor>&)>&, std::shared_ptr<ov::threading::ITaskExecutor>&>(struct {...} &) (__fn=...) at /usr/include/c++/11/bits/invoke.h:96
#26 0x00001555537deba5 in std::_Bind<ov::IAsyncInferRequest::make_next_stage_task(std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::shared_ptr<ov::threading::ITaskExecutor>)::<lambda(std::shared_ptr<ov::threading::ITaskExecutor>&)>(std::shared_ptr<ov::threading::ITaskExecutor>)>::__call<void, 0>(std::tuple<> &&, std::_Index_tuple<0>) (this=0x5555569807b0, __args=...) at /usr/include/c++/11/functional:420
#27 0x00001555537dd86f in std::_Bind<ov::IAsyncInferRequest::make_next_stage_task(std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::shared_ptr<ov::threading::ITaskExecutor>)::<lambda(std::shared_ptr<ov::threading::ITaskExecutor>&)>(std::shared_ptr<ov::threading::ITaskExecutor>)>::operator()<>(void) (this=0x5555569807b0) at /usr/include/c++/11/functional:503
#28 0x00001555537dc312 in std::__invoke_impl<void, std::_Bind<ov::IAsyncInferRequest::make_next_stage_task(std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::shared_ptr<ov::threading::ITaskExecutor>)::<lambda(std::shared_ptr<ov::threading::ITaskExecutor>&)>(std::shared_ptr<ov::threading::ITaskExecutor>)>&>(std::__invoke_other, std::_Bind<ov::IAsyncInferRequest::make_next_stage_task(std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::shared_ptr<ov::threading::ITaskExecutor>)::<lambda(std::shared_ptr<ov::threading::ITaskExecutor>&)>(std::shared_ptr<ov::threading::ITaskExecutor>)> &) (__f=...) at /usr/include/c++/11/bits/invoke.h:61
#29 0x00001555537daade in std::__invoke_r<void, std::_Bind<ov::IAsyncInferRequest::make_next_stage_task(std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::shared_ptr<ov::threading::ITaskExecutor>)::<lambda(std::shared_ptr<ov::threading::ITaskExecutor>&)>(std::shared_ptr<ov::threading::ITaskExecutor>)>&>(std::_Bind<ov::IAsyncInferRequest::make_next_stage_task(std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::shared_ptr<ov::threading::ITaskExecutor>)::<lambda(std::shared_ptr<ov::threading::ITaskExecutor>&)>(std::shared_ptr<ov::threading::ITaskExecutor>)> &) (__fn=...) at /usr/include/c++/11/bits/invoke.h:111
#30 0x00001555537d8f78 in std::_Function_handler<void(), std::_Bind<ov::IAsyncInferRequest::make_next_stage_task(std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void()> > >::iterator, std::shared_ptr<ov::threading::ITaskExecutor>)::<lambda(std::shared_ptr<ov::threading::ITaskExecutor>&)>(std::shared_ptr<ov::threading::ITaskExecutor>)> >::_M_invoke(const std::_Any_data &) (__functor=...) at /usr/include/c++/11/bits/std_function.h:290
#31 0x00001555537d59aa in std::function<void ()>::operator()() const (this=0x55555694d6e0) at /usr/include/c++/11/bits/std_function.h:590
#32 0x00001555538478ba in tbb::detail::d1::task_arena_function<std::function<void ()> const, void>::operator()() const (this=0x7fffffffd0a0) at /content/openvino/temp/Linux_x86_64/tbb/include/oneapi/tbb/task_arena.h:68
#33 0x00001555525d6f23 in ?? () from /content/openvino/temp/Linux_x86_64/tbb/lib/libtbb.so.12
#34 0x000015555383fdc6 in tbb::detail::d1::task_arena::execute_impl<void, std::function<void ()> const>(std::function<void ()> const&) (this=0x555556977490, f=...) at /content/openvino/temp/Linux_x86_64/tbb/include/oneapi/tbb/task_arena.h:251
#35 0x000015555383c683 in tbb::detail::d1::task_arena::execute<std::function<void ()> const>(std::function<void ()> const&&) (this=0x555556977490, f=...) at /content/openvino/temp/Linux_x86_64/tbb/include/oneapi/tbb/task_arena.h:404
#36 0x0000155553839692 in custom::task_arena::execute<std::function<void ()> const>(std::function<void ()> const&&) (this=0x555556977490, f=...) at /content/openvino/src/inference/src/dev/threading/parallel_custom_arena.hpp:149
#37 0x00001555538360b0 in ov::threading::CPUStreamsExecutor::Impl::Execute(std::function<void ()> const&, ov::threading::CPUStreamsExecutor::Impl::Stream&) (this=0x555556a0a580, task=..., stream=...) at /content/openvino/src/inference/src/dev/threading/cpu_streams_executor.cpp:414
#38 0x000015555383617e in ov::threading::CPUStreamsExecutor::Impl::Defer(std::function<void ()>) (this=0x555556a0a580, task=...) at /content/openvino/src/inference/src/dev/threading/cpu_streams_executor.cpp:461
#39 0x0000155553836b70 in ov::threading::CPUStreamsExecutor::execute(std::function<void ()>) (this=0x555556b66670, task=...) at /content/openvino/src/inference/src/dev/threading/cpu_streams_executor.cpp:546
#40 0x00001555537d2866 in (anonymous namespace)::ImmediateStreamsExecutor::run (this=0x555556c9a780, task=...) at /content/openvino/src/inference/src/dev/iasync_infer_request.cpp:25
#41 0x00001555537d3b45 in ov::IAsyncInferRequest::run_first_stage(__gnu_cxx::__normal_iterator<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void ()> >*, std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void ()> >, std::allocator<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void ()> > > > >, __gnu_cxx::__normal_iterator<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void ()> >*, std::vector<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void ()> >, std::allocator<std::pair<std::shared_ptr<ov::threading::ITaskExecutor>, std::function<void ()> > > > >, std::shared_ptr<ov::threading::ITaskExecutor>) (this=0x555556a91670, itBeginStage={first = std::shared_ptr<ov::threading::ITaskExecutor> (use count 1, weak count 0) = {get() = 0x555556c9a780}, second = {<std::_Maybe_unary_or_binary_function<void>> = {<No data fields>}, <std::_Function_base> = {static _M_max_size = 16, static _M_max_align = 8, _M_functor = {_M_unused = {_M_object = 0x555556a91670, _M_const_object = 0x555556a91670, _M_function_pointer = 0x555556a91670, _M_member_pointer = (void (std::_Undefined_class::*)(std::_Undefined_class * const)) 0x555556a91670}, _M_pod_data = "p\026\251VUU\000\000\000\000\000\000\000\000\000"}, _M_manager = 0x1555537da74e <std::_Function_handler<void(), ov::IAsyncInferRequest::IAsyncInferRequest(const std::shared_ptr<ov::IInferRequest>&, const std::shared_ptr<ov::threading::ITaskExecutor>&, const std::shared_ptr<ov::threading::ITaskExecutor>&)::<lambda()> >::_M_manager(std::_Any_data &, const std::_Any_data &, std::_Manager_operation)>}, _M_invoker = 0x1555537da727 <std::_Function_handler<void(), ov::IAsyncInferRequest::IAsyncInferRequest(const std::shared_ptr<ov::IInferRequest>&, const std::shared_ptr<ov::threading::ITaskExecutor>&, const std::shared_ptr<ov::threading::ITaskExecutor>&)::<lambda()> >::_M_invoke(const std::_Any_data &)>}}, itEndStage={first = <error reading variable: Cannot access memory at address 0x29>, second = {<std::_Maybe_unary_or_binary_function<void>> = {<No data fields>}, <std::_Function_base> = {static _M_max_size = 16, static _M_max_align = 8, _M_functor = {_M_unused = {_M_object = 0x5555569b0900, _M_const_object = 0x5555569b0900, _M_function_pointer = 0x5555569b0900, _M_member_pointer = (void (std::_Undefined_class::*)(std::_Undefined_class * const)) 0x5555569b0900, this adjustment 93825013582096}, _M_pod_data = "\000\t\233VUU\000\000\020\t\233VUU\000"}, _M_manager = 0x5555569b0910}, _M_invoker = 0x41}}, callbackExecutor=std::shared_ptr<ov::threading::ITaskExecutor> (empty) = {...}) at /content/openvino/src/inference/src/dev/iasync_infer_request.cpp:124
#42 0x00001555537d394c in ov::IAsyncInferRequest::infer_thread_unsafe (this=0x555556a91670) at /content/openvino/src/inference/src/dev/iasync_infer_request.cpp:112
#43 0x00001555537d4a73 in operator() (__closure=0x7fffffffd4a8) at /content/openvino/src/inference/src/dev/iasync_infer_request.cpp:262
#44 0x00001555537d71af in ov::IAsyncInferRequest::infer_impl<ov::IAsyncInferRequest::infer()::<lambda()> >(const struct {...} &) (this=0x555556a91670, f=...) at /content/openvino/src/inference/dev_api/openvino/runtime/iasync_infer_request.hpp:261
#45 0x00001555537d4ac4 in ov::IAsyncInferRequest::infer (this=0x555556a91670) at /content/openvino/src/inference/src/dev/iasync_infer_request.cpp:261
#46 0x000015553a2a6019 in operator() (__closure=0x555556a917a8) at /content/openvino/src/plugins/intel_cpu/src/async_infer_request.cpp:25
#47 0x000015553a2a845a in std::__invoke_impl<void, ov::intel_cpu::AsyncInferRequest::AsyncInferRequest(const std::shared_ptr<ov::IInferRequest>&, const std::shared_ptr<ov::threading::ITaskExecutor>&, const std::shared_ptr<ov::threading::ITaskExecutor>&, bool)::<lambda()>&>(std::__invoke_other, struct {...} &) (__f=...) at /usr/include/c++/11/bits/invoke.h:61
#48 0x000015553a2a7dbb in std::__invoke_r<void, ov::intel_cpu::AsyncInferRequest::AsyncInferRequest(const std::shared_ptr<ov::IInferRequest>&, const std::shared_ptr<ov::threading::ITaskExecutor>&, const std::shared_ptr<ov::threading::ITaskExecutor>&, bool)::<lambda()>&>(struct {...} &) (__fn=...) at /usr/include/c++/11/bits/invoke.h:111
#49 0x000015553a2a76a1 in std::_Function_handler<void(), ov::intel_cpu::AsyncInferRequest::AsyncInferRequest(const std::shared_ptr<ov::IInferRequest>&, const std::shared_ptr<ov::threading::ITaskExecutor>&, const std::shared_ptr<ov::threading::ITaskExecutor>&, bool)::<lambda()> >::_M_invoke(const std::_Any_data &) (__functor=...) at /usr/include/c++/11/bits/std_function.h:290
#50 0x000015553a2a6c00 in std::function<void ()>::operator()() const (this=0x555556a917a8) at /usr/include/c++/11/bits/std_function.h:590
#51 0x000015553a2a6444 in ov::intel_cpu::AsyncInferRequest::infer (this=0x555556a91670) at /content/openvino/src/plugins/intel_cpu/src/async_infer_request.cpp:54
#52 0x0000155553783b52 in ov::InferRequest::infer (this=0x7fffffffd930) at /content/openvino/src/inference/src/cpp/infer_request.cpp:224
#53 0x00005555560e4a34 in ov::test::TestCase::run (this=0x7fffffffd910, tolerance_bits=2) at /content/openvino/src/tests/test_utils/common_test_utils/src/test_case.cpp:227
#54 0x0000555555d1f2d0 in IE_CPU_IE_CPU_onnx_col2im_default_Test::TestBody (this=0x55555688e050) at /content/openvino/build/src/frontends/onnx/tests/onnx_import_IE_CPU.cpp:348
#55 0x000055555613682e in testing::internal::HandleSehExceptionsInMethodIfSupported<testing::Test, void> (object=0x55555688e050, method=&virtual testing::Test::TestBody(), location=0x55555628a853 "the test body") at /content/openvino/thirdparty/gtest/gtest/googletest/src/gtest.cc:2433
#56 0x000055555613144b in testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void> (object=0x55555688e050, method=&virtual testing::Test::TestBody(), location=0x55555628a853 "the test body") at /content/openvino/thirdparty/gtest/gtest/googletest/src/gtest.cc:2469
#57 0x0000555556116286 in testing::Test::Run (this=0x55555688e050) at /content/openvino/thirdparty/gtest/gtest/googletest/src/gtest.cc:2508
#58 0x0000555556116c9d in testing::TestInfo::Run (this=0x55555678ef10) at /content/openvino/thirdparty/gtest/gtest/googletest/src/gtest.cc:2684
#59 0x0000555556117423 in testing::TestSuite::Run (this=0x5555567510d0) at /content/openvino/thirdparty/gtest/gtest/googletest/src/gtest.cc:2816
#60 0x00005555561239b9 in testing::internal::UnitTestImpl::RunAllTests (this=0x5555565c7460) at /content/openvino/thirdparty/gtest/gtest/googletest/src/gtest.cc:5338
#61 0x0000555556137803 in testing::internal::HandleSehExceptionsInMethodIfSupported<testing::internal::UnitTestImpl, bool> (object=0x5555565c7460, method=(bool (testing::internal::UnitTestImpl::*)(testing::internal::UnitTestImpl * const)) 0x5555561235c2 <testing::internal::UnitTestImpl::RunAllTests()>, location=0x55555628b158 "auxiliary test code (environments or event listeners)") at /content/openvino/thirdparty/gtest/gtest/googletest/src/gtest.cc:2433
#62 0x000055555613240d in testing::internal::HandleExceptionsInMethodIfSupported<testing::internal::UnitTestImpl, bool> (object=0x5555565c7460, method=(bool (testing::internal::UnitTestImpl::*)(testing::internal::UnitTestImpl * const)) 0x5555561235c2 <testing::internal::UnitTestImpl::RunAllTests()>, location=0x55555628b158 "auxiliary test code (environments or event listeners)") at /content/openvino/thirdparty/gtest/gtest/googletest/src/gtest.cc:2469
#63 0x0000555556122349 in testing::UnitTest::Run (this=0x5555565ade60 <testing::UnitTest::GetInstance()::instance>) at /content/openvino/thirdparty/gtest/gtest/googletest/src/gtest.cc:4925
#64 0x0000555555fb5385 in RUN_ALL_TESTS () at /content/openvino/thirdparty/gtest/gtest/googletest/include/gtest/gtest.h:2473
#65 0x0000555555fb540e in FrontEndTestUtils::run_tests (argc=28, argv=0x7fffffffdfb8, manifest="/content/openvino/bin/intel64/Debug/./test_model_zoo/onnx/unit_test.manifest") at /content/openvino/src/frontends/tests/frontend/shared/src/main.cpp:16
#66 0x0000555555f9557f in main (argc=29, argv=0x7fffffffdfb8) at /content/openvino/src/frontends/tests/frontend/shared/gtest_main_manifest/main.cpp:21
```
