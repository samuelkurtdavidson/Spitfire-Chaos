#pragma once
#include "Module.h"

struct SDL_Surface;
struct SDL_Renderer;

class ModuleRender : public Module
{
public:
	SDL_Surface * gSurface;
	SDL_Renderer * gWIndow;

	ModuleRender();
	~ModuleRender();
};

