#include <SDL3/SDL.h>
#include "Window.h"

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    Window GameWindow;

    while(true) {
        SDL_PumpEvents();
    }

    SDL_Quit();
    return 0;
}
