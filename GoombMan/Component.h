#ifndef COMPONENT_H
#define COMPONENT_H
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include <vector>

namespace GoombMan {
    class Component
    {
    public:
        virtual ~Component();
        virtual void keyUp(const SDL_Event&) {}
        virtual void keyDown(const SDL_Event&) {}
        virtual void keyLeft(const SDL_Event&) {}
        virtual void keyRight(const SDL_Event&) {}
        virtual void draw() = 0;
        virtual void handleCollision(std::vector<Component*> comps) {}
        SDL_Rect getRect() { return rect; }
    protected:
        Component(int x, int y, int w, int h);
        SDL_Rect rect;
    private:
        Component(const Component&) = delete;
        const Component& operator=(const Component&) = delete;
    };
}

#endif /* Component_h */