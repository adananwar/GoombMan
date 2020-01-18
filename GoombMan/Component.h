#ifndef COMPONENT_H
#define COMPONENT_H
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <vector>
#else
#include <SDL.h>
#endif

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
        const SDL_Rect& getRect() const { return rect; }
        SDL_Rect rect;
    protected:
        Component(int x, int y, int w, int h);
    private:
        Component(const Component&) = delete;
        const Component& operator=(const Component&) = delete;
    };
}

#endif /* Component_h */
