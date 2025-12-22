#include <SDL3/SDL.h>
#include <iostream>
#include <string>
#include "Window.h"
#include "ErrorHandling.h"

void HandleEvent(SDL_Event& E) {
    if (E.type == SDL_EVENT_QUIT) {
        std::cout << "Quit event received.\n";
    } else if (E.type == SDL_EVENT_KEY_DOWN) {
        std::cout << "Key down pressed" << '\n';
    } else if (E.type == SDL_EVENT_MOUSE_MOTION) {
        std::cout << "Mouse moved" << '\n';
    }
}

int main(int , char** ) {
    std::cout << "Program started\n";
    std::cout.flush();
    
    SDL_Init(SDL_INIT_VIDEO);
    std::string GameName{"Roguelite"};
    Window GameWindow(GameName.c_str());

    // Check for SDL errors after creating the window
    #ifdef ERROR_LOGGING
    CheckSDLError("Creating Window");
    #endif

    bool isRunning = true;
    SDL_Event event; // Event variable to hold events

    while (isRunning) {
        // Pump events to update the event queue
        SDL_PumpEvents();

        while (SDL_PollEvent(&event)) {
            HandleEvent(event);
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }
    }

    SDL_Quit();
    return 0;
}
