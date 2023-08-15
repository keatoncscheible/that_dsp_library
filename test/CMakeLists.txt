# Include GoogleTest subdirectory
add_subdirectory(lib/googletest)

# Include directories for GoogleTest headers
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Iterate over library modules to create and configure test executables
foreach(LIBRARY_MODULE ${LIBRARY_MODULES})

    # Define the path to the test source file and the name of the test executable
    set(LIBRARY_MODULE_TEST "${TEST_DIR}/${LIBRARY_MODULE}_test.cpp")
    string(REPLACE "/" "-" TEST_EXE_NAME "${LIBRARY_MODULE}_test")
        
    if (EXISTS ${LIBRARY_MODULE_TEST})
        # Create a test executable for each test source file
        add_executable(${TEST_EXE_NAME} ${LIBRARY_MODULE_TEST})

        # Link the test executable with GoogleTest and your main library
        target_link_libraries(${TEST_EXE_NAME} PUBLIC
            gtest_main
            that_dsp_lib
        )

        # Add the test to CTest for test discovery and execution
        # Display a status message indicating the addition of the test
        message(STATUS "Adding test: ${TEST_EXE_NAME}")
        
        # Register the test with a name and specify the command to run the test executable
        add_test(NAME ${TEST_EXE_NAME} COMMAND ${TEST_EXE_NAME})
    else()
        # Display a warning message if the test source file is not found
        message(WARNING "${LIBRARY_MODULE_TEST} not found...")
    endif()
    
endforeach()
