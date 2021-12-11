#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL2_gfxPrimitives.h"
#include "SDL_ttf.h"

#include "Globals.h"
#include "Application.h"

//static char * icon_xpm[] = {
//        "32 23 3 1",
//        "     c #FFFFFF",
//        ".    c #000000",
//        "+    c #FFFF00",
//        "                                ",
//        "            ........            ",
//        "          ..++++++++..          ",
//        "         .++++++++++++.         ",
//        "        .++++++++++++++.        ",
//        "       .++++++++++++++++.       ",
//        "      .++++++++++++++++++.      ",
//        "      .+++....++++....+++.      ",
//        "     .++++.. .++++.. .++++.     ",
//        "     .++++....++++....++++.     ",
//        "     .++++++++++++++++++++.     ",
//        "     .++++++++++++++++++++.     ",
//        "     .+++++++++..+++++++++.     ",
//        "     .+++++++++..+++++++++.     ",
//        "     .++++++++++++++++++++.     ",
//        "      .++++++++++++++++++.      ",
//        "      .++...++++++++...++.      ",
//        "       .++............++.       ",
//        "        .++..........++.        ",
//        "         .+++......+++.         ",
//        "          ..++++++++..          ",
//        "            ........            ",
//        "                                "};
//
//int SDL_main(int argc, char* argv[]) {
//
//    SDL_Window *window;                    // Declare a pointer
//    SDL_Surface *surface;
//    SDL_Texture *texture;
//    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
//
//    // Create an application window with the following settings:
//    window = SDL_CreateWindow(
//        "An SDL2 window",                  // window title
//        SDL_WINDOWPOS_UNDEFINED,           // initial x position
//        SDL_WINDOWPOS_UNDEFINED,           // initial y position
//        716,                               // width, in pixels
//        720,                               // height, in pixels
//        SDL_WINDOW_OPENGL                  // flags - see below
//    );
//
//    // Check that the window was successfully created
//    if (window == NULL) {
//        // In the case that the window could not be made...
//        printf("Could not create window: %s\n", SDL_GetError());
//        return 1;
//    }
//
//    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1 ) {
//        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
//                     "Couldn't open mixer: %s", SDL_GetError());
//        return 2;
//    }
//
//    Mix_Chunk *sample = Mix_LoadWAV("cuckoo.wav");
//    if (sample == NULL) {
//        fprintf(stderr, "Unable to load wave file\n");
//        return 3;
//    }
//
//
//    // Setup renderer
//    SDL_Renderer* renderer = NULL;
//    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
//
//    surface = IMG_ReadXPMFromArray(icon_xpm);
//    texture = SDL_CreateTextureFromSurface(renderer, surface);
//    if (!texture) {
//        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
//                     "Couldn't load texture: %s", SDL_GetError());
//        return 4;
//    }
//
//    // Set render color to red ( background will be rendered in this color )
//    SDL_SetRenderDrawColor( renderer, 220, 220, 220, 255 );
//
//    // Clear winow
//    SDL_RenderClear( renderer );
//
//    // Display image
//    SDL_Rect dstrect;
//
//
//    // Load smiley.png and display it.
//    // Location of image files for Android is: app/src/main/assets
//    SDL_Surface *loadedSurface = IMG_Load("smiley.png");
//    if (!loadedSurface) {
//        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
//                     "Couldn't load PNG image: %s", SDL_GetError());
//        return 5;
//    }
//
//    SDL_Surface *backgroundSurface = IMG_Load("brno-snow.jpg");
//    if (!backgroundSurface) {
//        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
//                     "Couldn't load JPG image: %s", SDL_GetError());
//        return 6;
//    }
//
//    // Initialize TTF
//    if (TTF_Init() == -1) {
//        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF_Init: %s\n", TTF_GetError());
//        return 7;
//    }
//
//    // Load font
//    TTF_Font *font = TTF_OpenFont("blazed.ttf", 32);
//    if (!font) {
//        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
//                     "Unable to load font: %s\n", TTF_GetError());
//        return 8;
//    }
//
//    dstrect.x = 0;
//    dstrect.y = 0;
//    dstrect.w = backgroundSurface->w;
//    dstrect.h = backgroundSurface->h;
//    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
//    SDL_RenderCopy(renderer, backgroundTexture, NULL, &dstrect);
//
//    dstrect.x = 190;
//    dstrect.y = 130;
//    dstrect.w = loadedSurface->w;
//    dstrect.h = loadedSurface->h;
//    SDL_Texture *smileyTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
//    SDL_RenderCopy(renderer, smileyTexture, NULL, &dstrect);
//
//    dstrect.x = 20;
//    dstrect.y = 120;
//    dstrect.w = 128;
//    dstrect.h = 128;
//    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
//
//    dstrect.x = 0;
//    dstrect.y = 0;
//    dstrect.w = 450;
//    dstrect.h = 100;
//    SDL_Color textColor = { 255, 240, 0, 255 };
//    SDL_Surface* solid = TTF_RenderText_Solid(font, "SDL2 Android Example", textColor);
//
//    SDL_Texture* solidTexture = SDL_CreateTextureFromSurface(renderer, solid);
//    SDL_RenderCopy(renderer, solidTexture, NULL, &dstrect);
//    SDL_FreeSurface(solid);
//
//    // SDL2_gfx example
//    thickLineColor(renderer, 0, 300, 300, 300, 20, 0xFF00FFFF) ;
//
//    // Render to the screen
//    SDL_RenderPresent(renderer);
//
//    // Event loop
//    bool quit = false;
//    SDL_Event event;
//    while(!quit && SDL_WaitEvent(&event)) {
//        switch (event.type) {
//            case SDL_QUIT:
//                quit = true;
//                break;
//            case SDL_KEYDOWN:
//                if ((event.key.keysym.sym == SDLK_AC_BACK) || (event.key.keysym.sym == SDLK_ESCAPE)) {
//                    quit = true;
//                }
//                break;
//
//            case SDL_FINGERDOWN: {
//                Mix_PlayChannel(-1, sample, 0);
//                dstrect.x = event.tfinger.x * loadedSurface->w;
//                dstrect.y = event.tfinger.y * loadedSurface->h;
//                dstrect.w = 128;
//                dstrect.h = 128;
//                SDL_RenderCopy(renderer, texture, NULL, &dstrect);
//                SDL_RenderPresent(renderer);
//                break;
//            }
//            default:
//                break;
//        }
//    }
//
//    Mix_CloseAudio();
//
//    // Close and destroy the window
//    SDL_DestroyWindow(window);
//
//    // Clean up
//    SDL_Quit();
//
//    return 0;
//}

