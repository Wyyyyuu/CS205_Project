# CMake generated Testfile for 
# Source directory: /mnt/d/资料/C++/opencv/modules/imgcodecs
# Build directory: /mnt/d/资料/C++/opencv/build/modules/imgcodecs
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_imgcodecs "/mnt/d/资料/C++/opencv/build/bin/opencv_test_imgcodecs" "--gtest_output=xml:opencv_test_imgcodecs.xml")
set_tests_properties(opencv_test_imgcodecs PROPERTIES  LABELS "Main;opencv_imgcodecs;Accuracy" WORKING_DIRECTORY "/mnt/d/资料/C++/opencv/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/mnt/d/资料/C++/opencv/cmake/OpenCVUtils.cmake;1640;add_test;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1310;ocv_add_test_from_target;/mnt/d/资料/C++/opencv/modules/imgcodecs/CMakeLists.txt;158;ocv_add_accuracy_tests;/mnt/d/资料/C++/opencv/modules/imgcodecs/CMakeLists.txt;0;")
add_test(opencv_perf_imgcodecs "/mnt/d/资料/C++/opencv/build/bin/opencv_perf_imgcodecs" "--gtest_output=xml:opencv_perf_imgcodecs.xml")
set_tests_properties(opencv_perf_imgcodecs PROPERTIES  LABELS "Main;opencv_imgcodecs;Performance" WORKING_DIRECTORY "/mnt/d/资料/C++/opencv/build/test-reports/performance" _BACKTRACE_TRIPLES "/mnt/d/资料/C++/opencv/cmake/OpenCVUtils.cmake;1640;add_test;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1212;ocv_add_test_from_target;/mnt/d/资料/C++/opencv/modules/imgcodecs/CMakeLists.txt;162;ocv_add_perf_tests;/mnt/d/资料/C++/opencv/modules/imgcodecs/CMakeLists.txt;0;")
add_test(opencv_sanity_imgcodecs "/mnt/d/资料/C++/opencv/build/bin/opencv_perf_imgcodecs" "--gtest_output=xml:opencv_perf_imgcodecs.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_imgcodecs PROPERTIES  LABELS "Main;opencv_imgcodecs;Sanity" WORKING_DIRECTORY "/mnt/d/资料/C++/opencv/build/test-reports/sanity" _BACKTRACE_TRIPLES "/mnt/d/资料/C++/opencv/cmake/OpenCVUtils.cmake;1640;add_test;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1213;ocv_add_test_from_target;/mnt/d/资料/C++/opencv/modules/imgcodecs/CMakeLists.txt;162;ocv_add_perf_tests;/mnt/d/资料/C++/opencv/modules/imgcodecs/CMakeLists.txt;0;")
