file(GLOB CppSources *.cpp)
add_library(test_module SHARED ${CppSources})
target_include_directories(test_module
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add_library(test_module_test INTERFACE)
# target_include_directories(test_module_test INTERFACE
# ${CMAKE_CURRENT_SOURCE_DIR}/test)

include(GoogleTest)
file(GLOB CppTestSources test/*.cpp)
add_executable(test_module_unit_tests ${CppTestSources})
target_link_libraries(test_module_unit_tests GTest::GTest GTest::Main)
gtest_discover_tests(test_module_unit_tests WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR}/test)
