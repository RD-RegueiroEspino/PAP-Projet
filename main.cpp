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
int main() {
    std::cout<<"Preuve de R2: "<<std::endl;
    R2 v(5.3,2.1);
    R2 w=(3.1);
    std::cout<<v+w<<std::endl;
    std::cout<<2*v<<std::endl;

    Casteljau proba(3);
    proba[0]=R2(1,0);
    proba[1]=R2(0,1);
    proba[2]=R2(1,2);
    std::cout<<"Preuve du algorithme de Casteljau: "<<std::endl;
    w=pointcourbe(proba,0.7);
    std::cout<<w<<std::endl;
    
    std::cout<<"Preuve du Bitmap: "<<std::endl;
    Bitmap table(4,4);
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (i==j) table.set_p(i,j);
        }
    }
    table.printBitmap();
    
    /*
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            printf("error initializing SDL: %s\n", SDL_GetError());
        }
        SDL_Window* win = SDL_CreateWindow("GAME",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           1000, 1000, 0);
        while (1)
            ;
     */
    return 0;
}
