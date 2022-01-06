/*!
 *\file auxsdl.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 *
 */

#ifndef auxsdl_h
#define auxsdl_h
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
class auxsdl{
private:
    int width_;
    int heigth_;
public:
    auxsdl(int i){donnes_=i;}
    
};

SDL_Window ∗win = SDL_CreateWindow ("Bitmap",
SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    width ,heigth,SDL_WINDOW_OPENGL);
SDL_Renderer ∗ren = SDL_CreateRenderer(win,−1,0);
SDL_SetRenderDrawColor (ren,0,0,0,SDL_ALPHA_OPAQUE);
//figure
SDL_RenderClear(ren);
SDL_RenderPresent (ren);
SDL_Quit ( );

#endif /* auxsdl_h */
