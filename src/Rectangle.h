#pragma once
#include <SDL3/SDL.h>
#include <iostream>

class Rectangle {
    public:
        void HandleEvent(SDL_Event& E) {
            if (E.type == SDL_EVENT_MOUSE_MOTION) {
                isPointerHovering = isWithinRect(
                    (int)E.motion.x, (int)E.motion.y
                );
            } else if (E.type == SDL_EVENT_WINDOW_MOUSE_LEAVE) {
                isPointerHovering = false;
            } else if (E.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                if (isPointerHovering && E.button.button == SDL_BUTTON_LEFT) {
                    std::cout << "A left click happened "
                        "somewhere in the rectangle\n";
                }
            }
        }

        Rectangle(const SDL_Rect& Rect)
            : Rect{Rect} {}

        void Render(SDL_Surface* Surface) const {
            auto [r, g, b, a]{
                isPointerHovering ? HoverColor : Color
            };

            const auto* Fmt = SDL_GetPixelFormatDetails( Surface->format);

            SDL_FillSurfaceRect(
                Surface,
                &Rect,
                SDL_MapRGB(
                    Fmt, 
                    nullptr, 
                    r, g, b)
            );
        }

        void SetColor(const SDL_Color& NewColor) {
            Color = NewColor;
        }

        SDL_Color GetColor() const {
            return Color;
        }
    
        void SetHoverColor(const SDL_Color& NewColor) {
            HoverColor = NewColor;
        }

        SDL_Color GetHoverColor() const {
            return HoverColor;
        }

    private:
        SDL_Rect Rect;
        SDL_Color Color{255, 0, 0, 255}; 
        SDL_Color HoverColor{255, 255, 0, 255};
        bool isPointerHovering{false};
        bool isWithinRect(int x, int y) {
            if (x < Rect.x) return false;
            if (x > Rect.x + Rect.w) return false;
            if (y < Rect.y) return false;
            if (y > Rect.y + Rect.h) return false;
            return true;
        }
};