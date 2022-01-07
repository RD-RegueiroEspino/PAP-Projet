/*!
 *\file Remplisage.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 *
 */
#ifndef Remplisage_h
#define Remplisage_h
#include "Casteljau.h"
#include <vector>

/*Pour l'algorithme, il faut inclure un critère d'arrêt. On doit prendre en compte la taille du Bitmap.
Premier option: nombre maximum de points
Deuxième option: distance entre t

 Pour moi: chaque fois on peut considérer des t distincts, t/2 par exemple.
 Problème d'affichage: comme on sait les points qu'on a considére?
*/

class Remplisage{
private:
    int size_;
    R2 *donnes_;
public:
    Remplisage(int size);
    ~Remplisage();
    Remplisage(const Remplisage& copy);
    
    R2& operator[](int l){return donnes_[l];}
    R2 operator[](int l)const {return donnes_[l];}
    
    int get_size()const{return size_;}
    void Calcul(Casteljau E, Remplisage & T);
};

Remplisage::Remplisage(int size){
    if (size<=0) {
        throw "Wrong size";
    }
    size_=size;
    donnes_=new R2[size];
}
Remplisage::Remplisage(const Remplisage & copy) {
    size_=copy.size_;
    donnes_ = new R2[copy.size_];
    if (donnes_)
        for (int i = 0; i < size_; i++)
            donnes_[i] = copy.donnes_[i];
    else
        throw std::runtime_error("Error when allocating memory for vector data.");
}
Remplisage::~Remplisage(){
    delete [] donnes_;
}


void Calcul(Casteljau E, Remplisage & T) {
    int size=T.get_size();
    T[0]=E[0];
    T[size-1]=E[1];
    for (int i=1;i<size;i++){
        T[i]=pointcourbe(E,i/(double)size);
    }
}
/*
//Algorithme pour le remplisage:
int l=1;
int k=1;
while (l<10){
double T[k];
    for (int m=0;m<l;m++){
        T[m]=(2*m-1)/k;
    }
//Call to function
l+=1;
k=2*k;
}
//std::cout<<T<<std::endl;
 */

#endif /* Remplisage_h */
