cmake_minimum_required(VERSION 3.23)

set(project "lab4")
project(${project})

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(MyStack)

set(SOURCES
    main.cpp
)

add_executable(${project} ${SOURCES})

target_link_libraries(${project} MyStack)


target_include_directories(
    ${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/MyStack
)