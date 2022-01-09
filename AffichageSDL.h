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
        /*!
        * \fn {Dessine}
        * \brief {Fonction permettant de dessiner dans la fenêtre SDL nos lettres}
        * \param[in] x Valeur ASCII de la lettre 
        * \param[in] width Largueur du bitmap
        * \param[in] heigth Hauteur du bitmap
        */
        void Dessine(int x, int width, int heigth) {
            
            /*Sélection du Bitmap à dessiner dans la fenêtre SDL*/
            std::cout<<"Bitmap of the chosen letter:" <<std::endl;
            Bitmap table(width,heigth);
            selection(table,x);
            std::cout<<"Please wait few seconds, display with SDL in progress..."<<std::endl;

            /* Gestion de l'erreur de l'initialisation de la SDL */
            if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
                std::cout << "Echec de l'initialisation" << std::endl;;
            
            }

            /*Création de la fenêtre SDL*/
            SDL_Window* Fenetre = NULL;
            Fenetre = SDL_CreateWindow("Projet",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, table.get_width()*20.5, table.get_heigth()*7, 0);
            
            /*Gestion de l'erreur de création de fenêtre*/
            if (!Fenetre){
                std::cout << "Erreur de création de la fenêtre: %s" << std::endl;
            }

            /*création du fond blanc de la fenêtre SDL*/
            SDL_Renderer* rendu;
            rendu = SDL_CreateRenderer(Fenetre, -1, SDL_RENDERER_ACCELERATED);
            SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
            SDL_RenderClear(rendu);
     


            /*création de rectangles pleins (pixels) afin de dessiner la lettre du bitmap*/

            int** bitmap_lettre = table.get_table();
            for(int i=0; i<table.get_heigth(); i++){
            
            
                for(int j=0; j<table.get_width(); j++){
                
                    /*Dessine lettre contour noir seul*/
                    if(bitmap_lettre[j][i]==2 ){ 
                        SDL_Rect srcrect; 
                        srcrect.x = i*5 ;
                        srcrect.y = table.get_heigth()/2+j*5;
                        srcrect.w = 5;
                        srcrect.h = 5;
                        SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
                        SDL_RenderFillRect(rendu, &srcrect);

                    } 

                    /* Dessine lettre noir pleine*/
                    if( bitmap_lettre[j][i]==1 ){ 
                        SDL_Rect srcrect; 
                        srcrect.x = table.get_width()*7+i*5;
                        srcrect.y = table.get_heigth()/2+j*5;
                        srcrect.w = 5;
                        srcrect.h = 5;
                        SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
                        SDL_RenderFillRect(rendu, &srcrect);

                    } 

                    /*Dessine lettre intérieur noir */
                    if(bitmap_lettre[j][i]==1){ 
                        SDL_Rect srcrect; 
                        srcrect.x = table.get_width()*14+i*5;
                        srcrect.y = table.get_heigth()/2+j*5;
                        srcrect.w = 5;
                        srcrect.h = 5;
                        SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
                        SDL_RenderFillRect(rendu, &srcrect);
                    }

                    /*Dessine le contour de lettre avec intérieur en noir */
                    if(bitmap_lettre[j][i]==2){ 
                        SDL_Rect srcrect; 
                        srcrect.x = table.get_width()*14+i*5 ;
                        srcrect.y = table.get_heigth()/2+j*5;
                        srcrect.w = 5;
                        srcrect.h = 5;
                        SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
                        SDL_RenderFillRect(rendu, &srcrect);
                    }   
                }
            }

            /*Affichage de la fenêtre*/
            SDL_RenderPresent(rendu);

            /*Boucle permettant de bien quitter le programme lorsque l'on ferme la fenêtre*/
            int continu = 1;
            while (continu) {
                SDL_PumpEvents();
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        continu = 0;
                        break;
                    }
                }
        
            }
        SDL_Quit();
    

        }
};



