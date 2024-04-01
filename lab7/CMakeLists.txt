cmake_minimum_required(VERSION 3.23)

set(project "lab7")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
  main.cpp
)

add_subdirectory(Person)

add_executable(${project}
        ${SOURCES})

target_link_libraries(${project} Person)

target_include_directories(${project} PUBLIC 
	${CMAKE_SOURCE_DIR}/Person	
)