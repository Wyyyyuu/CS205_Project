# CMake generated Testfile for 
# Source directory: /mnt/d/资料/C++/opencv/modules/highgui
# Build directory: /mnt/d/资料/C++/opencv/build/modules/highgui
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_highgui "/mnt/d/资料/C++/opencv/build/bin/opencv_test_highgui" "--gtest_output=xml:opencv_test_highgui.xml")
set_tests_properties(opencv_test_highgui PROPERTIES  LABELS "Main;opencv_highgui;Accuracy" WORKING_DIRECTORY "/mnt/d/资料/C++/opencv/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/mnt/d/资料/C++/opencv/cmake/OpenCVUtils.cmake;1640;add_test;/mnt/d/资料/C++/opencv/cmake/OpenCVModule.cmake;1310;ocv_add_test_from_target;/mnt/d/资料/C++/opencv/modules/highgui/CMakeLists.txt;165;ocv_add_accuracy_tests;/mnt/d/资料/C++/opencv/modules/highgui/CMakeLists.txt;0;")
