#include <cstdlib>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


void applySurface(int x, int y, SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, clip, destination, &offset);
}
void showMessageScreen(std::string message, int x, int y, TTF_Font *font, int fontSize,SDL_Color scoreColor, SDL_Surface* &screen)
{
    std::string mot = "";
    std::string space = " ";
    int i = 0,j;
    SDL_Surface *mes = NULL;

    j = message.find(space);
    while(j != std::string::npos)
    {
        mot = message.substr(i, j - i);
        if(mot != "")
        {
            mes = TTF_RenderText_Solid(font,mot.c_str(),scoreColor);
            applySurface(x, y, mes, screen, NULL);
            x += mes -> w;
            SDL_FreeSurface(mes);
        }
        x += fontSize;
        i = j + 1;
        j = message.find(space, i);
    }

    mot = message.substr(i);
    mes = TTF_RenderText_Solid(font, mot.c_str(), scoreColor);
    applySurface(x, y, mes, screen, NULL);
    SDL_FreeSurface(mes);
}
