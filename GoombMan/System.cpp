#include "System.h"
#include <iostream>
#ifdef APPLE
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
namespace GoombMan {

    System::System() {
        SDL_Init(SDL_INIT_EVERYTHING);
        win = SDL_CreateWindow("KebabMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, 0);
        ren = SDL_CreateRenderer(win, -1, 0);
        TTF_Init();
        font = TTF_OpenFont("Roboto-Regular.ttf", 36);

        SDL_Surface* bgSurf = SDL_LoadBMP("lena.bmp");
        windowSurface = SDL_GetWindowSurface(win);
        SDL_Texture* bgTxt = SDL_CreateTextureFromSurface(ren, bgSurf);

        if (NULL == bgSurf) {
            std::cout << "SDL could not load image! SDL Error: " << SDL_GetError() << std::endl;
        }

        SDL_BlitSurface(bgSurf, NULL, windowSurface, NULL);

        //Update the surface
        SDL_UpdateWindowSurface(win);

        SDL_FreeSurface(bgSurf);
        SDL_Delay(5000);

        //Uint32 white = SDL_MapRGB(bgSurf->format, 255, 255, 255);
        //SDL_SetColorKey(bgSurf, true, white);

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
    // What does this one do?
    System sys;
}
