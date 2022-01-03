/*!
 *\file main.cpp
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 *
 */
#include <iostream>
#include "R2.h"
#include "Casteljau.h"
#include "Bitmap.h"
#include "auxsdl.h"

/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include "SDL2/SDL.h"


int main(int argc, char ** argv)
{
    bool quit = false;
    SDL_Event event;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    SDL_Window * window = SDL_CreateWindow("SDL2 Displaying Image",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
 
    while (!quit)
    {
        SDL_WaitEvent(&event);
 
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }
    }
 
    SDL_Quit();
 
    return 0;
}
