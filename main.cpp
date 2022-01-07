/*!
 *\file main.cpp
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 *
 */
#include <iostream>
#include "R2.h"
#include "Casteljau.h"
#include "Bitmap.h"
#include "Remplisage.h"
//#include "Remplisage.h"
//#include "auxsdl.h"

int main()
{
    std::cout<<"Bitmap: "<<std::endl;
    int width=40;
    int heigth=50;
    //Lettre E
    Bitmap table(width,heigth);
    int size=std::max(width,heigth);
    Remplisage T(size);
    R2 aux;
    /*
    int auxx;
    int auxy;
     */
    Casteljau E1(2);
    Casteljau E2(2);
    Casteljau E3(2);
    Casteljau E4(2);
    E1[0]=R2(0.15,0.3);
    E1[1]=R2(0.85,0.3);
    E2[0]=E1[0];
    E2[1]=R2(0.15,0.7);
    E3[0]=E1[1];
    E3[1]=R2(0.85,0.7);
    E4[0]=R2(0.5,0.3);
    E4[1]=R2(0.5,0.5);
    Calcul(E1,T);
    coloration(table,T);
    Calcul(E2,T);
    coloration(table,T);
    Calcul(E3,T);
    coloration(table,T);
    Calcul(E4,T);
    coloration(table,T);
    
   table.printBitmap();
    return 0;
}
