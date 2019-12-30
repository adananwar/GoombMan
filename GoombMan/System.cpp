#include "System.h"
#include <iostream>
#ifdef APPLE
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
namespace GoombMan {

    System::System() {
        SDL_Init(SDL_INIT_EVERYTHING);
        win = SDL_CreateWindow("KebabMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, 0);
        ren = SDL_CreateRenderer(win, -1, 0);
        TTF_Init();
        font = TTF_OpenFont("Roboto-Regular.ttf", 36);

        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
        {
            std::cout << "Failed to initialise SDL_image for PNG files: " << IMG_GetError() << std::endl;
        }

        SDL_Surface* bgSurf = SDL_LoadBMP("lena.bmp");
        windowSurf = SDL_GetWindowSurface(win);
        SDL_Texture* bgTxt = SDL_CreateTextureFromSurface(ren, bgSurf);

        if (NULL == bgSurf) {
            std::cout << "SDL could not load image! SDL Error: " << SDL_GetError() << std::endl;
        }

        SDL_BlitSurface(bgSurf, NULL, windowSurf, NULL);

        //Update the surface
        SDL_UpdateWindowSurface(win);

        SDL_FreeSurface(bgSurf);
        SDL_Delay(1000);

        //Uint32 white = SDL_MapRGB(bgSurf->format, 255, 255, 255);
        //SDL_SetColorKey(bgSurf, true, white);

    }


    System::~System() {
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }

    SDL_Renderer* System::get_ren() const {
        return ren;
    }

    TTF_Font* System::get_font() const {
        return font;
    }

    SDL_Surface* System::get_windowSurf() const {
        return windowSurf;
    }
    // What does this one do?
    System sys;
}


#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

const int WIDTH = 512, HEIGHT = 512;

int main(int argc, char* argv[])
{
	SDL_Surface* imageSurface = NULL;
	SDL_Surface* windowSurface = NULL;
	TTF_Font* font;

	if (TTF_Init() < 0)
	{
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	font = TTF_OpenFont("Roboto-Regular.ttf", 36);
	if (NULL == font) {
		std::cout << "SDL could not load font! SDL Error: " << SDL_GetError() << std::endl;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialise! SDL Error: " << SDL_GetError() << std::endl;
	}
	SDL_Window* window = SDL_CreateWindow("Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	windowSurface = SDL_GetWindowSurface(window);

	if (NULL == window)
	{
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cout << "Failed to initialise SDL_image for PNG files: " << IMG_GetError() << std::endl;
	}

	SDL_Event windowEvent;
	imageSurface = IMG_Load("trubb.png");
	if (NULL == imageSurface) {
		std::cout << "SDL could not load image! SDL Error: " << SDL_GetError() << std::endl;
	}
	while (true)
	{
		if ( SDL_PollEvent( &windowEvent ) )
		{
			if (SDL_QUIT == windowEvent.type)
			{
				break;
			}
		}
		SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);
	}

	SDL_FreeSurface(imageSurface);
	SDL_FreeSurface(windowSurface);

	imageSurface = NULL;
	windowSurface = NULL;

	SDL_DestroyWindow(window);
	SDL_Quit;
	return EXIT_SUCCESS;
}