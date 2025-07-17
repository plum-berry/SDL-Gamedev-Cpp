cmake_minimum_required(VERSION 3.10)
project(GAMETEST)


set(SDL3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SDL/include")
set(SDL3_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/SDL/lib")

set(SDL_IMAGE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SDL_IMAGE/include")
set(SDL_IMAGE_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/SDL_IMAGE/lib")


include_directories(${SDL3_INCLUDE_DIR})
include_directories(${SDL_IMAGE_INCLUDE_DIR})

link_directories((${SDL3_LIBRARY_DIR}))
link_directories((${SDL_IMAGE_LIBRARY_DIR}))

add_executable(SDLApp main.cpp Game.cpp TextureManager.cpp GameObject.cpp)
target_link_libraries(SDLApp mingw32 SDL3 SDL3_image)