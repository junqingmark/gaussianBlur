cmake_minimum_required(VERSION 2.6)

project(gaussBlur)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(SRCS 
    main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} glfw GLEW GL freeimage)
