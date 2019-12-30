#include "Button.h"
#include "System.h"
#ifdef APPLE
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#else
#include <SDL.h>
#include <iostream>
#include <SDL_ttf.h>
#include <SDL_image.h>
#endif
namespace GoombMan {

    Button::Button(int x, int y, int w, int h, std::string txt) :Component(x, y, w, h)
    {
        //SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), { 0,0,0 });
        //texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        //SDL_FreeSurface(surf);

        SDL_Surface* goombSurf = IMG_Load("GoombaOne.png");
        SDL_Texture* goombTxt = SDL_CreateTextureFromSurface(sys.get_ren(), goombSurf);
        SDL_FreeSurface(goombSurf);

        kebabIcon = IMG_LoadTexture(sys.get_ren(), "GoombaOne.png");
        SDL_Rect goombRect = { 0, 0, 100, 100 };
        // Down Icon may not be necessary, change to pacman instead?
        //downIcon = IMG_LoadTexture(sys.get_ren(), "GoombaTwoThree.png");
    }

    Button::~Button()
    {
        SDL_DestroyTexture(goombTxt);
        SDL_DestroyTexture(kebabIcon);
        SDL_DestroyTexture(downIcon);
    }

    Button* Button::getInstance(int x, int y, int w, int h, std::string txt) {
        return new Button(x, y, w, h, txt);
    }

    void Button::keyDown(const SDL_Event& event) {
        rect.y += 20;
    }
    void Button::keyUp(const SDL_Event& event) {
        rect.y -= 20;
    }
    void Button::keyRight(const SDL_Event& event) {
        rect.x += 20;
    }
    void Button::keyLeft(const SDL_Event& event) {
        rect.x -= 20;
    }
    void Button::draw() const {
        SDL_RenderCopy(sys.get_ren(), kebabIcon, NULL, &getRect());
        //if (isDown)
          //  SDL_RenderCopy(sys.get_ren(), downIcon, NULL, &getRect());
        //else
          //  SDL_RenderCopy(sys.get_ren(), kebabIcon, NULL, &getRect());

        SDL_RenderCopy(sys.get_ren(), goombTxt, NULL, &goombRect);

    }
}
