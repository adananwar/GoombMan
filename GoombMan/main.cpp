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
int value = 0;

int main(int argc, const char* argv[]) {

    class OkaKnapp : public Button {
    public:
        // 50 50
        OkaKnapp(Label* lbl) :Button(0, 270, 50, 50), label(lbl) {}
        void perform() {
            value++;
            label->setText(to_string(value));
        }
    private:
        Label* label;
    };
    

    Session ses;
    // Göra om denna till en score istället
    Label* lbl = Label::getInstance(510, 11, 33, 37, "0");
    ses.add(lbl);
    Label* lb2 = Label::getInstance(430, 0, 80, 50, "Score:");
    ses.add(lb2);

    Rectangle* r1 = new Rectangle(0, 220, 180, 40);
    Rectangle* r2 = new Rectangle(0, 320, 180, 40);
    Rectangle* r3 = new Rectangle(300, 0, 100, 540);
    Rectangle* r4 = new Rectangle(500, 510, 100, 40);
    Button* b = new OkaKnapp(lbl);
    Kebab* k = new Kebab(550, 550, 40, 50);

    ses.add(r1);
    ses.add(r2);
    ses.add(r3);
    ses.add(r4);
    ses.add(b);
    ses.add(k);
    ses.run();


    return 0;
}
