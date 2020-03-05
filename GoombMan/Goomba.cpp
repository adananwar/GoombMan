#include "Goomba.h"
#include "System.h"
#include "Session.h"
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

    Goomba::Goomba(int x, int y, int w, int h) :Component(x, y, w, h)
    {

        goombaIcon = IMG_LoadTexture(sys.get_ren(), "GoombaOne.png");
        secondIcon = IMG_LoadTexture(sys.get_ren(), "GoombaTwo.png");
    }

    Goomba::~Goomba()
    {
        SDL_DestroyTexture(goombaIcon);
        SDL_DestroyTexture(secondIcon);
    }

    Goomba* Goomba::getInstance(int x, int y, int w, int h) {
        return new Goomba(x, y, w, h);
    }

    void Goomba::keyDown(const SDL_Event& event) {

        if (rect.y + 20 < 600 - rect.h) {
            rect.y += 20;
        }
        else {
            rect.y = 600 - rect.h;
        }
        setIcon();
    }
    void Goomba::keyUp(const SDL_Event& event) {
        if (rect.y - 20 > 0) {
            rect.y -= 20;
        }
        else {
            rect.y = 0;
        }
        setIcon();
    }
    void Goomba::keyRight(const SDL_Event& event) {
        if (rect.x + 20 < 600 - rect.w) {
            rect.x += 20;
        }
        else {
            rect.x = 600 - rect.w;
        }
        setIcon();
    }
    void Goomba::keyLeft(const SDL_Event& event) {
        if (rect.x - 20 > 0) {
            rect.x -= 20;
        }
        else {
            rect.x = 0;
        }
        setIcon();
    }

    void Goomba::handleCollision(std::vector<Component*> comps) {
    }

    void Goomba::handleWallCollision(std::vector<Rectangle*> walls) {
        bool interectsWithWall = false;
        for (Rectangle* w : walls) {
            if (SDL_HasIntersection(&rect, &w->getRect())) {
                if (rect.h - 10 > 0) {
                    rect.h -= 5;
                    rect.w += 5;
                }
                interectsWithWall = true;
            }
            if (!interectsWithWall && rect.h < 50) {
                rect.h += 1;
                rect.w -= 1;
            }
        }
    }


    void Goomba::draw() {
        if (isSecond) {
            SDL_RenderCopy(sys.get_ren(), secondIcon, NULL, &getRect());
        }
        else {
            SDL_RenderCopy(sys.get_ren(), goombaIcon, NULL, &getRect());
        }
    }
    void Goomba::setIcon() {
        if (isSecond) {
            isSecond = false;
        }
        else {
            isSecond = true;
        }
    }
}