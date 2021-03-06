/*!
 *\file Remplissage.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#ifndef Remplissage_h
#define Remplissage_h
#include "Casteljau.h"
#include <vector>
/*!
 * \class {Remplissage}
 * \brief {Classe pour obtenir la valeur de la courbe de Bézier dans l'ensemble de points considerés.}
 */
class Remplissage{
private:
    int size_;/*!< Taille de l'objet*/
    R2 *donnes_;/*!< Objet d'éléments R2*/
public:
    /*!
     *\fn Remplisage(int size)
     * \brief {Constructeur}
     * \param[in] size Taille de l'objet à créer
     */
    Remplissage(int size);
    /*!
     *\fn ~Remplisage()
     * \brief {Destructeur}
     */
    ~Remplissage();
    /*!
     *\fn Remplisage(const Remplisage& copy)
     * \brief {Constructeur de copie}
     * \param[in] copy Objet à copier
     */
    Remplissage(const Remplissage& copy);
    /*!
     *\fn R2& operator[](int l)const
     * \brief {Écriture d'un élément de l'objet}
     * \param[in] l Position de l'élément dans l'objet
     */
    R2& operator[](int l){return donnes_[l];}
    /*!
     *\fn R2 operator[](int l)const
     * \brief {Lecture de chaque élément de l'objet}
     * \param[in] l Position de l'élément dans l'objet
     */
    R2 operator[](int l)const {return donnes_[l];}
    /*!
     *\fn int get_size()const
     * \brief {Obtention de la taille de l'objet}
     */
    int get_size()const{return size_;}
};
/*!
 *\fn void Calcul(Casteljau E, Remplisage & T)
 * \brief {Calcul des valeurs dans la courbe des points de l'objet}
 * \param[in] E Points de contrôle de la courbe
 * \param[in] T Points à calculer

 */
void Calcul(Casteljau E, Remplissage & T);
#endif /* Remplissage_h */
