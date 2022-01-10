/*!
 *\file AffichageSDL.cpp
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#include "AffichageSDL.h"
#include <stdio.h>
Bitmap AffichageSDL::Fenetre(int x, int width, int heigth){
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
    rendu = SDL_CreateRenderer(Fenetre, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
    SDL_RenderClear(rendu);
    return table;
}
void AffichageSDL::Dessine(Bitmap table){
        /*création de rectangles pleins (pixels) afin de dessiner la lettre du bitmap*/
        int** bitmap_lettre = table.get_table();
        for(int i=0; i<table.get_heigth(); i++){
        
            for(int j=0; j<table.get_width(); j++){
            
                /*Dessine lettre contour noir seul*/
                LettreVide(bitmap_lettre, j, i, table);

                /* Dessine lettre noir pleine*/
                LettreNoirPleine(bitmap_lettre, j, i, table);

                /*Dessine lettre rouge */
                LettreRouge(bitmap_lettre, j, i, table);
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
void AffichageSDL::LettreVide(int** bitmap_lettre, int j, int i, Bitmap table){
        if(bitmap_lettre[j][i]==2 ){
            SDL_Rect srcrect;
            srcrect.x = i*5 ;
            srcrect.y = table.get_heigth()/2+j*5;
            srcrect.w = 5;
            srcrect.h = 5;
            SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
            SDL_RenderFillRect(rendu, &srcrect);
        }
}
void AffichageSDL::LettreNoirPleine(int** bitmap_lettre, int j, int i, Bitmap table){
    if( bitmap_lettre[j][i]==1 ){
        SDL_Rect srcrect;
        srcrect.x = table.get_width()*7+i*5;
        srcrect.y = table.get_heigth()/2+j*5;
        srcrect.w = 5;
        srcrect.h = 5;
        SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
        SDL_RenderFillRect(rendu, &srcrect);
    }
}
void AffichageSDL::LettreRouge(int** bitmap_lettre, int j, int i, Bitmap table){
    /*Dessine intérieur noir*/
    if(bitmap_lettre[j][i]==1){
        SDL_Rect srcrect;
        srcrect.x = table.get_width()*14+i*5;
        srcrect.y = table.get_heigth()/2+j*5;
        srcrect.w = 5;
        srcrect.h = 5;
        SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
        SDL_RenderFillRect(rendu, &srcrect);
    }
    /*Dessine le contour de lettre en rouge*/
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
