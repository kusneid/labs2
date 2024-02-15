cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 20)

set(project1 "hurrayscreaming")
project(${project1})

set(SOURCES 
    hurray.cpp
)

set(HEADERS
    hurray.h
)

add_library(${project1} STATIC ${SOURCES} ${HEADERS})