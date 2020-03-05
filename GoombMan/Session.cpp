#include "Session.h"
#include "System.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#include <iostream>
#endif
namespace GoombMan {

    void Session::add(Component* c) {
        comps.push_back(c);
    }

    void Session::addWall(Rectangle* r) {
        walls.push_back(r);
    }

    void Session::addFood(Kebab* k) {
        food.push_back(k);
    }

    void Session::run() {


        bool quit = false;
        while (!quit) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        for (Component* c : comps) {
                            c->keyUp(event);
                            c->handleCollision(comps);
                        }
                        break;
                    case SDLK_DOWN:
                        for (Component* c : comps) {
                            c->keyDown(event);
                            c->handleCollision(comps);
                        }
                        break;
                    case SDLK_LEFT:
                        for (Component* c : comps) {
                            c->keyLeft(event);
                            c->handleCollision(comps);
                        }
                        break;
                    case SDLK_RIGHT:
                        for (Component* c : comps) {
                            c->keyRight(event);
                            c->handleCollision(comps);
                        }
                        break;

                    }
                } // switch
            } // inre while

            SDL_RenderClear(sys.get_ren());
            for (Rectangle* r : walls)
                r->draw();
            for (Component* c : comps)
                c->draw();
            SDL_RenderPresent(sys.get_ren());

        } //yttre while

    }

    Session::~Session()
    {
        for (Component* c : comps)
            delete c;
    }
}
