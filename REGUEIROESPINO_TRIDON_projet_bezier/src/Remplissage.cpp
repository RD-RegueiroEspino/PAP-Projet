/*!
 *\file Remplisage.cpp
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#include <stdio.h>
#include "Remplissage.h"
Remplissage::Remplissage(int size){
    if (size<=0) {
        throw "Wrong size";
    }
    size_=size;
    donnes_=new R2[size];
}
Remplissage::Remplissage(const Remplissage & copy) {
    size_=copy.size_;
    donnes_ = new R2[copy.size_];
    if (donnes_)
        for (int i = 0; i < size_; i++)
            donnes_[i] = copy.donnes_[i];
    else
        throw std::runtime_error("Error when allocating memory for vector data.");
}
Remplissage::~Remplissage(){
    delete [] donnes_;
}
void Calcul(Casteljau E, Remplissage & T) {
    int size=T.get_size();
    T[0]=E[0];
    T[size-1]=E[1];
    for (int i=1;i<size;i++){
        T[i]=pointcourbe(E,i/(double)size);
    }
}
