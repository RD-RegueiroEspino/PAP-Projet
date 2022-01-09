/*!
 *\file main.cpp
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#include <iostream>
#include "AffichageSDL.h"


int main()
{
    int width;
    int heigth;
    int x;
    char lettre;
    std::cout<<"Introduce the width (recommended 40): "<<std::endl;
    std::cin>>width;
    std::cout<<"Introduce the heigth (recommended 50): "<<std::endl;
    std::cin>>heigth;
    std::cout<<"Introduce the letter (capital letter): "<<std::endl;
    std::cin>>lettre;
    x=lettre;
    /*Bitmap table(width,heigth);
    selection(table,x); */
    std::cout<<x<<std::endl;

    AffichageSDL test;
    test.Dessine(x, width, heigth);

    return 0;
}
