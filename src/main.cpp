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
                running = false;  // Close requested
            }
        }

        // Optional: delay to limit CPU usage
        SDL_Delay(16); // ~60 FPS
    }

    // Clean up
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
