cmake_minimum_required(VERSION 3.23)

set(project "MyStack")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    MyStack.cpp
)

set(HEADERS
    MyStack.h
)

add_library(${project} STATIC ${SOURCES} ${HEADERS})