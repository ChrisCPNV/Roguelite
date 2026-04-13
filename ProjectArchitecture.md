# Roguelite Project Architecture

This document provides a comprehensive overview of the Roguelite project, explaining how each component interacts and their individual responsibilities.

## Project Overview

Roguelite is a minimal C++ application built with SDL3 for graphics rendering and CMake for build management. It demonstrates basic UI interaction with mouse and keyboard input handling.

## Build System

### CMakeLists.txt

- **Purpose**: Defines the build configuration for the project
- **Key Features**:
  - Sets C++17 standard
  - Configures SDL3 library integration
  - Defines executable target with source files
  - Links SDL3 libraries for Windows GUI application
- **Interactions**:
  - Compiles `src/main.cpp` and `src/Button.cpp` into the `roguelite` executable
  - Includes SDL3 headers and links the SDL3 DLL import library

### build/ Directory

- **Purpose**: Contains generated build artifacts from CMake
- **Contents**: Makefiles, object files, dependency files, and the final executable
- **Interactions**: Created by CMake; contains the compiled `roguelite.exe` and required `SDL3.dll`

## Core Application Files

### src/main.cpp

- **Purpose**: Main entry point and application loop
- **Responsibilities**:
  - Initializes SDL video subsystem
  - Creates the main window and UI manager
  - Runs the main event loop processing user input
  - Handles global events (mouse motion, keyboard input, window events)
  - Coordinates rendering and updating of all UI elements
- **Interactions**:
  - Creates `Window` instance for display management
  - Creates `UI` instance for user interface management
  - Calls `UI::HandleEvent()` for event processing
  - Calls `Window::Render()` and `UI::Render()` for drawing
  - Uses `ErrorHandling.h` for SDL error checking (when enabled)

### src/Window.h

- **Purpose**: Manages the SDL window and basic rendering operations
- **Responsibilities**:
  - Creates and manages the SDL window with specified dimensions (700x700)
  - Provides access to the window's surface for rendering
  - Handles basic background rendering (gray fill)
  - Updates the window surface to display rendered content
- **Interactions**:
  - Used by `main.cpp` to create the application window
  - Provides surface to `UI::Render()` for drawing UI elements
  - Surface is filled with background color before UI rendering

## User Interface System

### src/UI.h

- **Purpose**: Manages the collection of UI elements
- **Responsibilities**:
  - Contains the main rectangular area and four interactive buttons
  - Coordinates event handling across all UI elements
  - Manages rendering of all UI components
  - Provides interface for changing UI element properties
- **Interactions**:
  - Created by `main.cpp` in the main function
  - Receives events from `main.cpp` via `HandleEvent()`
  - Renders to the window surface provided by `Window`
  - Contains one `Rectangle` (main area) and four `Button` instances

### src/Rectangle.h

- **Purpose**: Base class for rectangular UI elements with mouse interaction
- **Responsibilities**:
  - Defines rectangular bounds and visual appearance
  - Handles mouse events (enter, exit, click)
  - Manages hover states and color changes
  - Provides rendering functionality for filled rectangles
- **Interactions**:
  - Base class for `Button` (inheritance)
  - Used directly as the main UI area in `UI`
  - Processes mouse events from `UI::HandleEvent()`
  - Renders to SDL surface provided by `Window`

### src/Button.h & src/Button.cpp

- **Purpose**: Interactive button UI element
- **Responsibilities**:
  - Inherits from `Rectangle` for basic shape and mouse handling
  - Implements click behavior to change target rectangle color
  - Maintains reference to target UI element and UI manager
- **Interactions**:
  - Created by `UI` with specific positions and target reference
  - When clicked, changes the color of the main rectangle (target)
  - Uses `Rectangle`'s mouse event handling for click detection

## Utility Files

### src/ErrorHandling.h

- **Purpose**: Provides SDL error checking utilities
- **Responsibilities**:
  - Defines `CheckSDLError()` function for error reporting
  - Conditionally enabled via `ERROR_LOGGING` macro
  - Clears SDL error state after reporting
- **Interactions**:
  - Used by `main.cpp` after window creation (when logging enabled)
  - Helps with debugging SDL-related issues

### src/test.cpp

- **Purpose**: Contains unrelated SDL example code
- **Status**: Currently commented out in CMakeLists.txt
- **Interactions**: Not compiled or used in the current build

## Data Flow and Event Handling

1. **Initialization**:
   - `main.cpp` initializes SDL and creates `Window` and `UI` instances
   - `UI` creates one main `Rectangle` and four `Button` objects

2. **Event Processing**:
   - SDL events are polled in `main.cpp`'s event loop
   - Global events (mouse motion, keyboard) are handled directly in `main.cpp`
   - UI-specific events are passed to `UI::HandleEvent()`
   - `UI` distributes events to all its `Rectangle` and `Button` components
   - `Rectangle`/`Button` objects process mouse events and update their state

3. **Rendering**:
   - `Window::Render()` fills the background with gray
   - `UI::Render()` calls render on all UI elements
   - Each `Rectangle`/`Button` draws its colored rectangle on the window surface
   - `Window::Update()` displays the final rendered surface

4. **Interaction Flow**:
   - User moves mouse → `Rectangle` detects hover and changes color
   - User clicks button → `Button::OnLeftClick()` changes main rectangle color
   - User presses keys → `main.cpp` handles movement input

## Dependencies

- **SDL3**: Handles window creation, rendering, and input events
- **C++17**: Language standard for modern C++ features
- **CMake 3.20+**: Build system generation
- **MinGW-w64**: Windows C++ compiler toolchain

## Build and Run Process

1. CMake generates build files from `CMakeLists.txt`
2. Compiler builds source files into executable
3. SDL3.dll must be copied to build directory
4. Executable runs the main loop, processing events and rendering UI

This architecture provides a clean separation between window management, UI components, and event handling, making it easy to extend with additional UI elements or game logic.
