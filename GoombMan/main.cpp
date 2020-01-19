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
    Rectangle* r4 = new Rectangle(500, 510, 100, 40);

    ses.add(r1);
    ses.add(r2);
    ses.add(r3);
    ses.add(r4);

    ses.addWall(r1);
    ses.addWall(r2);
    ses.addWall(r3);
    ses.addWall(r4);

    ses.run();


    return 0;
}


