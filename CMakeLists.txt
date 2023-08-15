# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.25.0)

# Set project-specific variables
set(LIBRARY_NAME "that_dsp_lib")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/test")
set(EXAMPLES_DIR "${CMAKE_SOURCE_DIR}/examples")
set(LIBRARY_MODULES 
    "signal"
    "control_signal"
)

# Define the project
project(
    ${LIBRARY_NAME} 
    VERSION 1.0
    LANGUAGES C CXX
)
enable_testing()

# Set C/C++ standard versions
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

###########
# Modules #
###########

# Add the matplotplusplus library as a subdirectory
add_subdirectory(lib/matplotplusplus)

# Initialize empty lists for sources and headers
set(SOURCES "")
set(HEADERS "")

# Iterate over library modules to collect sources and headers
foreach(LIBRARY_MODULE ${LIBRARY_MODULES})

    # Add source file to the list if it exists
    set(LIBRARY_MODULE_SOURCE "${SOURCE_DIR}/${LIBRARY_MODULE}.cpp")
    if (EXISTS ${LIBRARY_MODULE_SOURCE})
        list(APPEND SOURCES ${LIBRARY_MODULE_SOURCE})
    endif()

    # Add header file to the list if it exists
    set(LIBRARY_MODULE_HEADER "${INCLUDE_DIR}/${LIBRARY_MODULE}.h")
    if (EXISTS ${LIBRARY_MODULE_HEADER})
        list(APPEND HEADERS ${LIBRARY_MODULE_HEADER})
    endif()
endforeach()

# Print collected sources and headers for debugging
message(STATUS "SOURCES: ${SOURCES}")
foreach(SOURCE ${SOURCES})
    message(STATUS "    ${SOURCE}")
endforeach()

message(STATUS "HEADERS: ${HEADERS}")
foreach(HEADER ${HEADERS})
    message(STATUS "    ${HEADER}")
endforeach()

# Check if sources exist and configure the target library
list(LENGTH SOURCES SOURCE_COUNT)
if(SOURCE_COUNT EQUAL 0)
    # If no sources exist, create an interface target
    add_library(${LIBRARY_NAME} INTERFACE)
    target_include_directories(${LIBRARY_NAME} INTERFACE include)
    target_link_libraries(${LIBRARY_NAME} INTERFACE matplot)    
else()
    # If sources exist, create a static library target
    add_library(${LIBRARY_NAME} STATIC ${SOURCES})
    target_include_directories(${LIBRARY_NAME} PUBLIC ${INCLUDE_DIR})
    target_link_libraries(${LIBRARY_NAME} PUBLIC matplot)
endif()

# Add subdirectories for tests and examples
add_subdirectory(${TEST_DIR})
add_subdirectory(${EXAMPLES_DIR})
