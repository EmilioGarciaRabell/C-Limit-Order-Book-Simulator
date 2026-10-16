cmake_minimum_required(VERSION 3.20)

project(OrderBookProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test
    src/main.cpp
    src/OrderBook.cpp
    src/CLI.cpp
    src/Exchange.cpp
)

target_include_directories(test PRIVATE include)