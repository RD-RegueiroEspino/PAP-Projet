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
    int get_width() const {return width_;}
    int get_heigth() const {return heigth_;}
    //int& operator[](int i,int j){return table_[i[j]];}
   // int operator[](int i,int j)const {return table_[i[j]];}
    
    int get_p(const int i,const int j) const {return table_[i][j];}
    void set_p(const int i, const int j, const int l=1){table_[i][j]=l;}
    
    Bitmap & remplissage_point(const int auxx, const int auxy);
    Bitmap & contour_noir(const int auxx, const int auxy);
    Bitmap & contour_rouge();
    
    void printBitmap();
};
void coloration(Bitmap & table,Remplisage T);

#endif /* Bitmap_h */
