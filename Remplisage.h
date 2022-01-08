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
    int size_;/*!< Taille du objet*/
    R2 *donnes_;/*!< Objet d'éléments R2*/
public:
    /*!
     *\fn Remplisage(int size)
     * \brief {Constructeur}
     * \param[in] size Taille du objet à créer
     */
    Remplisage(int size);
    /*!
     *\fn ~Remplisage()
     * \brief {Destructeur}
     */
    ~Remplisage();
    /*!
     *\fn Remplisage(const Remplisage& copy)
     * \brief {Constructeur de copie}
     * \param[in] copy Objet à copier
     */
    Remplisage(const Remplisage& copy);
    /*!
     *\fn R2& operator[](int l)const
     * \brief {Écriture d'un élément du objet}
     * \param[in] l Position du élément dans l'objet
     */
    R2& operator[](int l){return donnes_[l];}
    /*!
     *\fn R2 operator[](int l)const
     * \brief {Lecture de chaque élément du objet}
     * \param[in] l Position du élément dans l'objet
     */
    R2 operator[](int l)const {return donnes_[l];}
    /*!
     *\fn int get_size()const
     * \brief {Obtention de la taille du objet}
     */
    int get_size()const{return size_;}
};
/*!
 *\fn void Calcul(Casteljau E, Remplisage & T)
 * \brief {Calcul des valeurs dans la courbe des points du objet}
 * \param[in] E Points de côntrol de la courbe
 * \param[in] T Points à calculer

 */
void Calcul(Casteljau E, Remplisage & T);
#endif /* Remplisage_h */
