/*!
 *\file Casteljau.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 *
 */
//Calcul des points de la courbe de Bézier en utilisant l'algorithme de Casteljau

#ifndef Casteljau_h
#define Casteljau_h
#include "R2.h"

class Casteljau: public R2{
protected:
    int size_;
    R2 *data_;
public:
    Casteljau(int size);
    ~Casteljau();
    Casteljau(const Casteljau & v);
    
    R2& operator[](int l){return data_[l];}
    R2 operator[](int l)const {return data_[l];}
    
    int get_size()const{return size_;}
};

R2 pointcourbe(Casteljau & T, const double t);
#endif /* Casteljau_h */
