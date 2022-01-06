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

class Remplisage: public R2{
public:
    Remplisage(){}
    ~Remplisage(){}
    
    R2& operator[](int l){return data_[l];}
    R2 operator[](int l)const {return data_[l];}
};


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
