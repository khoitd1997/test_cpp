file(GLOB CppSources *.cpp)
add_library(test_mod_2 ${CppSources})
target_include_directories(test_mod_2
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB CppTestSources test/*.cpp)
add_library(test_mod_2_test ${CppTestSources})
# target_link_libraries(test_mod_2_test Catch2::Catch2)
include(Catch)
catch_discover_tests(test_mod_2_test EXTRA_ARGS --use-colour yes)
