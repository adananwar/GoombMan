#ifndef SYSTEM_H
#define SYSTEM_H

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#else
#include <SDL.h>
#include <SDL_ttf.h>
#endif
namespace GoombMan {
    class System {
    public:
        //Constructor
        System();
        //Destructor
        ~System();
        SDL_Renderer* get_ren() const;
        TTF_Font* get_font() const;
        SDL_Texture* get_bgTxt() const;
        SDL_Surface* get_windowSurf() const;
    private:
        SDL_Window* win;
        SDL_Texture* bgTxt;
        SDL_Surface* windowSurf;
        SDL_Renderer* ren;
        TTF_Font* font;
    };
    extern System sys;
}

#endif /* System_h */

