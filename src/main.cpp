#include <SDL3/SDL.h>
#include <iostream>
#include <string>
#include "Window.h"
#include "ErrorHandling.h"
#include "Rectangle.h"

void HandleMotionEvent(
  SDL_MouseMotionEvent& Event,
  Window& GameWindow
) {
  std::cout << "Mouse Motion Detected - "
    << "x: " << Event.x
    << ", y: " << Event.y;

  std::cout << "\n  Distance from Right: "
    << (float)GameWindow.GetWidth() - Event.x;

  std::cout << "\n  Distance from Bottom: "
    << (float)GameWindow.GetHeight() - Event.y << '\n';
}

// Handle mouse button events
void HandleButtonEvent(SDL_MouseButtonEvent& Event) {
  if (Event.button == SDL_BUTTON_RIGHT) {
    std::cout << "Right Click or Release\n";
  }

  if (Event.button == SDL_BUTTON_LEFT &&
      Event.down &&
      Event.clicks >= 2
  ) {
    std::cout << "Left Double Click\n";
  }
}

// Handle movement events
void HandleMovement(SDL_KeyboardEvent& Event) {
    const bool *key_states = SDL_GetKeyboardState(nullptr);
    int directionX = 0;
    int directionY = 0;

    if (key_states[SDL_SCANCODE_W]) {
        directionY -= 1;
    }
    if (key_states[SDL_SCANCODE_S]) {
        directionY += 1;
    }
    if (key_states[SDL_SCANCODE_A]) {
        directionX -= 1;
    }
    if (key_states[SDL_SCANCODE_D]) {
        directionX += 1;
    }
    std::cout << "Movement Direction - X: "
        << directionX << ", Y: " << directionY << '\n';
}

int main(int , char** ) {
    std::cout << "Program started\n";
    std::cout.flush();

    SDL_Init(SDL_INIT_VIDEO);
    std::string GameName{"Roguelite"};
    Window GameWindow(GameName.c_str());
    Rectangle Rect{SDL_Rect{50,50,50,50}};

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
            Rect.HandleEvent(event); 

            if (event.type == SDL_EVENT_MOUSE_MOTION) {
              HandleMotionEvent(event.motion, GameWindow);
            } else if (event.type == SDL_EVENT_WINDOW_MOUSE_ENTER) {
              std::cout << "Mouse Entered Window\n";
            } else if (event.type == SDL_EVENT_WINDOW_MOUSE_LEAVE) {
              std::cout << "Mouse Left Window\n";
            } else if (
              event.type == SDL_EVENT_MOUSE_BUTTON_DOWN ||
              event.type == SDL_EVENT_MOUSE_BUTTON_UP
            ) {
              HandleButtonEvent(event.button);
            } else if (
                event.type == SDL_EVENT_KEY_DOWN || 
                event.type == SDL_EVENT_KEY_UP
                ) {
              HandleMovement(event.key);

            } else if (event.type == SDL_EVENT_QUIT) {
              isRunning = false;
            }
        }

        GameWindow.Render(); // Render background

        // Render other game elements here
        Rect.Render(GameWindow.GetSurface());

        GameWindow.Update(); // Swap buffers / update window
    }

    SDL_Quit();
    return 0;
}
