#include "System.h"
#include <iostream>
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
namespace GoombMan {

    System::System() {
        SDL_Init(SDL_INIT_EVERYTHING);
        win = SDL_CreateWindow("GoombMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, 0);
        ren = SDL_CreateRenderer(win, -1, 0);
        windowSurf = SDL_GetWindowSurface(win);

        std::cout << "height: " << windowSurf->h << std::endl;

        TTF_Init();
        font = TTF_OpenFont("Roboto-Regular.ttf", 36);

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);
        SDL_RenderPresent(ren);

    }



    System::~System() {
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }

    SDL_Renderer* System::get_ren() const {
        return ren;
    }

    TTF_Font* System::get_font() const {
        return font;
    }

    SDL_Surface* System::get_windowSurf() const {
        return windowSurf;
    }


    SDL_Texture* System::get_bgTxt() const {
        return bgTxt;
    }
    // What does this one do?

    System sys;
}