#pragma once
#include <SDL3/SDL.h>
#include "Rectangle.h"
#include "Button.h"

class UI {
    public:
        void Render(SDL_Surface* Surface) const {
            Main.Render(Surface);
            A.Render(Surface);
            B.Render(Surface);
            C.Render(Surface);
            D.Render(Surface);
        }

        void HandleEvent(SDL_Event& E) {
            Main.HandleEvent(E);
            A.HandleEvent(E);
            B.HandleEvent(E);
            C.HandleEvent(E);
            D.HandleEvent(E);
        }

        void SetRectangleColors(const SDL_Color& Color) {
            Main.SetColor(Color);
        }

    private:
        Rectangle Main{SDL_Rect{50, 50, 600, 400}};
        Button A{*this,SDL_Rect{175, 600, 50, 50}, Main};
        Button B{*this,SDL_Rect{275, 600, 50, 50}, Main};
        Button C{*this,SDL_Rect{375, 600, 50, 50}, Main};
        Button D{*this, SDL_Rect{475, 600, 50, 50}, Main};
};