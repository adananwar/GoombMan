#include "Session.h"
#include "System.h"
#include <iostream>
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

namespace GoombMan {

    void Session::add(Component* c) {
        comps.push_back(c);
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
                        for (Component* c : comps)
                            c->keyUp(event);
                        break;
                    case SDLK_DOWN:
                        for (Component* c : comps)
                            c->keyDown(event);
                        break;
                    case SDLK_LEFT:
                        for (Component* c : comps)
                            c->keyLeft(event);
                        break;
                    case SDLK_RIGHT:
                        for (Component* c : comps)
                            c->keyRight(event);
                        break;
                    }
                } // switch
            } // inre while
            //SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);

    

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

