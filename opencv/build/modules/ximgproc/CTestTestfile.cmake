# CMake generated Testfile for 
# Source directory: /mnt/d/资料/C++/opencv/opencv_contrib/modules/ximgproc
# Build directory: /mnt/d/资料/C++/opencv/build/modules/ximgproc
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_ximgproc "/mnt/d/资料/C++/opencv/build/bin/opencv_test_ximgproc" "--gtest_output=xml:opencv_test_ximgproc.xml")
set_tests_properties(opencv_test_ximgproc PROPERTIES  LABELS "Extra;opencv_ximgproc;Accuracy" WORKING_DIRECTORY "/mnt/d/资料/C++/opencv/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/mnt/d/资料/C++/opencv/cmake/OpenCVUtils.cmake;1640;add_test;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1310;ocv_add_test_from_target;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1074;ocv_add_accuracy_tests;/mnt/d/资料/C++/opencv/opencv_contrib/modules/ximgproc/CMakeLists.txt;2;ocv_define_module;/mnt/d/资料/C++/opencv/opencv_contrib/modules/ximgproc/CMakeLists.txt;0;")
add_test(opencv_perf_ximgproc "/mnt/d/资料/C++/opencv/build/bin/opencv_perf_ximgproc" "--gtest_output=xml:opencv_perf_ximgproc.xml")
set_tests_properties(opencv_perf_ximgproc PROPERTIES  LABELS "Extra;opencv_ximgproc;Performance" WORKING_DIRECTORY "/mnt/d/资料/C++/opencv/build/test-reports/performance" _BACKTRACE_TRIPLES "/mnt/d/资料/C++/opencv/cmake/OpenCVUtils.cmake;1640;add_test;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1212;ocv_add_test_from_target;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1075;ocv_add_perf_tests;/mnt/d/资料/C++/opencv/opencv_contrib/modules/ximgproc/CMakeLists.txt;2;ocv_define_module;/mnt/d/资料/C++/opencv/opencv_contrib/modules/ximgproc/CMakeLists.txt;0;")
add_test(opencv_sanity_ximgproc "/mnt/d/资料/C++/opencv/build/bin/opencv_perf_ximgproc" "--gtest_output=xml:opencv_perf_ximgproc.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_ximgproc PROPERTIES  LABELS "Extra;opencv_ximgproc;Sanity" WORKING_DIRECTORY "/mnt/d/资料/C++/opencv/build/test-reports/sanity" _BACKTRACE_TRIPLES "/mnt/d/资料/C++/opencv/cmake/OpenCVUtils.cmake;1640;add_test;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1213;ocv_add_test_from_target;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1075;ocv_add_perf_tests;/mnt/d/资料/C++/opencv/opencv_contrib/modules/ximgproc/CMakeLists.txt;2;ocv_define_module;/mnt/d/资料/C++/opencv/opencv_contrib/modules/ximgproc/CMakeLists.txt;0;")
