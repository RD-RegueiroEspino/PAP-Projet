/*!
 *\file main.cpp
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 *
 */
#include <iostream>
#include "R2.h"
#include "Casteljau.h"
#include "Bitmap.h"
//#include "Remplisage.h"
//#include "auxsdl.h"

int main()
{//Lettre A
    std::cout<<"Bitmap de C: "<<std::endl;
        Casteljau proba(3);
        proba[0]=R2(0.2,0.6);
        proba[1]=R2(0.5,0.1);
        proba[2]=R2(0.8,0.6);
        int size=40;
        R2 T[size];
        T[0]=proba[0];
        T[size-1]=proba[2];
        for (int i=1;i<size;i++){
            T[i]=pointcourbe(proba,i/(double)size);
        }
        int width=50;
        int heigth=50;
    Bitmap table(width,heigth);
    R2 aux;
    int auxx;
    int auxy;
    for (int i=0;i<size;i++){
        aux=T[i];
        auxx=int(width*aux.get_y1());
        auxy=int(heigth*aux.get_y2());
        //Intérieur
        table.remplissage(auxx,auxy);
    }
    table.contour();
    table.printBitmap();
    
    return 0;
}
