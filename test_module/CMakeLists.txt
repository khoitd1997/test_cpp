file(GLOB CppSources *.cpp)
add_library(test_module ${CppSources})
target_include_directories(test_module
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(test_bin ${CMAKE_CURRENT_SOURCE_DIR}/test/test.cpp)

find_package(Catch2 REQUIRED)
target_link_libraries(test_bin Catch2::Catch2)

# enable_testing() add_test(NAME test_module_testl COMMAND test_bin)
include(CTest)
include(Catch)
catch_discover_tests(test_bin
                     EXTRA_ARGS
                     --use-colour
                     yes)
