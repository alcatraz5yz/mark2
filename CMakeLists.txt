cmake_minimum_required(VERSION 3.14)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# For Qt
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# For gcov
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# For gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# For Doxygen
find_package(Doxygen)

# Check if Doxygen is installed
if(DOXYGEN_FOUND)
  set(DOXYGEN_IN Doxyfile)
  set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
  configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
  add_custom_target(docs
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
      COMMAND open html/index.html || echo "Generated at html/index.html"
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      COMMENT "Generating documentation with Doxygen"
      VERBATIM)
endif()

add_executable(MyProject src/main.cpp)

target_link_libraries(MyProject PRIVATE Qt6::Widgets)

add_executable(tests test/test_main.cpp)

target_link_libraries(tests PRIVATE Qt6::Widgets ${GTEST_BOTH_LIBRARIES} pthread)

enable_testing()
add_test(NAME tests COMMAND tests)

add_custom_target(runtests COMMAND ctest --verbose)

set(COV_DIR "out")

add_custom_target(gcov
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/${COV_DIR}
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR} lcov --capture --directory . --output-file ${COV_DIR}/coverage.info --rc lcov_branch_coverage=1 --ignore-errors graph,gcov,inconsistent,unused
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR} lcov --remove ${COV_DIR}/coverage.info '*/tests/*' '/usr/*' '*/MyProject_autogen/*' '*/gtest/*' --output-file ${COV_DIR}/filtered_coverage.info --ignore-errors inconsistent,unused
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR} genhtml ${COV_DIR}/filtered_coverage.info --output-directory ${COV_DIR} --rc genhtml_branch_coverage=1 --ignore-errors inconsistent
    COMMAND open ${CMAKE_BINARY_DIR}/${COV_DIR}/index.html || echo "Generated Coverage at ${CMAKE_BINARY_DIR}/${COV_DIR}/index.html"
    DEPENDS tests
)
