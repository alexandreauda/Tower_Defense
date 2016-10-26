#include "IAOnePath.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

BlockGrille IAOnePath::searchInitWay(){
  //TODO
  //return
}


/*
@description:
La methode searchWay de la classe IAOnePath renvoie le prochain block sur lequel un monstre devra se rendre sur une grille avec un seul chemin.

@param: La methode searchWay de la classe IAOnePath prend un parametre obligatoire: une matrice de BlockGrille de dimension 12*12 dans lequel l'IA effectura sa recherche.
-param1: une matrice de BlockGrille de dimension 12*12 dans lequel l'IA effectura sa recherche.
*/
BlockGrille IAOnePath::searchWay(BlockGrille grilleDeJeu[12][12]) const {

    int const actualPosxIDMonstre=m_actualPosition.getm_posxID();
    int const actualPosyIDMonstre=m_actualPosition.getm_posyID();
    int const previousPosxIDMonstre=m_previousPosition.getm_posxID();
    int const previousPosyIDMonstre=m_previousPosition.getm_posyID();

    BlockGrille const nextBlockRight=grilleDeJeu[actualPosxIDMonstre][actualPosyIDMonstre+1];
    BlockGrille const nextBlockLeft=grilleDeJeu[actualPosxIDMonstre][actualPosyIDMonstre-1];
    BlockGrille const nextBlockTop=grilleDeJeu[actualPosxIDMonstre-1][actualPosyIDMonstre];
    BlockGrille const nextBlockBottom=grilleDeJeu[actualPosxIDMonstre+1][actualPosyIDMonstre];

    //Si le monstre est sur le block tout en haut a gauche (coin haut a gauche)
    if(actualPosxIDMonstre==0 && actualPosyIDMonstre==0){

        //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
        if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
               return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
        }
        //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
        else{
            //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
            if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
               return nextBlockBottom;//retourne le block en bas du block ou se trouve actuellement le monstre
           }
        }
    }

    //Si le monstre n'est pas sur le block tout en haut a gauche (et donc, n'est pas sur le coin haut a gauche)
    else{

            //Si le monstre est sur le block tout en bas a gauche (coin bas a gauche)
            if(actualPosxIDMonstre==11 && actualPosyIDMonstre==0){

                //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
                    return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
                }
                //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                else{
                    //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                    if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                        return nextBlockTop;//retourne le block en haut du block ou se trouve actuellement le monstre
                    }
                }
            }

            //Si le monstre n'est pas sur le block tout en bas a gauche (et donc, n'est pas sur le coin bas a gauche)
            else{

                //Si le monstre est sur un block tout en haut mais qu'il n'est pas dans un coin de la grille
                if((actualPosxIDMonstre==0) && (actualPosyIDMonstre > 0) && (actualPosyIDMonstre < 11)){

                    //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                    if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
                        return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
                    }
                    //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                    else{
                        //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                        if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
                            return nextBlockBottom;//retourne le block en bas du block ou se trouve actuellement le monstre
                        }
                        //Si le block en bas du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                        else{
                                //Si le block a gauche du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockLeft.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre-1)){
                                    return nextBlockLeft;//retourne le block a gauche du block ou se trouve actuellement le monstre
                                }
                        }
                    }
                }

                //Si le monstre n'est pas sur un block tout en haut de la grille
                else{

                    //Si le monstre est sur un block tout en bas mais qu'il n'est pas dans un coin de la grille
                    if((actualPosxIDMonstre==11) && (actualPosyIDMonstre > 0) && (actualPosyIDMonstre < 11)){

                        //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                        if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
                            return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
                        }
                        //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                        else{
                            //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                            if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                                return nextBlockTop;//retourne le block en haut du block ou se trouve actuellement le monstre
                            }
                            //Si le block en haut du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                            else{
                                //Si le block a gauche du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockLeft.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre-1)){
                                    return nextBlockLeft;//retourne le block a gauche du block ou se trouve actuellement le monstre
                                }
                            }
                        }
                    }

                    //Si le monstre n'est pas sur un block tout en bas de la grille
                    else{

                        //Si le monstre est sur un block tout a gauche mais qu'il n'est pas dans un coin de la grille
                        if((actualPosyIDMonstre==0) && (actualPosxIDMonstre > 0) && (actualPosxIDMonstre < 11)){

                              //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                            if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
                                return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
                            }
                            //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                            else{
                                //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
                                    return nextBlockBottom;//retourne le block en bas du block ou se trouve actuellement le monstre
                                }
                                //Si le block en bas du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                                else{
                                     //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                     if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                                        return nextBlockTop;//retourne le block en haut du block ou se trouve actuellement le monstre
                                    }
                                }
                            }
                        }

                        //Si le monstre n'est pas sur un block tout a gauche de la grille (et donc, n'est pas sur un bord de la grille)
                        else{

                            //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                            if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
                                return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
                            }
                            //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                            else{
                                //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
                                    return nextBlockBottom;//retourne le block en bas du block ou se trouve actuellement le monstre
                                }
                                //Si le block en bas du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                                else{
                                    //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                    if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                                        return nextBlockTop;//retourne le block en haut du block ou se trouve actuellement le monstre
                                    }
                                    //Si le block en haut du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                                    else{
                                        //Si le block a gauche du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                        if((nextBlockLeft.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre-1)){
                                            return nextBlockLeft;//retourne le block a gauche du block ou se trouve actuellement le monstre
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
    }

 }
