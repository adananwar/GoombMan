#include "Button.h"
#include "System.h"
#include "Session.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#else
#include <SDL.h>
#include <iostream>
#include <SDL_ttf.h>
#include <SDL_image.h>
#endif
namespace GoombMan {

    Button::Button(int x, int y, int w, int h) :Component(x, y, w, h)
    {
        //SDL_Surface* bgSurf = IMG_Load("GoombaTwoThree.png");
        //SDL_Texture* bgTxt = SDL_CreateTextureFromSurface(sys.get_ren(), bgSurf);
        //SDL_FreeSurface(bgSurf);

        goomba = IMG_LoadTexture(sys.get_ren(), "GoombaOne.png");
        SDL_Rect goombRect = { 0, 0, 100, 100 };
        downIcon = IMG_LoadTexture(sys.get_ren(), "GoombaTwo.png");
    }

    Button::~Button()
    {
        SDL_DestroyTexture(goombTxt);
        SDL_DestroyTexture(goomba);
        SDL_DestroyTexture(downIcon);
    }

    Button* Button::getInstance(int x, int y, int w, int h) {
        return new Button(x, y, w, h);
    }

    void Button::keyDown(const SDL_Event& event) {

        if (rect.y + 20 < sys.get_windowSurf()->h - rect.h) {
            rect.y += 20;
        }
        else {
            rect.y = sys.get_windowSurf()->h - rect.h;
        }
        setIcon();
    }
    void Button::keyUp(const SDL_Event& event) {
        if (rect.y - 20 > 0) {
            rect.y -= 20;
        }
        else {
            rect.y = 0;
        }
        setIcon();
    }
    void Button::keyRight(const SDL_Event& event) {
        if (rect.x + 20 < sys.get_windowSurf()->w - rect.w) {
            rect.x += 20;
        }
        else {
            rect.x = sys.get_windowSurf()->w - rect.w;
        }
        setIcon();
    }
    void Button::keyLeft(const SDL_Event& event) {
        if (rect.x - 20 > 0) {
            rect.x -= 20;
        }
        else {
            rect.x = 0;
        }
        setIcon();
    }
    void Button::draw() {
        //SDL_RenderCopy(sys.get_ren(), bgTxt, NULL, NULL);
        SDL_RenderCopy(sys.get_ren(), goomba, NULL, &getRect());
        if (isDown) {
            SDL_RenderCopy(sys.get_ren(), downIcon, NULL, &getRect());
        }
        else {
            SDL_RenderCopy(sys.get_ren(), goomba, NULL, &getRect());
        }
    }
    void Button::setIcon() {
        if (isDown) {
            isDown = false;
        }
        else {
            isDown = true;
        }
    }
}
