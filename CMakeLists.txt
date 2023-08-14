cmake_minimum_required(VERSION 3.25.0)

set(LIBRARY_NAME "that_dsp_lib")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/test")
set(EXAMPLES_DIR "${CMAKE_SOURCE_DIR}/examples")
set(LIBRARY_MODULES 
    "signal"
    "arithmetic/mac"
    "arithmetic/square"
)

project(
    ${LIBRARY_NAME} 
    VERSION 1.0
    LANGUAGES C CXX
)
enable_testing()

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

###########
# Project #
###########
add_subdirectory(lib/matplotplusplus)

# Initialize empty lists for sources and headers
set(SOURCES "")
set(HEADERS "")

# Create source file and header file lists from the library
foreach(LIBRARY_MODULE ${LIBRARY_MODULES})

    # Add source if it exists
    set(LIBRARY_MODULE_SOURCE "${SOURCE_DIR}/${LIBRARY_MODULE}.cpp")
    if (EXISTS ${LIBRARY_MODULE_SOURCE})
        list(APPEND SOURCES ${LIBRARY_MODULE_SOURCE})
    endif()

    # Add header if it exists
    set(LIBRARY_MODULE_HEADER "${INCLUDE_DIR}/${LIBRARY_MODULE}.h")
    if (EXISTS ${LIBRARY_MODULE_HEADER})
        list(APPEND HEADERS ${LIBRARY_MODULE_HEADER})
    endif()
endforeach()

message(STATUS "SOURCES: ${SOURCES}")
foreach(SOURCE ${SOURCES})
    message(STATUS "    ${SOURCE}")
endforeach()

message(STATUS "HEADERS: ${HEADERS}")
foreach(HEADER ${HEADERS})
    message(STATUS "    ${HEADER}")
endforeach()

add_library(${LIBRARY_NAME} STATIC ${SOURCES})
target_include_directories(${LIBRARY_NAME} PUBLIC ${INCLUDE_DIR})
target_link_libraries(${LIBRARY_NAME} PUBLIC matplot)

add_subdirectory(${TEST_DIR})
add_subdirectory(${EXAMPLES_DIR})
