/*!
 *\file main.cpp
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#include <iostream>
#include "R2.h"
#include "Casteljau.h"
#include "Bitmap.h"
#include "Remplisage.h"
//#include "Lettre.h"
//#include "auxsdl.h"

int main()
{
    int width;
    int heigth;
    int x;
    char lettre;
    std::cout<<"Introduce the width: "<<std::endl;
    std::cin>>width;
    std::cout<<"Introduce the heigth: "<<std::endl;
    std::cin>>heigth;
    std::cout<<"Introduce the letter: "<<std::endl;
    std::cin>>lettre;
    x=lettre;
    Bitmap table(width,heigth);
    selection(table,x);
    std::cout<<x<<std::endl;
    return 0;
}
