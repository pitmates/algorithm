cmake_minimum_required(VERSION 3.17)
project(codeforces)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_SOURCE_DIR code)

file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

foreach (FILENAME ${SOURCE_FILES})
    get_filename_component(EXENAME ${FILENAME} NAME_WE)
    add_executable(${EXENAME} ${FILENAME} )
endforeach ()

add_definitions(-DPIT)


