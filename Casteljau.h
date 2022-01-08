/*!
 *\file Casteljau.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#ifndef Casteljau_h
#define Casteljau_h
#include "R2.h"
/*!
 * \class {Casteljau}
 * \brief {Classe pour obtenir la valeur de la courbe de Bézier dans un point en utilisant l'algorithme de Casteljau.}
 */
class Casteljau: public R2{
protected:
    int size_;  /*!< Taille du objet*/
    R2 *data_;  /*!< Objet d'éléments R2*/
public:
    /*!
     *\fn Casteljau(int size)
     * \brief {Constructeur}
     * \param[in] size Premier élément
     */
    Casteljau(int size);
    /*!
     *\fn ~Casteljau()
     * \brief {Destructeur}
     */
    ~Casteljau();
    /*!
     *\fn Casteljau(const Casteljau & v)
     * \brief {Constructeur de copie}
     * \param[in] v Élément Casteljau à copier
     */
    Casteljau(const Casteljau & v);
    /*!
     *\fn R2& operator[](int l)
     * \brief {Écriture d'un élément du objet}
     * \param[in] l Position du élément dans l'objet
     */
    R2& operator[](int l){return data_[l];}
    /*!
     *\fn R2 operator[](int l)
     * \brief {Lecture de chaque élément du objet}
     * \param[in] l Position du élément dans l'objet
     */
    R2 operator[](int l)const {return data_[l];}
    /*!
     *\fn int get_size()const
     * \brief {Obtention de la taille du objet}
     */
    int get_size()const{return size_;}
};
/*!
 *\fn R2 pointcourbe(Casteljau & T, const double t)
 * \brief {Calcul du point t de la courbe}
 * \param[in] T Objet de la classe Casteljau
 * \param[in] t Valeur de [0,1] pour lequelle on veut connaître le point de la courbe
 */
R2 pointcourbe(Casteljau & T, const double t);
#endif /* Casteljau_h */
