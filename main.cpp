#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <SDL/SDL_ttf.h>
using namespace std;

const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;
const int SCREEN_BPP=32;

SDL_Color textColor= {255,255,255};
int fontSize=36;


int main ( int argc, char** argv )
{
    bool quit=false;

    SDL_Surface *screen, *fondMenu;
    SDL_Event event;


    SDL_Init(SDL_INIT_EVERYTHING);
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,
                            SCREEN_BPP,SDL_SWSURFACE);

    fondMenu=SDL_LoadBMP("menu.png");

    while(!quit)
    {
        SDL_FillRect(screen,&screen->clip_rect,
                     SDL_MapRGB(screen->format,0,0,0));

        SDL_BlitSurface(fondMenu,NULL,screen,NULL);

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
