#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

struct SDL_Window;

// TODO 1: Create the declaration of ModuleWindow class

class ModuleWindow : public Module {
public:
	SDL_Window * Window = nullptr;

	bool Init();
	bool CleanUp();
};

#endif // __ModuleWindow_H__