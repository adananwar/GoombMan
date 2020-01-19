#include "Component.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

namespace GoombMan {

	Component::Component(int x, int y, int w, int h) :rect{ x,y,w,h } {
	}


	Component::~Component() {
	}
}