enum main_states
{
    MAIN_CREATION,
    MAIN_START,
    MAIN_UPDATE,
    MAIN_FINISH,
    MAIN_EXIT
};

Application* App = nullptr;

int SDL_main(int argc, char* argv[])
{
//    ReportMemoryLeaks();

    int main_return = EXIT_FAILURE;
    main_states state = MAIN_CREATION;

    while (state != MAIN_EXIT)
    {
        switch (state)
        {
            case MAIN_CREATION:
            {
                // LOG("Application Creation --------------");
                App = new Application();
                state = MAIN_START;
            }	break;

            case MAIN_START:
            {
                // LOG("Application Init --------------");
                if(App->Init() == false)
                {
                    // LOG("Application Init exits with error -----");
                    state = MAIN_EXIT;
                }
                else
                {
                    state = MAIN_UPDATE;
                    // LOG("Application Update --------------");
                }

            }	break;

            case MAIN_UPDATE:
            {
                int update_return = App->Update();

                if (update_return == UPDATE_ERROR)
                {
                    // LOG("Application Update exits with error -----");
                    state = MAIN_EXIT;
                } else if (update_return == UPDATE_STOP)
                    state = MAIN_FINISH;
            }
                break;

            case MAIN_FINISH:
            {
                // LOG("Application CleanUp --------------");
                if(App->CleanUp() == false)
                {
                    // LOG("Application CleanUp exits with error -----");
                }
                else
                    main_return = EXIT_SUCCESS;

                state = MAIN_EXIT;

            } break;

            case MAIN_EXIT:
                break;
        }
    }

    delete App;
    // LOG("Bye :)\n");
    return main_return;
}