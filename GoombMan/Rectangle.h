#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Component.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include <string>

namespace GoombMan {
    class Rectangle : public Component
    {
    public:
        static Rectangle* getInstance(int x, int y, int w, int h);
        // Behövs dessa keyDown ens?
        void keyDown(const SDL_Event&);
        void keyUp(const SDL_Event&);
        void keyRight(const SDL_Event&);
        void keyLeft(const SDL_Event&);
        void draw();
        virtual void perform(Rectangle* source) {}
        Rectangle(int x, int y, int w, int h);
        ~Rectangle();
        SDL_Texture* bgTxt;
    private:
        SDL_Texture* rectIcon;
        // Behövs dessa?
        SDL_Texture* goombTxt;
        SDL_Texture* kebabIcon, * downIcon;
        SDL_Rect goombRect;
         
        bool isDown = false;
    };
}

#endif /* Rectangle_h */
