#include "Rectangle.h"
#include "System.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#else
#include <SDL.h>
#include <iostream>
#include <SDL_ttf.h>
#include <SDL_image.h>
#endif

namespace GoombMan {

    Rectangle::Rectangle(int x, int y, int w, int h) :Component(x, y, w, h) {

        rectIcon = IMG_LoadTexture(sys.get_ren(), "wall.jpg");
    }

    Rectangle::~Rectangle() {
        SDL_DestroyTexture(rectIcon);
    }

    Rectangle* Rectangle::getInstance(int x, int y, int w, int h) {
        return new Rectangle(x, y, w, h);
    }

    void Rectangle::keyDown(const SDL_Event& event) {
    }
    void Rectangle::keyUp(const SDL_Event& event) {
    }
    void Rectangle::keyRight(const SDL_Event& event) {
    }
    void Rectangle::keyLeft(const SDL_Event& event) {
    }

    void Rectangle::draw() {
        SDL_RenderCopy(sys.get_ren(), rectIcon, NULL, &getRect());
    }

}
