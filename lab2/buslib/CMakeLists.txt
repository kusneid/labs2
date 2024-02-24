cmake_minimum_required(VERSION 3.23)

set(project "bus")
project(${project})

set(CMAKE_CXX_STANDARD 17)
set(SOURCES 
    bus.cpp
)

set(HEADERS
    bus.h
)

add_library(${project} STATIC ${SOURCES} ${HEADERS})