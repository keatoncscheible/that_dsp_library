cmake_minimum_required(VERSION 3.25.0)

#########
# GTest #
#########
add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

foreach(LIBRARY_MODULE ${LIBRARY_MODULES})

    # No need to generate a test if there is no source file for the module
    set(LIBRARY_MODULE_SOURCE "${SOURCE_DIR}/${LIBRARY_MODULE}.cpp")
    if (NOT EXISTS ${LIBRARY_MODULE_SOURCE})
        continue()
    endif()

    set(LIBRARY_MODULE_TEST "${TEST_DIR}/${LIBRARY_MODULE}_test.cpp")
    string(REPLACE "/" "-" TEST_EXE_NAME ${LIBRARY_MODULE})
        
    if (EXISTS ${LIBRARY_MODULE_TEST})
       # Create a test executable for each test
        add_executable(${TEST_EXE_NAME} ${LIBRARY_MODULE_TEST})

        # Link the test executable with GTest and your main library
        target_link_libraries(${TEST_EXE_NAME} PUBLIC
            gtest_main
            that_dsp_lib
        )

        # Add the test to CTest
        message(STATUS "Adding test: ${TEST_EXE_NAME}")
        add_test(NAME ${TEST_EXE_NAME} COMMAND ${TEST_EXE_NAME})
    else()
        message(WARNING "${LIBRARY_MODULE_TEST} not found...")
    endif()
    
endforeach()