# Roguelite

A minimal roguelite project using **C++17**, **SDL3**, and **CMake** on Windows with MinGW.

---

## Prerequisites

* **C++ compiler:** MinGW-w64 (`g++` and `mingw32-make` in your PATH)
* **CMake:** version 3.20 or higher
* **SDL3 development files** for MinGW (download from [SDL GitHub Releases](https://github.com/libsdl-org/SDL/releases))

> Example SDL3 installation path: `C:/SDL3/x86_64-w64-mingw32`

---

## Project Structure

```text
Roguelite/
├─ CMakeLists.txt
├─ src/
│  └─ main.cpp
├─ build/          # created later by CMake
├─ README.md       # this file
└─ .gitignore
```

---

## CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.20)
project(Roguelite LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to SDL3
set(SDL3_PATH "C:/SDL3/x86_64-w64-mingw32")

# Include SDL3 headers
include_directories("${SDL3_PATH}/include")

# Add executable
add_executable(roguelite src/main.cpp)

# Link SDL3 DLL import library
target_link_libraries(roguelite
    "${SDL3_PATH}/lib/libSDL3.dll.a"
)
```

---

## Minimal main.cpp

```cpp
#include <SDL3/SDL.h>
#include <iostream>

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window (width, height, flags)
    SDL_Window* window = SDL_CreateWindow(
        "Roguelite",
        640,
        480,
        0 // flags
    );

    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Event loop
    bool running = true;
    SDL_Event event;

    while (running) {
        // Poll all events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;  // Window close requested
            }
        }
        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
```

---

## Build Instructions

1. Open a terminal and navigate to the project folder:

    ```bash
    cd C:/Users/YourName/Dev/C++/Roguelite
    ```

2. Create a `build` folder and navigate into it:

    ```bash
    mkdir build
    cd build
    ```

3. Generate Makefiles with CMake:

    ```bash
    cmake .. -G "MinGW Makefiles"
    ```

4. Build the project:

    ```bash
    mingw32-make
    ```

* After building, `roguelite.exe` will be generated in the `build/` folder.

---

## Prepare SDL3 DLL

Copy `SDL3.dll` from the SDL3 `bin` folder to the `build` folder:

```bash
cp C:/SDL3/x86_64-w64-mingw32/bin/SDL3.dll .
```

---

## Run the Executable

From the `build/` folder:

```bash
./roguelite.exe
```

* The window should open and stay visible until you close it.

---

## Notes

* SDL3 no longer requires `libSDL3main.a`.
* Windows are shown by default; `SDL_WINDOW_SHOWN` is obsolete.
* Use an **event loop** to keep the window open and handle user input.
* If you add new source files or change CMake settings, remove `build/` and rebuild:

```bash
rm -rf build
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```

This README provides all steps to **initialize, build, and run your SDL3 roguelite project** on Windows using MinGW.
