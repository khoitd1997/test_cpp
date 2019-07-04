cmake_minimum_required(VERSION 3.10)
project(Test_cpp LANGUAGES CXX)

# find_package(Catch2 REQUIRED) enable_testing() find_package(GTest REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall
                    -Wextra
                    -Wnon-virtual-dtor
                    -Wold-style-cast
                    -Woverloaded-virtual
                    -Wsign-conversion
                    -Wconversion
                    -Wduplicated-cond
                    -Wduplicated-branches
                    -Wlogical-op
                    -Wnull-dereference
                    -Wuseless-cast
                    -Wformat=2
                    -Wdouble-promotion
                    -fasynchronous-unwind-tables
                    -fstack-protector
                    -fstack-protector-strong
                    -fPIC
                    -shared
                    -pipe
                    # -DCATCH_CONFIG_COLOUR_ANSI
                    -fsanitize=address
                    -fsanitize=undefined
                    -g
                    -fdiagnostics-color=always)
add_link_options(-fsanitize=address -fsanitize=undefined)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
  # Update submodules as needed
  option(GIT_SUBMODULE "Check submodules during build" ON)
  if(GIT_SUBMODULE)
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update
                            --init
                            --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(
        FATAL_ERROR
          "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules"
        )
    endif()
  endif()
endif()

add_executable(test_cpp ${PROJECT_SOURCES} main.cpp)
# target_link_libraries(test_cpp PRIVATE test_module)

# add_subdirectory(test_module) add_subdirectory(test_mod_2)

# add_executable(unit_test_cpp ${PROJECT_SOURCES} test_main.cpp)
# target_link_libraries(unit_test_cpp # test_mod_2_test Catch2::Catch2
# test_module_test) include(CTest) include(Catch)
# catch_discover_tests(unit_test_cpp EXTRA_ARGS --use-colour yes)
