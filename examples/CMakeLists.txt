foreach(LIBRARY_MODULE ${LIBRARY_MODULES})
    set(LIBRARY_MODULE_EXAMPLE "${EXAMPLES_DIR}/${LIBRARY_MODULE}_example.cpp")
    if (NOT EXISTS ${LIBRARY_MODULE_EXAMPLE})
        continue()
    endif()

    string(REPLACE "/" "-" LIBRARY_MODULE_EXAMPLE_EXE_NAME "${LIBRARY_MODULE}_example")

    add_executable(${LIBRARY_MODULE_EXAMPLE_EXE_NAME} ${LIBRARY_MODULE_EXAMPLE})
    target_link_libraries(${LIBRARY_MODULE_EXAMPLE_EXE_NAME} PUBLIC
        that_dsp_lib
    )
    message(STATUS "Creating Example: ${LIBRARY_MODULE_EXAMPLE_EXE_NAME}")

endforeach()