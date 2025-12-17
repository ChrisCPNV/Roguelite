#pragma once
#include <SDL3/SDL.h>

class Window {
public:
    Window(){
        SDL_CreateWindow(
            "Hello Window",
            700, 300, 0
        );
    }
};