/*!
 *\file Remplisage.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#ifndef Remplisage_h
#define Remplisage_h
#include "Casteljau.h"
#include <vector>
/*!
 * \class {Remplisage}
 * \brief {Classe pour obtenir la valeur de la courbe de Bézier dans l'ensemble de points considerés.}
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
};
/*!
 * \brief {Calcul de l'ensemble des points considérés à partir des points initials}
 */
void Calcul(Casteljau E, Remplisage & T);
#endif /* Remplisage_h */
