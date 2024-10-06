cmake_minimum_required(VERSION 3.14)
project(sample_cpp_project)

include_directories(include)

add_executable(main main.cpp src/my_add.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(tests test_add.cpp src/my_add.cpp)
target_link_libraries(tests gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)


FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.9.0
)

FetchContent_MakeAvailable(googlebenchmark)
add_executable(benchmark_add benchmark.cpp src/my_add.cpp)
target_link_libraries(benchmark_add benchmark::benchmark)

find_package(Doxygen)

if(DOXYGEN_FOUND)
  set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)

  file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doxygen)

  add_custom_target(doc
                    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    COMMENT "Generating API documentation with Doxygen"
                    VERBATIM)

else(DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the documentation")
endif(DOXYGEN_FOUND)