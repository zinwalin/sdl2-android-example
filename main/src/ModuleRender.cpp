#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleTextures.h"
//#include "SDL.h"

#include "SDL.h"
#include "SDL_ttf.h"

ModuleRender::ModuleRender() : Module()
{
	camera.x = camera.y = 0;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;

}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	// LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if(REN_VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

//	renderer = SDL_CreateRenderer(App->window->window, -1, flags);
	renderer =  SDL_CreateRenderer(App->window->window, -1, SDL_RENDERER_ACCELERATED);

	if(renderer == NULL)
	{
		// LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	// TODO 9: load a texture "test.png" to test is everything works well

	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	SDL_SetRenderDrawColor(App->render->renderer,0, 0, 0, 255);

	if (SDL_RenderClear(App->render->renderer) == -1)
	{
		// LOG("An error has ocurred when clearing the screen %s", SDL_GetError());
	}

	// TODO 7: Clear the screen to black before starting every frame
	
	// TODO 10: Blit our test texture to check functionality

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	// TODO 8: Switch buffers so we actually render

//	// Clear window
//    SDL_RenderClear( renderer );
//
//    // Display image
//    SDL_Rect dstrect;
//
//	// Initialize TTF
//	if (TTF_Init() == -1) {
//		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF_Init: %s\n", TTF_GetError());
//		return update_status::UPDATE_ERROR;
//	}
//
//	// Load font
//	TTF_Font *font = TTF_OpenFont("blazed.ttf", 32);
//	if (!font) {
//		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
//					 "Unable to load font: %s\n", TTF_GetError());
//		return update_status::UPDATE_ERROR;
//	}
//
//	dstrect.x = 0;
//    dstrect.y = 0;
//    dstrect.w = 450;
//    dstrect.h = 100;
//
//	SDL_Color textColor = { 255, 240, 0, 255 };
//	SDL_Surface* solid = TTF_RenderText_Solid(font, "SDL2 Android Example", textColor);
//
//    SDL_Texture* solidTexture = SDL_CreateTextureFromSurface(renderer, solid);
//    SDL_RenderCopy(renderer, solidTexture, NULL, &dstrect);
//    SDL_FreeSurface(solid);

	SDL_RenderPresent(App->render->renderer);

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	// LOG("Destroying renderer");

	//Destroy window
	if(renderer != nullptr)
	{ 
		SDL_DestroyRenderer(renderer);
    }
	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, float x, float y, SDL_Rect* section, int w, int h, int modifier)
{
	section->y += modifier;
	bool ret = true;
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;

	if (section != nullptr)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}

	if (w != 0 && h != 0)
	{
		rect.w = w;
		rect.h = h;
	}
    
	SDL_RenderSetLogicalSize(renderer, 672, 830);

	if (SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		// LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	section->y -= modifier;

	return ret;
}

	bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera)
	{
		bool ret = true;

		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(renderer, r, g, b, a);

		SDL_Rect rec(rect);
		if (use_camera)
		{
			rec.x = (int)(camera.x + rect.x * SCREEN_SIZE);
			rec.y = (int)(camera.y + rect.y * SCREEN_SIZE);
			rec.w *= SCREEN_SIZE;
			rec.h *= SCREEN_SIZE;
		}

		if (SDL_RenderFillRect(renderer, &rec) != 0)
		{
			// LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
			ret = false;
		}

		return ret;
	}
