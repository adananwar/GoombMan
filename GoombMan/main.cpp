#define SDL_MAIN_HANDLED
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#include <iostream>
#endif
#include "Label.h"
#include "Session.h"
#include "Goomba.h"
#include "Kebab.h"
#include <string>
using namespace std;
using namespace GoombMan;

int main(int argc, const char* argv[]) {


    Session ses;
    Label* lbl = Label::getInstance(510, 11, 33, 37, "0");
    ses.add(lbl);
    Label* lb2 = Label::getInstance(430, 0, 80, 50, "Score:");
    ses.add(lb2);

    Rectangle* r1 = new Rectangle(0, 220, 180, 40);
    Rectangle* r2 = new Rectangle(0, 320, 180, 40);
    Rectangle* r3 = new Rectangle(300, 0, 100, 540);

    Goomba* b = new Goomba(200, 200, 50, 50);
    Kebab* k = new Kebab(550, 550, 40, 50);
    Kebab* k2 = new Kebab(330, 150, 40, 50);

    ses.addWall(r1);
    ses.addWall(r2);
    ses.addWall(r3);

    ses.add(b);
    ses.add(k);
    ses.add(k2);

    ses.run();


    return 0;
}


