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
{
    std::cout<<"Bitmap: "<<std::endl;
    int width=40;
    int heigth=50;
    //Lettre A
    Bitmap table(width,heigth);
    int size=std::max(width,heigth);
    R2 T[size];
    R2 aux;
    int auxx;
    int auxy;
    Casteljau A1(2);
    Casteljau A2(2);
    Casteljau A3(2);
    A1[0]=R2(0.15,0.5);
    A1[1]=R2(0.8,0.8);
    A2[0]=A1[0];
    A2[1]=R2(0.8,0.2);
    A3[0]=R2(0.5,0.65);
    A3[1]=R2(0.5,0.35);
    
    T[0]=A1[0];
    T[size-1]=A1[1];
    for (int i=1;i<size;i++){
        T[i]=pointcourbe(A1,i/(double)size);
    }
    for (int i=0;i<size;i++){
        aux=T[i];
        auxx=int(width*aux.get_y1());
        auxy=int(heigth*aux.get_y2());
        table.remplissage_point(auxx,auxy);
    }
    T[0]=A2[0];
    T[size-1]=A2[1];
    for (int i=1;i<size;i++){
        T[i]=pointcourbe(A2,i/(double)size);
    }
    for (int i=0;i<size;i++){
        aux=T[i];
        auxx=int(width*aux.get_y1());
        auxy=int(heigth*aux.get_y2());
        table.remplissage_point(auxx,auxy);
    }
    T[0]=A3[0];
    T[size-1]=A3[1];
    for (int i=1;i<size;i++){
        T[i]=pointcourbe(A3,i/(double)size);
    }
    for (int i=0;i<size;i++){
        aux=T[i];
        auxx=int(width*aux.get_y1());
        auxy=int(heigth*aux.get_y2());
        table.remplissage_point(auxx,auxy);
    }
   table.printBitmap();
    return 0;
}
