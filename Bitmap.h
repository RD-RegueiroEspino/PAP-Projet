/*!
 *\file Bitmap.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */

#ifndef Bitmap_h
#define Bitmap_h
#include <iostream>
#include "Remplissage.h"

class Bitmap{
protected:
    int width_;/*!< Largueur du bitmap*/
    int heigth_;/*!< Hauteur du bitmap*/
    int **table_;/*!<Objet pour représenter le bitmap*/
public:
    /*!
     *\fn Bitmap(const int width,const int heigth)
     *\brief {Constructeur}
     *\param[in] width Largueur du bitmap
     *\param[in] heigth Hauteur du bitmap
     */
    Bitmap(const int width,const int heigth);
    /*!
     *\fn Bitmap()
     *\brief {Destructeur}
     */
    ~Bitmap();
    /*!
     *\fn Bitmap(const Bitmap & v)
     *\brief {Constructeur de copie}
     *\param[in] v Objet à copier
     */
    Bitmap(const Bitmap & v);
    /*!
     *\fn int get_width() const
     *\brief {Obtention de la largueur du bitmap}
     */
    int get_width() const {return width_;}
    /*!
     *\fn Bitmap(const Bitmap & v)
     *\brief {Obtention de l'hauteur du bitmap}
     */
    int get_heigth() const {return heigth_;}
    /*!
     *\fn int get_p(const int i,const int j) const
     *\brief {Obtention du valeur [ i ] [ j ] du objet}
     *\param[in] i Premier paramétre a considérer dans l'objet
     *\param[in] j Deuxième paramétre a considérer dans l'objet
     */
    int get_p(const int i,const int j) const {return table_[i][j];}
    /*!
     *\fn void set_p(const int i, const int j, const int l=1)
     *\brief {Changer le valeur [ i ] [ j ] du objet}
     *\param[in] i Premier paramétre a considérer dans l'objet
     *\param[in] j Deuxième paramétre a considérer dans l'objet
     *\param[in] l Valeur à introduir dans l'objet
     */
    void set_p(const int i, const int j, const int l=1){table_[i][j]=l;}
    /*!
     *\fn Bitmap & remplissage_point(const int auxx, const int auxy)
     *\brief {Remplissage du bitmap}
     *\param[in] auxx Premier paramètre du objet
     *\param[in] auxy Deuxième paramètre du objet
     */
    Bitmap & remplissage_point(const int auxx, const int auxy);
    /*!
     *\fn Bitmap & contour_noir(const int auxx, const int auxy)
     *\brief {Obtention du contour du bitmap}
     *\param[in] auxx Premier paramètre du objet
     *\param[in] auxy Deuxième paramètre du objet
     */
    Bitmap & contour_noir(const int auxx, const int auxy);
    /*!
     *\fn Bitmap & contour_rouge()
     *\brief {Ajouter le contour rouge}
     */
    Bitmap & contour_rouge();
    /*!
     *\fn void printBitmap()
     *\brief {Montrer dans l'écran l'objet}
     */
    void printBitmap();
};
/*!
 *\fn void coloration(Bitmap & table,Remplissage T)
 *\brief {Ajouter la lettre au bitmap}
 *\param[in] table Bitmap
 *\param[in] T Valeurs de la courbe
 */
void coloration(Bitmap & table,Remplissage T);
void printLettreA(Bitmap & table);
void printLettreB(Bitmap & table);
void printLettreC(Bitmap & table);
void printLettreD(Bitmap & table);
void printLettreE(Bitmap & table);
void printLettreF(Bitmap & table);
void printLettreG(Bitmap & table);
void printLettreH(Bitmap & table);
void printLettreY(Bitmap & table);
void printLettreJ(Bitmap & table);
void printLettreK(Bitmap & table);
void printLettreL(Bitmap & table);
void printLettreM(Bitmap & table);
void printLettreN(Bitmap & table);
void printLettreO(Bitmap & table);
void printLettreP(Bitmap & table);
void printLettreQ(Bitmap & table);
void printLettreR(Bitmap & table);
void printLettreS(Bitmap & table);
void printLettreT(Bitmap & table);
void printLettreU(Bitmap & table);
void printLettreV(Bitmap & table);
void printLettreW(Bitmap & table);
void printLettreX(Bitmap & table);
void printLettreY(Bitmap & table);
void printLettreZ(Bitmap & table);
void selection(Bitmap & table,int x=65);
#endif /* Bitmap_h */
