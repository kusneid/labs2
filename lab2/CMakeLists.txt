cmake_minimum_required(VERSION 3.23)

set(project "lab2")
project(${project})

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(planet)

set(SOURCES
    main.cpp
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(${project} ${SOURCES})

target_link_libraries(${project} planet)
target_link_libraries(${project} )

target_include_directories(
    ${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/planet
)