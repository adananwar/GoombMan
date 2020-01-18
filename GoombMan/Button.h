#ifndef BUTTON_H
#define BUTTON_H
#include "Component.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include <string>

namespace GoombMan {
    class Button : public Component
    {
    public:
        static Button* getInstance(int x, int y, int w, int h);
        void keyDown(const SDL_Event&);
        void keyUp(const SDL_Event&);
        void keyRight(const SDL_Event&);
        void keyLeft(const SDL_Event&);
        void draw();
        void setIcon();
        virtual void perform() {}
        Button(int x, int y, int w, int h);
        ~Button();
        SDL_Texture* bgTxt;
    private:
        SDL_Texture* goombTxt;
        SDL_Texture* goomba, * downIcon;
        SDL_Rect goombRect;
        bool isDown = false;
    };
}
#endif
