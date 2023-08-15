# Loop over each library module defined in LIBRARY_MODULES
foreach(LIBRARY_MODULE ${LIBRARY_MODULES})
    # Define the path to the example source file for the current library module
    set(LIBRARY_MODULE_EXAMPLE "${EXAMPLES_DIR}/${LIBRARY_MODULE}_example.cpp")
    
    # If the example source file does not exist, skip to the next module
    if (NOT EXISTS ${LIBRARY_MODULE_EXAMPLE})
        continue()
    endif()

    # Replace '/' with '-' to create a valid executable name
    string(REPLACE "/" "-" LIBRARY_MODULE_EXAMPLE_EXE_NAME "${LIBRARY_MODULE}_example")

    # Create an executable for the example using the source file
    add_executable(${LIBRARY_MODULE_EXAMPLE_EXE_NAME} ${LIBRARY_MODULE_EXAMPLE})
    
    # Link the example executable with the main library
    target_link_libraries(${LIBRARY_MODULE_EXAMPLE_EXE_NAME} PUBLIC
        that_dsp_lib
    )
    
    # Print a message indicating the creation of the example
    message(STATUS "Creating Example: ${LIBRARY_MODULE_EXAMPLE_EXE_NAME}")
endforeach()
