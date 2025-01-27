#ifndef LABEL_H
#define LABEL_H
#include "Component.h"
#include <string>
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
namespace GoombMan {

    class Label : public Component
    {
    public:
        static Label* getInstance(int x, int y, int w, int h, std::string txt);
        void draw();
        std::string getText() const;
        void setText(std::string newText);
        ~Label();
    protected:
        Label(int x, int y, int w, int h, std::string txt);
    private:
        std::string text;
        SDL_Texture* texture;
    };

}
#endif
