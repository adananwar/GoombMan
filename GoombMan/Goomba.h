#ifndef GOOMBA_H
#define GOOMBA_H
#include "Component.h"
#include "Rectangle.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include <string>

namespace GoombMan {
    class Goomba : public Component
    {
    public:
        static Goomba* getInstance(int x, int y, int w, int h);
        void keyDown(const SDL_Event&);
        void keyUp(const SDL_Event&);
        void keyRight(const SDL_Event&);
        void keyLeft(const SDL_Event&);
        void draw();
        void handleCollision(std::vector<Component*> comps);
        void handleWallCollision(std::vector<Rectangle*> walls);
        void setIcon();
        virtual void perform(Goomba* source) {}
        Goomba(int x, int y, int w, int h);
        ~Goomba();
    private:
        SDL_Texture* goombaIcon, * secondIcon;
        bool isSecond = false;
    };
}
#endif
