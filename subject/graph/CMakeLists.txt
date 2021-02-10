cmake_minimum_required(VERSION 3.15)
project(graph)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_SOURCE_DIR tarjan)

file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

foreach (FILENAME ${SOURCE_FILES})
    get_filename_component(EXENAME ${FILENAME} NAME_WE)
    add_executable(${EXENAME} ${FILENAME} )
endforeach ()

add_definitions(-DPIT)


