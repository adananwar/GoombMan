#include <SDL2/SDL.h>
#include "Label.h"
#include "Session.h"
#include "Button.h"
#include <string>
using namespace std;
using namespace GoombMan;

int main(int argc, const char * argv[]) {

    class OkaKnapp : public Button {
    public:
        OkaKnapp(Label *lbl) :Button(100, 100, 150, 70, "÷ka"), label(lbl) {}
        void perform(Button* source) {
        }
    private:
        Label* label;
    };
    
    // Lägg till knappen här
    Session ses;
       Label* lbl = Label::getInstance(270, 100, 100, 70, "0");
       ses.add(lbl);
       Button* b = new OkaKnapp(lbl);
       ses.add(b);
       ses.run();

    
    return 0;
}
