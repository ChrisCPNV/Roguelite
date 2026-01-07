#pragma once
#include <SDL3/SDL.h>
#include "Rectangle.h"

class UI; // Forward declaration

class Button : public Rectangle {
    public:
        Button(
            UI& UIManager, 
            const SDL_Rect& Rect,
            Rectangle& Target
        ) 
        : Rectangle{Rect}, 
        UIManager{UIManager},
        Target{Target} 
        {
            SetColor({255, 165, 0, 255});
        }

        void OnLeftClick() override;

    private:
        Rectangle& Target;
        UI& UIManager;
};