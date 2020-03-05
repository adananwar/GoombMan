#include "Kebab.h"
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

    Kebab::Kebab(int x, int y, int w, int h) :Component(x, y, w, h)
    {
        kebabIcon = IMG_LoadTexture(sys.get_ren(), "kebab.png");
    }

    Kebab::~Kebab()
    {
        SDL_DestroyTexture(kebabIcon);
    }

    Kebab* Kebab::getInstance(int x, int y, int w, int h) {
        return new Kebab(x, y, w, h);
    }

    void Kebab::keyDown(const SDL_Event& event) {
    }
    void Kebab::keyUp(const SDL_Event& event) {
    }
    void Kebab::keyRight(const SDL_Event& event) {
    }
    void Kebab::keyLeft(const SDL_Event& event) {
    }

    void Kebab::handleCollision(std::vector<Component*> comps) {
        for (Component* c : comps) {
            if (SDL_HasIntersection(&rect, &c->getRect()) && rect.x != c->getRect().x) {
                rect.h, rect.w = 0;
            }
        }
    }
    void Kebab::draw() {
        SDL_RenderCopy(sys.get_ren(), kebabIcon, NULL, &getRect());
    }
}
