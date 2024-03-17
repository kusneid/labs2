    cmake_minimum_required(VERSION 3.23)

    set(project "lab3")
    project(${project})

    set(CMAKE_CXX_STANDARD 17)

    set(SOURCES
        main.cpp
    )
    add_subdirectory(fraction)


    add_executable(${project} ${SOURCES})

    target_link_libraries(${project} fraction)

    target_include_directories(
        ${PROJECT_NAME} PUBLIC 
        ${CMAKE_SOURCE_DIR}/fraction
    )