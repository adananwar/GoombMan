#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Kebab.h"
#include "Rectangle.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

namespace GoombMan {
    class Session {
    public:
        void add(Component* c);
        void addFood(Kebab* k);
        void addWall(Rectangle* r);
        void run();
        ~Session();
    private:
        std::vector<Component*> comps;
        std::vector<Kebab*> food;
        std::vector<Rectangle*> walls;
    };
}
#endif /* Session_h */


