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
├─ src/
│  ├─ main.cpp
│  ├─ Button.cpp
│  ├─ ErrorHandling.h
│  ├─ Rectangle.h
│  ├─ Button.h
│  ├─ UI.h
│  └─ Window.h
├─ build/          # created later by CMake
├─ CMakeLists.txt
├─ README.md       # this file
├─ SDLQuickReference.md       # Only for dev
└─ .gitignore
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
cp C:/SDL3/x86_64-w64-mingw32/bin/SDL3.dll .
```

This README provides all steps to **initialize, build, and run your SDL3 roguelite project** on Windows using MinGW.
