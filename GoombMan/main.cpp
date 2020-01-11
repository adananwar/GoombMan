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

    class Rulle : public Kebab {
    public:
        Rulle(Label* lbl) :Kebab(350, 350, 40, 50), label(lbl) {}
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
    Button* b = new OkaKnapp(lbl);
    ses.add(b);
    ses.add(k);
    ses.run();


    return 0;
}
