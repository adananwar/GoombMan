#ifndef KEBAB_H
#define KEBAB_H
#include "Component.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include <string>

namespace GoombMan {
    class Kebab : public Component
    {
    public:
        static Kebab* getInstance(int x, int y, int w, int h);
        void keyDown(const SDL_Event&);
        void keyUp(const SDL_Event&);
        void keyRight(const SDL_Event&);
        void keyLeft(const SDL_Event&);
        void draw();
        virtual void perform(Kebab* source) {}
        Kebab(int x, int y, int w, int h);
        ~Kebab();
        SDL_Texture* bgTxt;
    private:
        SDL_Texture* goombTxt;
        SDL_Texture* kebabIcon, * downIcon;
        SDL_Rect goombRect;
        bool isDown = false;
    };
}
#endif
