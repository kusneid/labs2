cmake_minimum_required(VERSION 3.23)

set(project "lab8")
project(${project})

set(CMAKE_CXX_STANDARD 17)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/text.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/1.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/2.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
set(SOURCES
    main.cpp
)

set(HEADER
  header.h
)

add_executable(${project} ${SOURCES} ${HEADER})