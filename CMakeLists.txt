cmake_minimum_required(VERSION 3.14)
project(video-app1 C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glfw)
add_subdirectory(lib/FFmpeg)

add_definitions(-DGL_SILENCE_DEPRECATION)

list(APPEND SOURCES
    src/main.cpp
    src/load_frame.cpp
)

list ( APPEND EXTRA_LIBS "-lavformat -lavcodec -lswscale -lavutil -lz -lGL -lGLU -lX11" )

add_executable(video-app1 ${SOURCES})
target_link_libraries(video-app1 FFmpeg glfw ${EXTRA_LIBS})