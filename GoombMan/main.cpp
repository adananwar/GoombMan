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
        OkaKnapp(Label* lbl) :Button(100, 100, 150, 150), label(lbl) {}
        void perform(Button* source) {
        }
    private:
        Label* label;
    };

    // Lägg till knappen här
    Session ses;
    Label* lbl = Label::getInstance(500, 15, 50, 50, "0");
    ses.add(lbl);
    Label* lb2 = Label::getInstance(400, 0, 100, 70, "Score:");
    ses.add(lb2);
    //Label* lb2 = Label::getInstance(<#int x#>, <#int y#>, <#int w#>, <#int h#>, <#std::string txt#>)
    Button* b = new OkaKnapp(lbl);
    ses.add(b);
    ses.run();


    return 0;
}
