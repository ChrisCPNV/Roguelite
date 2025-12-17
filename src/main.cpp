#include <windows.h>    // Required for WinMain, HINSTANCE, LPSTR
#include <SDL3/SDL.h>

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd
) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return 1;

    SDL_Window* win = SDL_CreateWindow(
        "Hello Window",
        700, 300, 0
    );

    bool running = true;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = false;
        }
        SDL_Delay(16);
    }

    SDL_Quit();
    return 0;
}
