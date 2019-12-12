#ifndef SESSION_H
#define SESSION_H
#include <vector>
// Måste skapa en Component.h klass
#include "Component.h"
namespace GoombMan {
class Session {
public:
    void add(Component* c);
    void run();
    ~Session();
private:
    std::vector<Component*> comps;
    };
}
#endif /* Session_h */
