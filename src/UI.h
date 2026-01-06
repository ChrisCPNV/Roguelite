#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "Rectangle.h"
#include <memory>

class UI {
    public:

    UI() {
        int RowCount{5}, ColCount{12};
        Rectangles.reserve(RowCount * ColCount);
        for (int Row{0}; Row < RowCount; ++Row) {
            for (int Col{0}; Col < ColCount; ++Col) {
                bool useGreen {(Row + Col) % 2 == 0};
                Rectangles.emplace_back(SDL_Rect{
                    60* Col, 60* Row, 50, 50
                });
            }
        }
    }

    void Render(SDL_Surface* Surface) const {
        for (auto& Rectangle : Rectangles) {
            Rectangle->Render(Surface);
        }
    }

    void HandleEvent(SDL_Event& E) {
        for (auto& Rectangle : Rectangles) {
            Rectangle->HandleEvent(E);
        }
    }

    private:
        std::vector<std::unique_ptr<Rectangle>> Rectangles;
};