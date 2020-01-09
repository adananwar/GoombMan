#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Component.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

namespace GoombMan {
    class Session {
    public:
        void add(Component* c);
        void run();
        ~Session();
    private:
        std::vector<Component*> comps;
    };
}
#endif /* Session_h */
