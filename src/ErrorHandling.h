#pragma once
#include <SDL3/SDL.h>
#include <string>
#include <iostream>

// Uncomment the following line to enable error logging
#define ERROR_LOGGING 

void CheckSDLError(const std::string& Action) {
    #ifdef ERROR_LOGGING
    const char* Error{SDL_GetError()};
    if (*Error != '\0') {
        std::cout << Action << " Error: " << Error << '\n';
        SDL_ClearError();
    }
    #endif
}