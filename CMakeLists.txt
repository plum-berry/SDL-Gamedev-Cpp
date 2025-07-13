cmake_minimum_required(VERSION 3.10)
project(Gametest)

set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SDL2/include")
set(SDL2_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/SDL2/lib")

include_directories(${SDL2_INCLUDE_DIR}) 
link_directories(${SDL2_LIBRARY_DIR})

add_executable(SDLApp main.cpp Game.cpp)

target_link_libraries(SDLApp mingw32 SDL2main SDL2 SDL2_image)
