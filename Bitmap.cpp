/*!
 *\file Bitmap.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#include "Bitmap.h"
#include <stdio.h>
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
    int j=(int)(get_width()/14)-1;
    int k=(int)(get_heigth()/14)-1;
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

/*!
 *On sait que les lettres ne van utiliser les coins du Bitmap. Donc, pour favoriser l'optimisation, on ne considerara ces points.
 *Sinon, il suffira de changer le code en vérifiant aussy l'hypothèse de que le point considérée est dans le Bitmap.
 */
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
