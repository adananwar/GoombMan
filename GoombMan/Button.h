#ifndef BUTTON_H
#define BUTTON_H
#include "Component.h"
#include <SDL2/SDL.h>
#include <string>

namespace GoombMan {
    class Button : public Component
    {
    public:
        static Button* getInstance(int x, int y, int w, int h, std::string txt);
        void mouseDown(const SDL_Event&);
        void mouseUp(const SDL_Event&);
        void draw() const;
        virtual void perform(Button* source) {}
        ~Button();
    protected:
        Button(int x, int y, int w, int h, std::string txt);
    private:
        std::string text;
        SDL_Texture* texture;
        SDL_Texture* kebabIcon, *downIcon;
        bool isDown = false;
    };
}
#endif