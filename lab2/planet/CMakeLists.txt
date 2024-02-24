cmake_minimum_required(VERSION 3.23)

set(project "planet")
project(${project})

set(CMAKE_CXX_STANDARD 17)
set(SOURCES
    planet.cpp
)

set(HEADERS
    planet.h
)


add_library(${project} STATIC ${SOURCES} ${HEADERS})