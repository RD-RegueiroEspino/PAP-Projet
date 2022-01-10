/*!
 *\file AffichageSDL.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */

#include <SDL2/SDL.h>
#include "Bitmap.h"

/*!
 * \class {AffichageSDL}
 * \brief {Classe permettant de simplifier l'usage de la SDL dans notre projet}
 */
class AffichageSDL{

    public:
        SDL_Renderer* rendu;

    Bitmap Fenetre(int x, int width, int heigth);

    /*!
    * \fn {Dessine}
    * \brief {Fonction permettant de dessiner dans la fenêtre SDL nos lettres}
    * \param[in] x Valeur ASCII de la lettre 
    * \param[in] width Largueur du bitmap
    * \param[in] heigth Hauteur du bitmap
    */
    void Dessine(Bitmap table);
    /*!
    * \fn {LettreVide}
    * \brief {Fonction permettant de dessiner la lettre vide (contour seul)}
    * \param[in] bitmap_lettre Bitmap de stockage de la lettre
    * \param[in] j la j ième ligne de bitmap_lettre
    * \param[in] i la i ème colonne de bitmap_lettre
    * \param[in] table objet contenant le bitmap de la lettre
    */
    void LettreVide(int** bitmap_lettre, int j, int i, Bitmap table);
    /*!
    * \fn {LettreNoirPleine}
    * \brief {Fonction permettant de dessiner la lettre pleine en noir}
    * \param[in] bitmap_lettre Bitmap de stockage de la lettre
    * \param[in] j la j ième ligne de bitmap_lettre
    * \param[in] i la i ème colonne de bitmap_lettre
    * \param[in] table objet contenant le bitmap de la lettre
    */
    void LettreNoirPleine(int** bitmap_lettre, int j, int i, Bitmap table);
    /*!
    * \fn {LettreRouge}
    * \brief {Fonction permettant de dessiner la lettre noir avec un contour rouge}
    * \param[in] bitmap_lettre Bitmap de stockage de la lettre 
    * \param[in] j la j ième ligne de bitmap_lettre
    * \param[in] i la i ème colonne de bitmap_lettre
    * \param[in] table objet contenant le bitmap de la lettre
    */
    void LettreRouge(int** bitmap_lettre, int j, int i, Bitmap table);
};



