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

        void keyDown(const SDL_Event&);
        void keyUp(const SDL_Event&);
        void keyRight(const SDL_Event&);
        void keyLeft(const SDL_Event&);
        void draw();
        virtual void perform(Rectangle* source) {}
        Rectangle(int x, int y, int w, int h);
        ~Rectangle();
    private:
        SDL_Texture* rectIcon;
    };
}

#endif /* Rectangle_h */
