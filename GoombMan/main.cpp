#define SDL_MAIN_HANDLED
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#include <iostream>
#endif
#include "Label.h"
#include "Session.h"
#include "Button.h"
#include "Kebab.h"
#include "Rectangle.h"
#include <string>
using namespace std;
using namespace GoombMan;

int main(int argc, const char* argv[]) {

    class OkaKnapp : public Button {
    public:
        OkaKnapp(Label* lbl) :Button(200, 200, 50, 50), label(lbl) {}
        void perform(Button* source) {
        }
    private:
        Label* label;
    };
    


    Session ses;
    Label* lbl = Label::getInstance(485, 11, 33, 37, "0");
    ses.add(lbl);
    Label* lb2 = Label::getInstance(400, 0, 80, 50, "Score:");
    ses.add(lb2);

    Rectangle* r = new Rectangle(270, 500, 70, 200);
    Button* b = new OkaKnapp(lbl);
    Kebab* k = new Kebab(350, 350, 40, 50);

    ses.add(r);
    ses.add(b);
    ses.add(k);
    ses.run();


    return 0;
}
