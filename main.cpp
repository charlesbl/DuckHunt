#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <ctime>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <affichage.h>
#include <niveau.h>

using namespace std;

const int SCREEN_WIDTH=750;
const int SCREEN_HEIGHT=761;
const int SCREEN_BPP=32;

//constantes
const string MENU = "menu.png";
const string NIVEAU = "backGame.png";
const string NIVEAUB = "backGameBlit.png";
const string CROSSAIR = "viseur.png";
const string BULLET = "shot.png";
const string DUCK = "duck.png";
const string HIT = "hit.png";
int nbAmmo = 3;
bool quit = false;
bool showmenu = true;


int main ()
{
    srand(time(NULL));

    SDL_Surface *screen, *fondNiveau, *fondNiveauB, *crossair, *bullet, *duck, *hit, *score, *levelName, *gameOver = NULL;
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
    hit = SDL_DisplayFormat(IMG_Load(HIT.c_str()));

    SDL_SetColorKey(bullet, SDL_SRCCOLORKEY, SDL_MapRGB(bullet->format, 255, 255, 255));
    SDL_SetColorKey(crossair, SDL_SRCCOLORKEY, SDL_MapRGB(crossair->format, 0, 0, 0));
    SDL_SetColorKey(fondNiveauB, SDL_SRCCOLORKEY, SDL_MapRGB(fondNiveauB->format, 0, 0, 0));
    SDL_SetColorKey(hit, SDL_SRCCOLORKEY, SDL_MapRGB(hit->format, 0, 0, 0));
    SDL_SetColorKey(duck, SDL_SRCCOLORKEY, SDL_MapRGB(duck->format, 228, 255, 0));

    TTF_Init();

    initMenu(menu);

    TTF_Font *scoreFonts;
    scoreFonts = TTF_OpenFont("duck_hunt.ttf", 25);

    TTF_Font *levelFonts;
    levelFonts = TTF_OpenFont("duck_hunt.ttf", 70);


    Uint8 *keystates = SDL_GetKeyState(NULL);

    Niveau niv;
    initNiveau(niv, 1, 0);

    while(!quit)
    {
        SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,0,255,0));

        if(showmenu)
        {
            SDL_ShowCursor(1);
            showMenu(menu, screen);
        }else
        {
            SDL_ShowCursor(0);
            SDL_BlitSurface(fondNiveau, NULL, screen, NULL);

            if(niv.start){
                showLevel(screen, levelName, levelFonts, niv);
            }else if(niv.perdu){
                showGameOver(screen, gameOver, levelFonts, niv);
            }else{
                updateNiv(screen, duck, niv);
            }

            SDL_BlitSurface(fondNiveauB, NULL, screen, NULL);

            SDL_BlitSurface(crossair, NULL, screen, &rCrossair);
            showBullet(nbAmmo, screen, bullet);
            showHit(screen, hit, niv.hit);

            showScore(screen, score, scoreFonts, niv.score);

        }
        if(keystates[SDLK_SPACE])
            showmenu=false;
        if(keystates[SDLK_ESCAPE])
            showmenu=true;

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

                if(showmenu)
                {
                    if(onRect(x, y, menu.rjouer)){
                        menu.sJouer = true;
                    }else if(onRect(x, y, menu.rQuit)){
                        menu.sQuit = true;
                    }else{
                        menu.sJouer = menu.sQuit = false;
                    }
                }else{
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
                    if(nbAmmo > 0 && !niv.start){
                        nbAmmo--;
                        if(onRect(x, y, niv.cNoir.rect)){
                            killCan(niv.cNoir, niv);
                        }else if(onRect(x, y, niv.cMarron.rect)){
                            killCan(niv.cMarron, niv);
                        }else if(onRect(x, y, niv.cBleu.rect)){
                            killCan(niv.cBleu, niv);
                        }
                    }
                }
            }
        }
        SDL_Flip(screen);
        SDL_Delay(10);
    }

    TTF_CloseFont(menu.menuFonts);
    TTF_Quit();

    SDL_FreeSurface(screen);
    SDL_Quit();

    return EXIT_SUCCESS;
}
