#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include <string>
#include "Window.h"

int main(int , char** ) {
    SDL_Init(SDL_INIT_VIDEO);
    std::string GameName{"Roguelite"};
    Window GameWindow(GameName.c_str());

    std::string Error{SDL_GetError()};
    if (Error.empty()) {
        std::cout << "There is no error";
    } else {
        std::cout << "Error: " << Error;
    }

    bool isRunning = true;
    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }
    }

    SDL_Quit();
    return 0;
}
