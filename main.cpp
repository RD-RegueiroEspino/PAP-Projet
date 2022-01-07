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
    Casteljau S1(3);
    Casteljau S2(3);
    Casteljau S3(2);
    S1[0]=R2(0.15,0.7);
    S1[1]=R2(0.3,0.05);
    S1[2]=R2(0.45,0.4);
    S2[0]=R2(0.55,0.6);
    S2[1]=R2(0.7,0.95);
    S2[2]=R2(0.85,0.3);
    S3[0]=S1[2];
    S3[1]=S2[0];
    Calcul(S1,T);
    coloration(table,T);
    Calcul(S2,T);
    coloration(table,T);
    Calcul(S3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
    return 0;
}
