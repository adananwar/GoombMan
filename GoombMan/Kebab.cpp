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
        //SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), { 0,0,0 });
        //texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        //SDL_FreeSurface(surf);

        SDL_Surface* bgSurf = IMG_Load("GoombaTwoThree.png");
        SDL_Texture* bgTxt = SDL_CreateTextureFromSurface(sys.get_ren(), bgSurf);
        SDL_FreeSurface(bgSurf);


        kebabIcon = IMG_LoadTexture(sys.get_ren(), "kebab.png");

        if (NULL == kebabIcon) {
            std::cout << "SDL could not load image! SDL Error: " << SDL_GetError() << std::endl;
        }
    }

    Kebab::~Kebab()
    {
        SDL_DestroyTexture(goombTxt);
        SDL_DestroyTexture(kebabIcon);
        SDL_DestroyTexture(downIcon);
    }

    Kebab* Kebab::getInstance(int x, int y, int w, int h) {
        return new Kebab(x, y, w, h);
    }

    void Kebab::keyDown(const SDL_Event& event) {
    }
    void Kebab::keyUp(const SDL_Event& event) {
    }
    void Kebab::keyRight(const SDL_Event& event) {
        rect.x += 20;
    }
    void Kebab::keyLeft(const SDL_Event& event) {
    }
    void Kebab::draw() {
        //SDL_RenderCopy(sys.get_ren(), bgTxt, NULL, NULL);
        SDL_RenderCopy(sys.get_ren(), kebabIcon, NULL, &getRect());
        //if (isDown)
          //  SDL_RenderCopy(sys.get_ren(), downIcon, NULL, &getRect());
        //else
          //  SDL_RenderCopy(sys.get_ren(), kebabIcon, NULL, &getRect());
    }
}