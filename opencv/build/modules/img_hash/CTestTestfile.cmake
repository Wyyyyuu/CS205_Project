# CMake generated Testfile for 
# Source directory: /mnt/d/资料/C++/opencv/opencv_contrib/modules/img_hash
# Build directory: /mnt/d/资料/C++/opencv/build/modules/img_hash
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_img_hash "/mnt/d/资料/C++/opencv/build/bin/opencv_test_img_hash" "--gtest_output=xml:opencv_test_img_hash.xml")
set_tests_properties(opencv_test_img_hash PROPERTIES  LABELS "Extra;opencv_img_hash;Accuracy" WORKING_DIRECTORY "/mnt/d/资料/C++/opencv/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/mnt/d/资料/C++/opencv/cmake/OpenCVUtils.cmake;1640;add_test;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1310;ocv_add_test_from_target;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1074;ocv_add_accuracy_tests;/mnt/d/资料/C++/opencv/opencv_contrib/modules/img_hash/CMakeLists.txt;3;ocv_define_module;/mnt/d/资料/C++/opencv/opencv_contrib/modules/img_hash/CMakeLists.txt;0;")
