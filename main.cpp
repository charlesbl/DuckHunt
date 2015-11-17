#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <affichage.h>
#include <niveau.h>

using namespace std;

const int SCREEN_WIDTH=750;
const int SCREEN_HEIGHT=761;
const int SCREEN_BPP=32;

const string MENU = "menu.png";
const string NIVEAU = "backGame.png";
const string CROSSAIR = "viseur.png";


int main ()
{
    bool quit=false;
    bool menu=true;

    SDL_Surface *screen, *fondMenu, *fondNiveau, *crossair, *texte = NULL;
    SDL_Event event;

    SDL_Rect rCrossair = {0, 0, 0, 0};

    SDL_Init(SDL_INIT_EVERYTHING);
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, SCREEN_BPP,SDL_SWSURFACE);
    fondMenu = IMG_Load(MENU.c_str());
    fondNiveau = IMG_Load(NIVEAU.c_str());
    crossair = SDL_DisplayFormat(IMG_Load(CROSSAIR.c_str()));

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
            SDL_ShowCursor(0);
            SDL_BlitSurface(fondNiveau, NULL, screen, NULL);

            SDL_SetColorKey(crossair, SDL_SRCCOLORKEY, SDL_MapRGB(crossair->format, 0, 0, 0));
            SDL_BlitSurface(crossair, NULL, screen, &rCrossair);

            niveau niv;
            niv.cNoir.rect;
            initNiveau(niv,4);
            updateNiv(niv);
        }
        if(keystates[SDLK_SPACE])
                menu=false;
        if(keystates[SDLK_ESCAPE])
                quit=true;

        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                quit=true;
            }
            else if(event.type == SDL_MOUSEMOTION && !menu)
            {
                int x = event.button.x;
                int y = event.button.y;

                rCrossair = {x, y, 30, 30};
            }
        }
        SDL_Flip(screen);
        SDL_Delay(10);
    }

    TTF_CloseFont(menuFonts);
    TTF_Quit();

    SDL_FreeSurface(screen);
    SDL_Quit();

    return EXIT_SUCCESS;
}
