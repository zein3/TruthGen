cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# make this more general
file(GLOB_RECURSE TEST_FILES *_test.cpp)
add_executable(tests ${TEST_FILES})
target_link_libraries(tests PUBLIC gtest_main ${PROJECT_NAME}_lib)
#add_executable(scanner_tests scanner_test.cpp)
#target_link_libraries(scanner_tests PUBLIC
    #gtest_main
    #${PROJECT_NAME}_lib
#)

include(GoogleTest)
gtest_discover_tests(tests)
#gtest_discover_tests(scanner_tests)
