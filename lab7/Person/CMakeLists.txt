cmake_minimum_required(VERSION 3.23)

set(project "Person")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
  person.cpp
)

set(HEADERS
  person.h
)

add_library(${project} STATIC ${SOURCES} ${HEADERS})