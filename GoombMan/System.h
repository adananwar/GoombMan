#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
namespace GoombMan {
    class System {
    public:
        //Constructor
        System();
        //Destructor
        ~System();
        SDL_Renderer* get_ren() const;
        TTF_Font* get_font() const;
        SDL_Surface* get_windowSurface const;
    private:
        SDL_Window* win;
        SDL_Renderer* ren;
        TTF_Font* font;
        SDL_Surface* windowSurface;
    };
extern System sys;
}

#endif /* System_h */