/*!
 *\file Bitmap.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */

#ifndef Bitmap_h
#define Bitmap_h
#include <iostream>
#include "Remplisage.h"

class Bitmap{
protected:
    int width_;
    int heigth_;
    int **table_;
public:
    Bitmap(const int width,const int heigth);
    ~Bitmap();
    Bitmap(const Bitmap & v);
    int get_width() const {return width_;}
    int get_heigth() const {return heigth_;}
    //int& operator[](int i,int j){return table_[i[j]];}
   // int operator[](int i,int j)const {return table_[i[j]];}
    
    int get_p(const int i,const int j) const {return table_[i][j];}
    void set_p(const int i, const int j, const int l=1){table_[i][j]=l;}
    
    Bitmap & remplissage_point(const int auxx, const int auxy);
    Bitmap & contour_noir(const int auxx, const int auxy);
    Bitmap & contour_rouge();
    Bitmap & printLettre();
    void printBitmap();
};
void coloration(Bitmap & table,Remplisage T);
void printLettreA(Bitmap & table);
void printLettreB(Bitmap & table);
void printLettreC(Bitmap & table);
void printLettreD(Bitmap & table);
void printLettreE(Bitmap & table);
void printLettreF(Bitmap & table);
void printLettreG(Bitmap & table);
void printLettreH(Bitmap & table);
void printLettreY(Bitmap & table);
void printLettreJ(Bitmap & table);
void printLettreK(Bitmap & table);
void printLettreL(Bitmap & table);
void printLettreM(Bitmap & table);
void printLettreN(Bitmap & table);
void printLettreO(Bitmap & table);
void printLettreP(Bitmap & table);
void printLettreQ(Bitmap & table);
void printLettreR(Bitmap & table);
void printLettreS(Bitmap & table);
void printLettreT(Bitmap & table);
void printLettreU(Bitmap & table);
void printLettreV(Bitmap & table);
void printLettreW(Bitmap & table);
void printLettreX(Bitmap & table);
void printLettreY(Bitmap & table);
void printLettreZ(Bitmap & table);
void selection(Bitmap & table,int x=65);
#endif /* Bitmap_h */
