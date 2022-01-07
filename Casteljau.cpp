/*!
 *\file Casteljau.cpp
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */

#include <stdio.h>
#include "Casteljau.h"

Casteljau::Casteljau(int size){
    if (size<=0) {
        throw "Wrong size";
    }
    size_=size;
    data_=new R2[size];
}
Casteljau::~Casteljau(){
    delete [] data_;
}
Casteljau::Casteljau(const Casteljau & v){
    size_=v.get_size();
    data_=new R2[size_];
    for (int i=0; i < v.get_size(); i++){
        data_[i]=v[i];
    }
}

 //Point t de la courbe de Bézier:
R2 pointcourbe(Casteljau & T, const double t){
    if (t<0 || t>1) throw "Wrong value";
    Casteljau L=T;
    R2 aux;
    for (int j=1;j<T.get_size();j++){
        for (int i=0;i<T.get_size()-j;i++){
            aux=L[i];
            L[i]=(1-t)*aux+t*L[i+1];
        }
    }
    return L[0];
 }
