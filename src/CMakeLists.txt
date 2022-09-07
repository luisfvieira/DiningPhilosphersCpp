cmake_minimum_required(VERSION 3.10)
project(philosophers)

set(CMAKE_CXX_STANDARD 20)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(philosophers PRIVATE Threads::Threads)

add_executable(philosophers, philosophers.cpp)