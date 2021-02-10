cmake_minimum_required(VERSION 3.13)
project(google_code_jam)

set(CMAKE_CXX_STANDARD 11)

# set(PROJECT_SOURCE_DIR 2018_kickstart_round_G)
set(PROJECT_SOURCE_DIR code)
set(PROJECT_BINARY_DIR data)

file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

foreach (FILENAME ${SOURCE_FILES})
    get_filename_component(EXENAME ${FILENAME} NAME_WE)
    add_executable(${EXENAME} ${FILENAME})
endforeach ()

add_definitions(-DPIT)
