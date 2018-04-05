#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleIntro.h"
#include "ModuleSceneSpace.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ModuleIntro::ModuleIntro() {}

ModuleIntro::~ModuleIntro() {}

bool ModuleIntro::Start()
{
	LOG("Loading intro scene");

	background = App->textures->Load("rtype/intro.png");
	App->mixer->PlayMusic("rtype/intro.ogg");
	return true;
}

bool ModuleIntro::CleanUp()
{
	LOG("Unloading intro scene");

	App->textures->Unload(background);
	return true;
}

// Update: draw background
update_status ModuleIntro::Update()
{
	App->render->Blit(background, 0, -25, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
		App->fade->FadeToBlack(App->scene_intro, App->scene_space, 2.0f);

	return UPDATE_CONTINUE;
}