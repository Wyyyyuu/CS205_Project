# CMake generated Testfile for 
# Source directory: /mnt/d/资料/C++/opencv/opencv_contrib/modules/stereo
# Build directory: /mnt/d/资料/C++/opencv/build/modules/stereo
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_stereo "/mnt/d/资料/C++/opencv/build/bin/opencv_test_stereo" "--gtest_output=xml:opencv_test_stereo.xml")
set_tests_properties(opencv_test_stereo PROPERTIES  LABELS "Extra;opencv_stereo;Accuracy" WORKING_DIRECTORY "/mnt/d/资料/C++/opencv/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/mnt/d/资料/C++/opencv/cmake/OpenCVUtils.cmake;1640;add_test;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1310;ocv_add_test_from_target;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1074;ocv_add_accuracy_tests;/mnt/d/资料/C++/opencv/opencv_contrib/modules/stereo/CMakeLists.txt;2;ocv_define_module;/mnt/d/资料/C++/opencv/opencv_contrib/modules/stereo/CMakeLists.txt;0;")
add_test(opencv_perf_stereo "/mnt/d/资料/C++/opencv/build/bin/opencv_perf_stereo" "--gtest_output=xml:opencv_perf_stereo.xml")
set_tests_properties(opencv_perf_stereo PROPERTIES  LABELS "Extra;opencv_stereo;Performance" WORKING_DIRECTORY "/mnt/d/资料/C++/opencv/build/test-reports/performance" _BACKTRACE_TRIPLES "/mnt/d/资料/C++/opencv/cmake/OpenCVUtils.cmake;1640;add_test;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1212;ocv_add_test_from_target;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1075;ocv_add_perf_tests;/mnt/d/资料/C++/opencv/opencv_contrib/modules/stereo/CMakeLists.txt;2;ocv_define_module;/mnt/d/资料/C++/opencv/opencv_contrib/modules/stereo/CMakeLists.txt;0;")
add_test(opencv_sanity_stereo "/mnt/d/资料/C++/opencv/build/bin/opencv_perf_stereo" "--gtest_output=xml:opencv_perf_stereo.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_stereo PROPERTIES  LABELS "Extra;opencv_stereo;Sanity" WORKING_DIRECTORY "/mnt/d/资料/C++/opencv/build/test-reports/sanity" _BACKTRACE_TRIPLES "/mnt/d/资料/C++/opencv/cmake/OpenCVUtils.cmake;1640;add_test;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1213;ocv_add_test_from_target;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1075;ocv_add_perf_tests;/mnt/d/资料/C++/opencv/opencv_contrib/modules/stereo/CMakeLists.txt;2;ocv_define_module;/mnt/d/资料/C++/opencv/opencv_contrib/modules/stereo/CMakeLists.txt;0;")
