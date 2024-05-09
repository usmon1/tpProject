cmake_minimum_required(VERSION 3.20)
project(tpproject_aliev_usmon)

set(CMAKE_CXX_STANDARD 20)

include_directories(Header)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
configure_file(Dictionary.txt ${CMAKE_CURRENT_BINARY_DIR}/bin/Dictionary.txt COPYONLY)
add_executable(tpproject_aliev_usmon  Dictionary.txt
        FastTyping.cpp
        src/ErrorStatistics.cpp
        src/Speed.cpp
        src/UserRequest.cpp)