#include "Globals.h"
#include "Application.h"
#include "SDL/include/SDL.h"
#include "ModuleWindow.h"



// TODO 2: Init the library and check for possible error
// using SDL_GetError()



bool ModuleWindow::Init() {
	bool ret = true;
	int check = SDL_Init(SDL_INIT_VIDEO);

	if (check < 0) {
		LOG("Error intialising Window subsytem %s", SDL_GetError());
		ret = false;
	}

	ModuleWindow::Window = SDL_CreateWindow("Spitfire Chaos", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

	return ret;
}

bool ModuleWindow::CleanUp() {
	SDL_DestroyWindow(Window);
	SDL_Quit();
	return true;
}

// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors


// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)

