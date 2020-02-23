cmake_minimum_required(VERSION 3.0)
project(video-app1 C CXX)
set (CMAKE CXX STANDARD 14)

add_subdirectory(lib/glfw)
add_subdirectory(lib/FFmpeg)

add_definitions(-DGL_SILENCE_DEPRECATION)

if (APPLE) 
	list (APPEND EXTRA_LIBS "-framework OpenGL")
elseif (WIN32)
	list (APPEND EXTRA_LIBS "-lglu32 -lopengl32")
else () 
	list (APPEND EXTRA_LIBS "-lGL -lGLU -lX11")
endif()

list ( APPEND SOURCES
	src/main.cpp
	src/load_frame.cpp
)

add_executable ( video-app1 ${SOURCES} )
target_link_libraries(video-app1 FFmpeg glfw ${EXTRA_LIBS})