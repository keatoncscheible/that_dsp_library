cmake_minimum_required(VERSION 3.25.0)

#########
# GTest #
#########
add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

foreach(LIBRARY_MODULE ${LIBRARY_MODULES})
    string(REPLACE "/" "_" TEST_NAME ${LIBRARY_MODULE})
    # Create a test executable for each test
    add_executable(${TEST_NAME} ${LIBRARY_MODULE}_test.cpp)

    # Link the test executable with GTest and your main library
    target_link_libraries(${TEST_NAME} PUBLIC
        gtest_main
        that_dsp_lib
    )

    # Add the test to CTest
    message(STATUS "Adding test: ${TEST_NAME}")
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    set_tests_properties(${TEST_NAME} PROPERTIES
        ENVIRONMENT GTEST_COLOR=1)
endforeach()