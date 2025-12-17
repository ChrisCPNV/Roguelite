cmake_minimum_required(VERSION 3.20)
project(Roguelite LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to SDL3 development folder
set(SDL3_PATH "C:/SDL3/x86_64-w64-mingw32")

# Include SDL3 headers
include_directories("${SDL3_PATH}/include")

# Add your executable
add_executable(roguelite src/main.cpp)

# Link SDL3 DLL import library only
target_link_libraries(roguelite
    "${SDL3_PATH}/lib/libSDL3.dll.a"
)

# Tell MinGW to build a Windows GUI app (no console)
target_link_options(roguelite PRIVATE -mwindows)
