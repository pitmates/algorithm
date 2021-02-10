cmake_minimum_required(VERSION 3.15)
project(string)

set(CMAKE_CXX_STANDARD 14)

#include_directories(
#    ${PROJECT_SOURCE_DIR}/graph
#    ${PROJECT_SOURCE_DIR}/string
#)

set(PROJECT_SOURCE_DIR kmp)
#add_subdirectory(string)

file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

foreach (FILENAME ${SOURCE_FILES})
    get_filename_component(EXENAME ${FILENAME} NAME_WE)
    add_executable(${EXENAME} ${FILENAME} )
endforeach ()

add_definitions(-DPIT)


