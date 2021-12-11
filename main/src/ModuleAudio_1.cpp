#include "Globals.h"
#include "Application.h"
#include "ModuleAudio_1.h"
#include "ModuleAudio_2.h"
#include "ModuleMap1.h"
#include "ModuleRender.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL2_gfxPrimitives.h"
#include "SDL_ttf.h"

ModuleAudio1::ModuleAudio1() : Module()
{

}

ModuleAudio1::~ModuleAudio1()
{

}

bool ModuleAudio1::Init()
{
//	if (Mix_Init(MIX_INIT_OGG) == 0)
//	if (Mix_Init(MIX_INIT_MOD) == 0)
//	{
//		// LOG("An error has ocurred while initializing the audio: %s", SDL_GetError())
//			return false;
//	}

//	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
//	{
//		// LOG("An error has ocurred while opening the audio has ocurred: %s", SDL_GetError())
//	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1 ) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
					 "Couldn't open mixer: %s", SDL_GetError());
		return 2;
	}

//	ModuleAudio1::Load("Sound effects/Boss song.ogg");
	ModuleAudio1::Load("cuckoo.wav");

	
	return true;
}
update_status ModuleAudio1::Update()
{
	
	if (App->render->camera.y < -12000 && playing == false)
	{
//		if (Mix_PlayMusic(music, -1) == -1)
		if (Mix_PlayChannel(-1, music, 0) == -1)
		{
			// LOG("An error has ocurred while reproducing the audio %s", SDL_GetError())
		}

		playing = true;
	}

	if (App->render->camera.y > -12000 && playing == true)
	{
		playing = false;
	}

	return UPDATE_CONTINUE;
}
Mix_Chunk* const ModuleAudio1::Load(const char* path)
{

//	music = Mix_LoadMUS(path);
//	if (music == NULL)
//	{
//		// LOG("An error has ocurred when loading the sound: %s", SDL_GetError())
//	}

	music = Mix_LoadWAV("cuckoo.wav");
	if (music == NULL) {

	}

	return music;
}
bool ModuleAudio1::CleanUp()
{
	Mix_CloseAudio();
//	Mix_FreeMusic(music);
	return true;
}

bool ModuleAudio1::Close()
{
	Mix_CloseAudio();
	return true;
}