cmake_minimum_required(VERSION 3.25.0)

set(LIBRARY_NAME "that_dsp_lib")
set(SOURCE_DIR "src")
set(INCLUDE_DIR "include")
set(TEST_DIR "test")
set(LIBRARY_MODULES 
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
# Initialize empty lists for sources and headers
set(SOURCES "")
set(HEADERS "")
# Fill out source and header list
foreach(LIBRARY_MODULE ${LIBRARY_MODULES})
    list(APPEND SOURCES "src/${LIBRARY_MODULE}.cpp")
    list(APPEND HEADERS "include/${LIBRARY_MODULE}.hpp")
endforeach()

message(STATUS "SOURCES: ${SOURCES}")
message(STATUS "HEADERS: ${HEADERS}")

add_library(${LIBRARY_NAME} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${LIBRARY_NAME} PUBLIC ${INCLUDE_DIR})

add_subdirectory(${TEST_DIR})