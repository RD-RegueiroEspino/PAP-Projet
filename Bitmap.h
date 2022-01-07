/*!
 *\file Bitmap.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 *
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
    void printBitmap();
    
    int get_p(const int i,const int j) const {return table_[i][j];}
    void set_p(const int i, const int j, const int l=1){table_[i][j]=l;}
    
    Bitmap & remplissage_point(const int auxx, const int auxy);
    Bitmap & contour_noir(const int auxx, const int auxy);
    Bitmap & contour_rouge();
    
    void coloration(Bitmap & table,Remplisage T);
};

void Bitmap::printBitmap(){
    for (int i=0;i<get_width();i++){
        std::cout<<"[";
        for (int j=0;j<get_heigth();j++){
            std::cout<<table_[i][j]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
}

Bitmap::Bitmap(const int width,const int heigth){
    if (width<=0 || heigth <=0){
        throw "Bad size of the Bitmap";
    }
    width_=width;
    heigth_=heigth;
    table_=new int*[width];
    for (int i=0;i<width;i++){
        table_[i]=new int[heigth];
        for (int j=0;j<heigth;j++){
            table_[i][j]=0;
        }
    }
}
Bitmap::~Bitmap(){
    delete[] table_;
}
/*
void Bitmap::printBitmap(){
    for (int i=0;i<get_width();i++){
        std::cout<<"[";
        for (int j=0;j<get_heigth();j++){
            std::cout<<table_[i][j]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
}
 */
Bitmap & Bitmap::remplissage_point(const int auxx, const int auxy){
    for (int j=0;j<(int)get_width()/14;j++){
        for (int k=0;k<(int)get_heigth()/14;k++){
            (*this).set_p(auxx-j,auxy);
            (*this).set_p(auxx+j,auxy);
            (*this).set_p(auxx,auxy-k);
            (*this).set_p(auxx,auxy+k);
            (*this).set_p(auxx+j,auxy+k);
            (*this).set_p(auxx-j,auxy+k);
            (*this).set_p(auxx+j,auxy-k);
            (*this).set_p(auxx-j,auxy-k);
        }
    }
    return *this;
}
//Ce contour n'est pas bon
Bitmap & Bitmap::contour_noir(const int auxx, const int auxy){
    int j=(int)(get_width()/12)-1;
    int k=(int)(get_heigth()/12)-1;
    (*this).set_p(auxx,auxy);
    (*this).set_p(auxx,auxy-k);
    (*this).set_p(auxx+j,auxy);
    (*this).set_p(auxx-j,auxy);
    (*this).set_p(auxx-j,auxy+k);
    (*this).set_p(auxx-j,auxy-k);
    (*this).set_p(auxx+j,auxy+k);
    (*this).set_p(auxx+j,auxy-k);
    return *this;
}

//On sait que les lettres ne van utiliser les coins du Bitmap. Donc, pour favoriser l'optimisation, on ne considerara ces points.
//Sinon, il suffira de changer le code en vérifiant aussy l'hypothèse de que le point considérée est dans le Bitmap.
Bitmap & Bitmap::contour_rouge(){
    for (int i=2;i<get_width()-2;i++){
        for (int j=2;j<get_heigth()-2;j++){
            if ((*this).get_p(i,j)==1){
                for (int k=1;k<3;k++){
                    if ((*this).get_p(i+k,j)==0){
                        (*this).set_p(i+k,j,2);
                    }
                    if ((*this).get_p(i,j+k)==0){
                        (*this).set_p(i,j+k,2);
                    }
                }
                for (int k=1;k<3;k++){
                    if ((*this).get_p(i-k,j)==0){
                        (*this).set_p(i-k,j,2);
                    }
                    if ((*this).get_p(i,j-k)==0){
                        (*this).set_p(i,j-k,2);
                    }
                }
            }
        }
    }
    return *this;
}
/*
void Remplisage(int width,int heigth, R2 T[int size]){
    Bitmap table(width,heigth);
    R2 aux;
    int auxx;
    int auxy;
    for (int i=0;i<size;i++){
        aux=T[i];
        auxx=int(width*aux.get_y1());
        auxy=int(heigth*aux.get_y2());
        table.set_p(auxx,auxy);
        //Ici on doit moduler avec un boucle
        for (int j=1;j<(int)width/10;j++){
            table.set_p(auxx-j,auxy);
            table.set_p(auxx+j,auxy);
        }
        for (int j=1;j<(int)heigth/10;j++){
            table.set_p(auxx,auxy-1);
            table.set_p(auxx,auxy+1);
        }
    }
    table.printBitmap();
}
*/
void coloration(Bitmap & table,Remplisage T){
    R2 aux;
    int auxx;
    int auxy;
    for (int i=0;i<T.get_size();i++){
        aux=T[i];
        auxx=int(table.get_width()*(aux.get_y1()));
        auxy=int(table.get_heigth()*(aux.get_y2()));
        table.remplissage_point(auxx,auxy);
    }
}
/*
Bitmap & Bitmap::coloration(Remplisage T){
    int auxx;
    int auxy;
    for (int i=0;i<T.get_size();i++){
        auxx=int((*this).get_width()*(T[i].get_y1()));
        auxy=int((*this).get_heigth()*(T[i].get_y2()));
        (*this).remplissage_point(auxx,auxy);
    }
    return *this;
}
 */
#endif /* Bitmap_h */
