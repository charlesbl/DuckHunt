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
const string NIVEAUB = "backGameBlit.png";
const string CROSSAIR = "viseur.png";
const string BULLET = "shot.png";
const string DUCK = "duck.png";
int nbAmmo = 3;


int main ()
{
    srand(time(NULL));
    bool quit=false;
    bool showmenu=true;

    SDL_Surface *screen, *fondNiveau, *fondNiveauB, *crossair, *bullet, *duck = NULL;
    SDL_Event event;
    Menu menu;

    SDL_Rect rCrossair = {0, 0, 0, 0};

    SDL_Init(SDL_INIT_EVERYTHING);
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, SCREEN_BPP,SDL_SWSURFACE);
    fondNiveau = IMG_Load(NIVEAU.c_str());
    fondNiveauB = SDL_DisplayFormat(IMG_Load(NIVEAUB.c_str()));
    crossair = SDL_DisplayFormat(IMG_Load(CROSSAIR.c_str()));
    bullet = SDL_DisplayFormat(IMG_Load(BULLET.c_str()));
    duck = SDL_DisplayFormat(IMG_Load(DUCK.c_str()));

    SDL_SetColorKey(bullet, SDL_SRCCOLORKEY, SDL_MapRGB(crossair->format, 255, 255, 255));
    SDL_SetColorKey(crossair, SDL_SRCCOLORKEY, SDL_MapRGB(crossair->format, 0, 0, 0));
    SDL_SetColorKey(fondNiveauB, SDL_SRCCOLORKEY, SDL_MapRGB(crossair->format, 0, 0, 0));
    SDL_SetColorKey(duck, SDL_SRCCOLORKEY, SDL_MapRGB(crossair->format, 228, 255, 0));

    TTF_Init();
    TTF_Font *menuFonts;
    menuFonts = TTF_OpenFont("duck_hunt.ttf",100);

    menu.tJouer = TTF_RenderText_Blended(menuFonts, "Jouer", menu.menuColor);
    menu.rjouer = {80, 80, 300, 100};
    menu.tQuit = TTF_RenderText_Blended(menuFonts, "Quitter", menu.menuColor);
    menu.rQuit = {80, 200, 300, 100};
    menu.fondMenu = IMG_Load(MENU.c_str());

    ostringstream mssg;
    Uint8 *keystates = SDL_GetKeyState(NULL);

    Niveau niv;
    initNiveau(niv);

    while(!quit)
    {
        mssg.flush();
        SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,0,255,0));

        if(showmenu)
        {
            showMenu(menu, screen);
        }else
        {
            SDL_ShowCursor(0);
            SDL_BlitSurface(fondNiveau, NULL, screen, NULL);

            updateNiv(screen, duck, niv);

            SDL_BlitSurface(fondNiveauB, NULL, screen, NULL);

            SDL_BlitSurface(crossair, NULL, screen, &rCrossair);
            showBullet(nbAmmo, screen, bullet);

        }
        if(keystates[SDLK_SPACE])
            showmenu=false;
        if(keystates[SDLK_ESCAPE])
            quit=true;

        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                quit=true;
            }
            else if(event.type == SDL_MOUSEMOTION)
            {
                int x = event.button.x;
                int y = event.button.y;

                if(!showmenu)
                {
                    rCrossair = {x, y, 30, 30};
                }
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = event.button.x;
                int y = event.button.y;

                if(showmenu)
                {
                    if(onRect(x, y, menu.rjouer)){
                        showmenu = false;
                    }
                    if(onRect(x, y, menu.rQuit)){
                        quit = true;
                    }
                }else{
                    if(nbAmmo > 0){
                        nbAmmo--;
                        if(onRect(x, y, niv.cNoir.rect)){
                            niv.cNoir.isDead = true;
                        }else if(onRect(x, y, niv.cMarron.rect)){
                            niv.cMarron.isDead = true;
                        }else if(onRect(x, y, niv.cBleu.rect)){
                            niv.cBleu.isDead = true;
                        }
                    }
                }
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
