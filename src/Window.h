#pragma once
#include <SDL3/SDL.h>

class Window {
public:
    Window(const char* title) {
        SDLWindow = SDL_CreateWindow(
            title,
            800, 300, 0
        );

        const auto* Fmt{SDL_GetPixelFormatDetails(
            GetSurface()->format
        )};

        SDL_FillSurfaceRect(
            GetSurface(),
            nullptr,
            SDL_MapRGB(Fmt, nullptr, 50, 50, 50)
        );

        SDL_UpdateWindowSurface(SDLWindow);
    }

    // Get the SDL_Surface associated with the window
    SDL_Surface* GetSurface() const {
        return SDL_GetWindowSurface(SDLWindow);
    }

    // Delete copy constructor and assignment operator to prevent copying
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    // Destructor to clean up the SDL_Window
    ~Window() {
      if (SDLWindow && SDL_WasInit(SDL_INIT_VIDEO)) {
        SDL_DestroyWindow(SDLWindow);
      }
    }

private:
    SDL_Window* SDLWindow{nullptr};
};