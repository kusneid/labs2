cmake_minimum_required(VERSION 3.23)

set(project "fraction")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    fraction.cpp
)

set(HEADERS
    fraction.h
)

add_library(${project} STATIC ${SOURCES} ${HEADERS})