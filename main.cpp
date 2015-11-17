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
string POLICE = "duck_hunt.tff";


int main ()
{
    bool quit=false;

    SDL_Surface *screen, *fondMenu, *texte = NULL;
    SDL_Event event;

    TTF_Init();
    TTF_Font *menuFonts;
    int fontSizeMenu = 100;
    menuFonts = TTF_OpenFont(POLICE.c_str(),fontSizeMenu);
    SDL_Color menuColor = {0, 0 ,0};

    texte = TTF_RenderText_Blended(menuFonts, "Salut les Zér0s !", menuColor);

    ostringstream mssg;

    SDL_Init(SDL_INIT_EVERYTHING);
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, SCREEN_BPP,SDL_SWSURFACE);
    fondMenu = IMG_Load(MENU.c_str());

    while(!quit)
    {
        mssg.flush();
        SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,0,255,0));

        SDL_BlitSurface(fondMenu, NULL, screen, NULL);

        SDL_Flip(screen);

        while(SDL_PollEvent(&event))
            if(event.type==SDL_QUIT)
            {
                quit=true;
            }
    }



    SDL_FreeSurface(screen);

    SDL_Quit();

    return EXIT_SUCCESS;
}
