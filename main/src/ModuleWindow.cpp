#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
//#include "SDL.h"

#include "SDL.h"

ModuleWindow::ModuleWindow() : Module()
{
}

// Destructor
ModuleWindow::~ModuleWindow()
{
}

// Called before render is available
bool ModuleWindow::Init()
{
	// LOG("Init SDL window & surface");
	bool ret = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		// LOG("SDL_VIDEO could not initialize! SDL_Error:\n");
		// LOG(SDL_GetError());
		ret = false;
	}
	else
	{
		//Create window
		int width = SCREEN_WIDTH;
		int height = SCREEN_HEIGHT;
		Uint32 flags = SDL_WINDOW_SHOWN;

		if(WIN_FULLSCREEN == true)
			flags |= SDL_WINDOW_FULLSCREEN;

		if(WIN_BORDERLESS == true)
			flags |= SDL_WINDOW_BORDERLESS;

		if(WIN_RESIZABLE == true)
			flags |= SDL_WINDOW_RESIZABLE;

		if(WIN_FULLSCREEN_DESKTOP == true)
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

//		window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

		// Create an application window with the following settings:
		window = SDL_CreateWindow(
				"An SDL2 window",                  // window title
				SDL_WINDOWPOS_UNDEFINED,           // initial x position
				SDL_WINDOWPOS_UNDEFINED,           // initial y position
				width,                               // width, in pixels
				height,                               // height, in pixels
				SDL_WINDOW_OPENGL                  // flags - see below
		);

		if(window == NULL)
		{
			// LOG("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			ret = false;
		}
		else
		{
//			//Get window surface
//			screen_surface = SDL_GetWindowSurface(window);  // 这句话会导致后面的renderer生成失败， 可能是SDL2在windows的调用方式。
		}
	}

	return ret;
}

// Called before quitting
bool ModuleWindow::CleanUp()
{
	// LOG("Destroying SDL window and quitting all SDL systems");

	//Destroy window
	if(window != NULL)
		SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
	return true;
}