/*!
 *\file main.cpp
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#include <iostream>
#include "R2.h"
#include "Casteljau.h"
#include "Bitmap.h"
#include "Remplisage.h"
//#include "auxsdl.h"

int main()
{
    std::cout<<"Bitmap: "<<std::endl;
    int width=40;
    int heigth=50;
    Bitmap table(width,heigth);
    int size=std::max(width,heigth);
    Remplisage T(size);
    //Lettre I
        Casteljau I1(2);
        Casteljau I2(2);
        Casteljau I3(2);
        I1[0]=R2(0.15,0.3);
        I1[1]=R2(0.15,0.7);
        I2[0]=R2(0.15,0.5);
        I2[1]=R2(0.85,0.5);
        I3[0]=R2(0.85,0.3);
        I3[1]=R2(0.85,0.7);
        Calcul(I1,T);
        coloration(table,T);
        Calcul(I2,T);
        coloration(table,T);
        Calcul(I3,T);
        coloration(table,T);
        table.contour_rouge();
        table.printBitmap();
    return 0;
}
