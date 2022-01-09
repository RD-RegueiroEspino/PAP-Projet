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
     *\brief {Obtention de la largeur du bitmap}
     */
    int get_width() const {return width_;}
    /*!
     *\fn Bitmap(const Bitmap & v)
     *\brief {Obtention de la hauteur du bitmap}
     */
     int** get_table() const {return table_;}
    /*!
     *\fn Bitmap(const Bitmap & v)
     *\brief {Obtention de la table du bitmap}
     */
    int get_heigth() const {return heigth_;}
    /*!
     *\fn int get_p(const int i,const int j) const
     *\brief {Obtention du valeur [ i ] [ j ] de l'objet}
     *\param[in] i Premier paramètre à considérer dans l'objet
     *\param[in] j Deuxième paramètre à considérer dans l'objet
     */
    int get_p(const int i,const int j) const {return table_[i][j];}
    /*!
     *\fn void set_p(const int i, const int j, const int l=1)
     *\brief {Changer le valeur [ i ] [ j ] de l'objet}
     *\param[in] i Premier paramètre à considérer dans l'objet
     *\param[in] j Deuxième paramètre à considérer dans l'objet
     *\param[in] l Valeur à introduir dans l'objet
     */
    void set_p(const int i, const int j, const int l=1){table_[i][j]=l;}
    /*!
     *\fn Bitmap & remplissage_point(const int auxx, const int auxy)
     *\brief {Remplissage du bitmap}
     *\param[in] auxx Premier paramètre de l'objet
     *\param[in] auxy Deuxième paramètre de l'objet
     */
    Bitmap & remplissage_point(const int auxx, const int auxy);
    /*!
     *\fn Bitmap & contour_rouge()
     *\brief {Ajouter le contour rouge}
     */
    Bitmap & contour_rouge();
    /*!
     *\fn void printBitmap()
     *\brief {Montrer l'objet à l'écran }
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
/*!
 *\fn void printLettreA(Bitmap & table)
 *\brief {Ajouter la lettre A au bitmap}
 *\param[in] table Bitmap
 */
void printLettreA(Bitmap & table);
/*!
 *\fn void printLettreB(Bitmap & table)
 *\brief {Ajouter la lettre B au bitmap}
 *\param[in] table Bitmap
 */
void printLettreB(Bitmap & table);
/*!
 *\fn void printLettreC(Bitmap & table)
 *\brief {Ajouter la lettre C au bitmap}
 *\param[in] table Bitmap
 */
void printLettreC(Bitmap & table);
/*!
 *\fn void printLettreD(Bitmap & table)
 *\brief {Ajouter la lettre D au bitmap}
 *\param[in] table Bitmap
 */
void printLettreD(Bitmap & table);
/*!
 *\fn void printLettreE(Bitmap & table)
 *\brief {Ajouter la lettre E au bitmap}
 *\param[in] table Bitmap
 */
void printLettreE(Bitmap & table);
/*!
 *\fn void printLettreF(Bitmap & table)
 *\brief {Ajouter la lettre F au bitmap}
 *\param[in] table Bitmap
 */
void printLettreF(Bitmap & table);
/*!
 *\fn void printLettreG(Bitmap & table)
 *\brief {Ajouter la lettre G au bitmap}
 *\param[in] table Bitmap
 */
void printLettreG(Bitmap & table);
/*!
 *\fn void printLettreH(Bitmap & table)
 *\brief {Ajouter la lettre H au bitmap}
 *\param[in] table Bitmap
 */
void printLettreH(Bitmap & table);
/*!
 *\fn void printLettreI(Bitmap & table)
 *\brief {Ajouter la lettre I au bitmap}
 *\param[in] table Bitmap
 */
void printLettreI(Bitmap & table);
/*!
 *\fn void printLettreJ(Bitmap & table)
 *\brief {Ajouter la lettre J au bitmap}
 *\param[in] table Bitmap
 */
void printLettreJ(Bitmap & table);
/*!
 *\fn void printLettreK(Bitmap & table)
 *\brief {Ajouter la lettre K au bitmap}
 *\param[in] table Bitmap
 */
void printLettreK(Bitmap & table);
/*!
 *\fn void printLettreL(Bitmap & table)
 *\brief {Ajouter la lettre L au bitmap}
 *\param[in] table Bitmap
 */
void printLettreL(Bitmap & table);
/*!
 *\fn void printLettreM(Bitmap & table)
 *\brief {Ajouter la lettre M au bitmap}
 *\param[in] table Bitmap
 */
void printLettreM(Bitmap & table);
/*!
 *\fn void printLettreN(Bitmap & table)
 *\brief {Ajouter la lettre N au bitmap}
 *\param[in] table Bitmap
 */
void printLettreN(Bitmap & table);
/*!
 *\fn void printLettreO(Bitmap & table)
 *\brief {Ajouter la lettre O au bitmap}
 *\param[in] table Bitmap
 */
void printLettreO(Bitmap & table);
/*!
 *\fn void printLettreP(Bitmap & table)
 *\brief {Ajouter la lettre P au bitmap}
 *\param[in] table Bitmap
 */
void printLettreP(Bitmap & table);
/*!
 *\fn void printLettreQ(Bitmap & table)
 *\brief {Ajouter la lettre Q au bitmap}
 *\param[in] table Bitmap
 */
void printLettreQ(Bitmap & table);
/*!
 *\fn void printLettreR(Bitmap & table)
 *\brief {Ajouter la lettre R au bitmap}
 *\param[in] table Bitmap
 */
void printLettreR(Bitmap & table);
/*!
 *\fn void printLettreS(Bitmap & table)
 *\brief {Ajouter la lettre S au bitmap}
 *\param[in] table Bitmap
 */
void printLettreS(Bitmap & table);
/*!
 *\fn void printLettreT(Bitmap & table)
 *\brief {Ajouter la lettre T au bitmap}
 *\param[in] table Bitmap
 */
void printLettreT(Bitmap & table);
/*!
 *\fn void printLettreU(Bitmap & table)
 *\brief {Ajouter la lettre U au bitmap}
 *\param[in] table Bitmap
 */
void printLettreU(Bitmap & table);
/*!
 *\fn void printLettreV(Bitmap & table)
 *\brief {Ajouter la lettre V au bitmap}
 *\param[in] table Bitmap
 */
void printLettreV(Bitmap & table);
/*!
 *\fn void printLettreW(Bitmap & table)
 *\brief {Ajouter la lettre W au bitmap}
 *\param[in] table Bitmap
 */
void printLettreW(Bitmap & table);
/*!
 *\fn void printLettreX(Bitmap & table)
 *\brief {Ajouter la lettre X au bitmap}
 *\param[in] table Bitmap
 */
void printLettreX(Bitmap & table);
/*!
 *\fn void printLettreY(Bitmap & table)
 *\brief {Ajouter la lettre Y au bitmap}
 *\param[in] table Bitmap
 */
void printLettreY(Bitmap & table);
/*!
 *\fn void printLettreZ(Bitmap & table)
 *\brief {Ajouter la lettre Z au bitmap}
 *\param[in] table Bitmap
 */
void printLettreZ(Bitmap & table);
/*!
 *\fn void selection(Bitmap & table,int x=65)
 *\brief {Sélection de lettre et création du bitmap}
 *\param[in] table Bitmap
 **\param[in] x Valeur ASCII de la lettre
 */
void selection(Bitmap & table,int x=65);
#endif /* Bitmap_h */
