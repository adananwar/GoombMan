#include "Button.h"
#include "System.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
namespace GoombMan {

    Button::Button(int x, int y, int w, int h, std::string txt):Component(x,y,w,h)
    {
        SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), { 0,0,0 });
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);
        kebabIcon = IMG_LoadTexture(sys.get_ren(), "kebab.png");
        // Down Icon may not be necessary, change to pacman instead?
        downIcon = IMG_LoadTexture(sys.get_ren(), "kebab.png");
    }

    Button::~Button()
    {
        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(kebabIcon);
        SDL_DestroyTexture(downIcon);
    }

    Button* Button::getInstance(int x, int y, int w, int h, std::string txt) {
        return new Button(x, y, w, h, txt);
    }

    void Button::mouseDown(const SDL_Event& eve) {
        SDL_Point p = { eve.button.x, eve.button.y };
        if (SDL_PointInRect(&p, &getRect()))
            isDown = true;
    }
    void Button::mouseUp(const SDL_Event& eve) {
        SDL_Point p = { eve.button.x, eve.button.y };
        if (SDL_PointInRect(&p, &getRect()))
            perform(this);

        isDown = false;
    }
    void Button::draw() const {
        if (isDown)
            SDL_RenderCopy(sys.get_ren(), downIcon, NULL, &getRect());
        else
            SDL_RenderCopy(sys.get_ren(), kebabIcon, NULL, &getRect());

        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());

    }
}
