# REQUIRED: sudo apt install --no-install-recommends libasio-dev
project(NServer)
SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS_DEBUG "-O0") #turn off optimization for debug
cmake_minimum_required(VERSION 3.6)
# TARGET    main
add_executable(${PROJECT_NAME} main.cpp)
include_directories(../include)
# LINK      pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)