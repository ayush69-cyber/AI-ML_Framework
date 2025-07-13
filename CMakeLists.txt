cmake_minimum_required(VERSION 3.10)

project(AI-ML_FRAMEWORK)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    include
)

add_executable(myproject
    src/main.cpp 
    src/matrix.cpp
    src/Network.cpp
    src/vector.cpp
    src/lin_regression.cpp
    src/log_regression.cpp
    src/function.cpp
)