#pragma once
#include <SDL3/SDL.h>
#include <iostream>

class Window {
public:
    Window(){
        SDLWindow = SDL_CreateWindow(
            "Hello Window",
            700, 300,
            SDL_WINDOW_RESIZABLE |
            SDL_WINDOW_MINIMIZED
        );
    }

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    ~Window() {
        if (SDLWindow && SDL_WasInit(SDL_INIT_VIDEO)) {
            SDL_DestroyWindow(SDLWindow);
        } else {
            std::cout << "Skipping SDL_DestroyWindow\n";
        }
    }

private:
    SDL_Window* SDLWindow{nullptr};
};