#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <affichage.h>
using namespace std;

const int SCREEN_WIDTH=750;
const int SCREEN_HEIGHT=761;
const int SCREEN_BPP=32;

const string MENU = "menu.png";
const string NIVEAU = "backGame.png";


int main ()
{
    bool quit=false;
    bool menu=true;

    SDL_Surface *screen, *fondMenu, *fondNiveau, *texte = NULL;
    SDL_Event event;

    SDL_Init(SDL_INIT_EVERYTHING);
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, SCREEN_BPP,SDL_SWSURFACE);
    fondMenu = IMG_Load(MENU.c_str());
    fondNiveau = IMG_Load(NIVEAU.c_str());

    TTF_Init();
    TTF_Font *menuFonts;
    menuFonts = TTF_OpenFont("duck_hunt.tff",60);
    SDL_Color menuColor = {0, 0 ,0};

    //texte = TTF_RenderText_Blended(menuFonts, "Salut les Zér0s !", menuColor);

    ostringstream mssg;
    Uint8 *keystates = SDL_GetKeyState(NULL);

    while(!quit)
    {
        mssg.flush();
        SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,0,255,0));

        if(menu)
        {
            SDL_BlitSurface(fondMenu, NULL, screen, NULL);
        }else
        {
            SDL_BlitSurface(fondNiveau, NULL, screen, NULL);

        }
        if(keystates[SDLK_SPACE])
                menu=false;

        SDL_Flip(screen);

        while(SDL_PollEvent(&event))
            if(event.type==SDL_QUIT)
            {
                quit=true;
            }
    }

    TTF_CloseFont(menuFonts);
    TTF_Quit();

    SDL_FreeSurface(screen);
    SDL_Quit();

    return EXIT_SUCCESS;
}
