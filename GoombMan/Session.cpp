#include "Session.h"
#include "Goomba.h"
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

        Goomba* g = new Goomba(200, 200, 50, 50);
        Kebab* k = new Kebab(550, 550, 40, 50);

        add(g);
        add(k);

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
                        }
                        g->handleWallCollision(walls);
                        break;
                    case SDLK_DOWN:
                        for (Component* c : comps) {
                            c->keyDown(event);
                            c->handleCollision(comps);
                        }
                        g->handleWallCollision(walls);
                        break;
                    case SDLK_LEFT:
                        for (Component* c : comps) {
                            c->keyLeft(event);
                            c->handleCollision(comps);
                        }
                        g->handleWallCollision(walls);
                        break;
                    case SDLK_RIGHT:
                        for (Component* c : comps) {
                            c->keyRight(event);
                            c->handleCollision(comps);
                        }
                        g->handleWallCollision(walls);
                        break;

                    }
                } // switch
            } // inre while

            SDL_RenderClear(sys.get_ren());
            for (Component* c : comps)
                c->draw();
            SDL_RenderPresent(sys.get_ren());

        } //yttre while

    }

    Session::~Session()
    {
    }
}
