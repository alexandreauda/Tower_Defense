#include "IAOnePath.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode searchInitWay de la classe IAOnePath renvoie au hazard le premier block du chemin de la grille en considerant que celle-ci peut comporter plusieurs chemins.

@param: La methode searchInitWay de la classe IAOnePath prend un parametre obligatoire: une matrice de BlockGrille de dimension 12*12 dans lequel l'IA effectura sa recherche.
-param1: une matrice de BlockGrille de dimension 12*12 dans lequel l'IA effectura sa recherche.
*/
BlockGrille IAOnePath::searchInitWay(BlockGrille grilleDeJeu[12][12]) const{
  vector<int> vectListInitBlock;
  int xEntryWay;
  for(int i=0;i<12;i++){
    if((grilleDeJeu[i][0]).getm_colorBlockID() == 1){
        vectListInitBlock.push_back(i);
    }
  }
    int nombre_aleatoire = 0;
	srand(time(NULL)); // initialisation de rand
    nombre_aleatoire = rand()%vectListInitBlock.size();//Nombre pris aleatoirement entre 0 et le nombre de block qui initialise un chemin dans la grille - 1.
    xEntryWay=vectListInitBlock[nombre_aleatoire];

  return grilleDeJeu[xEntryWay][0];//retourne le block qui est une dalle du chemin et qui est sur la premiere colonne
}


/*
@description:
La methode searchWay de la classe IAOnePath renvoie le prochain block sur lequel un monstre devra se rendre sur une grille en considerant que celle-ci ne comporte qu' un seul chemin. Si il y a plusieurs chemins (i.e: une intersection), les Monstres choisissent un chemin en suivant la regle de priorite suivant: RIGHT; DOWN; UP; LEFT.

@param: La methode searchWay de la classe IAOnePath prend un parametre obligatoire: une matrice de BlockGrille de dimension 12*12 dans lequel l'IA effectura sa recherche.
-param1: une matrice de BlockGrille de dimension 12*12 dans lequel l'IA effectura sa recherche.
*/
BlockGrille IAOnePath::searchWay(BlockGrille grilleDeJeu[12][12]) {

    int const actualPosxIDMonstre=m_actualPosition.getm_posyID();
    int const actualPosyIDMonstre=m_actualPosition.getm_posxID();
    int const previousPosxIDMonstre=m_previousPosition.getm_posyID();
    int const previousPosyIDMonstre=m_previousPosition.getm_posxID();

    BlockGrille const nextBlockRight=grilleDeJeu[actualPosxIDMonstre][actualPosyIDMonstre+1];
    BlockGrille const nextBlockLeft=grilleDeJeu[actualPosxIDMonstre][actualPosyIDMonstre-1];
    BlockGrille const nextBlockTop=grilleDeJeu[actualPosxIDMonstre-1][actualPosyIDMonstre];
    BlockGrille const nextBlockBottom=grilleDeJeu[actualPosxIDMonstre+1][actualPosyIDMonstre];

    //Si le monstre est sur le block tout en haut a gauche (coin haut a gauche)
    if(actualPosxIDMonstre==0 && actualPosyIDMonstre==0){

        //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
        if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
               m_direction="RIGHT";//met l'attribut m_direction egal a RIGHT
               return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
        }
        //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
        else{
            //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
            if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
               m_direction="DOWN";//met l'attribut m_direction egal a DOWN
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
                    m_direction="RIGHT";//met l'attribut m_direction egal a RIGHT
                    return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
                }
                //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                else{
                    //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                    if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                        m_direction="UP";//met l'attribut m_direction egal a UP
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
                        m_direction="RIGHT";//met l'attribut m_direction egal a RIGHT
                        return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
                    }
                    //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                    else{
                        //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                        if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
                            m_direction="DOWN";//met l'attribut m_direction egal a DOWN
                            return nextBlockBottom;//retourne le block en bas du block ou se trouve actuellement le monstre
                        }
                        //Si le block en bas du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                        else{
                                //Si le block a gauche du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockLeft.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre-1)){
                                    m_direction="LEFT";//met l'attribut m_direction egal a LEFT
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
                            m_direction="RIGHT";//met l'attribut m_direction egal a RIGHT
                            return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
                        }
                        //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                        else{
                            //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                            if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                                m_direction="UP";//met l'attribut m_direction egal a UP
                                return nextBlockTop;//retourne le block en haut du block ou se trouve actuellement le monstre
                            }
                            //Si le block en haut du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                            else{
                                //Si le block a gauche du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockLeft.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre-1)){
                                    m_direction="LEFT";//met l'attribut m_direction egal a LEFT
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
                                m_direction="RIGHT";//met l'attribut m_direction egal a RIGHT
                                return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
                            }
                            //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                            else{
                                //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
                                    m_direction="DOWN";//met l'attribut m_direction egal a DOWN
                                    return nextBlockBottom;//retourne le block en bas du block ou se trouve actuellement le monstre
                                }
                                //Si le block en bas du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                                else{
                                     //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                     if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                                        m_direction="UP";//met l'attribut m_direction egal a UP
                                        return nextBlockTop;//retourne le block en haut du block ou se trouve actuellement le monstre
                                    }
                                }
                            }
                        }

                        //Si le monstre n'est pas sur un block tout a gauche de la grille (et donc, n'est pas sur un bord de la grille)
                        else{

                            //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                            if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
                                m_direction="RIGHT";//met l'attribut m_direction egal a RIGHT
                                return nextBlockRight;//retourne le block a droite du block ou se trouve actuellement le monstre
                            }
                            //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                            else{
                                //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
                                    m_direction="DOWN";//met l'attribut m_direction egal a DOWN
                                    return nextBlockBottom;//retourne le block en bas du block ou se trouve actuellement le monstre
                                }
                                //Si le block en bas du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                                else{
                                    //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                    if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                                        m_direction="UP";//met l'attribut m_direction egal a UP
                                        return nextBlockTop;//retourne le block en haut du block ou se trouve actuellement le monstre
                                    }
                                    //Si le block en haut du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                                    else{
                                        //Si le block a gauche du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                        if((nextBlockLeft.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre-1)){
                                            m_direction="LEFT";//met l'attribut m_direction egal a LEFT
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



/*
@description:
La methode searchIfWay de la classe IAOnePath renvoie 1 s'il existe un block sur lequel un monstre peut se rendre sur la grille pour continuer a avancer et 0 si le Monstre ne trouve aucun block sur lequel il peut avancer.

@param: La methode searchIfWay de la classe IAOnePath prend un parametre obligatoire: une matrice de BlockGrille de dimension 12*12 dans lequel l'IA effectura sa recherche.
-param1: une matrice de BlockGrille de dimension 12*12 dans lequel l'IA effectura sa recherche.
*/
int IAOnePath::searchIfWay(BlockGrille grilleDeJeu[12][12]) const{

    int const actualPosxIDMonstre=m_actualPosition.getm_posyID();
    int const actualPosyIDMonstre=m_actualPosition.getm_posxID();
    int const previousPosxIDMonstre=m_previousPosition.getm_posyID();
    int const previousPosyIDMonstre=m_previousPosition.getm_posxID();

    BlockGrille const nextBlockRight=grilleDeJeu[actualPosxIDMonstre][actualPosyIDMonstre+1];
    BlockGrille const nextBlockLeft=grilleDeJeu[actualPosxIDMonstre][actualPosyIDMonstre-1];
    BlockGrille const nextBlockTop=grilleDeJeu[actualPosxIDMonstre-1][actualPosyIDMonstre];
    BlockGrille const nextBlockBottom=grilleDeJeu[actualPosxIDMonstre+1][actualPosyIDMonstre];

    //Si le monstre est sur le block tout en haut a gauche (coin haut a gauche)
    if(actualPosxIDMonstre==0 && actualPosyIDMonstre==0){

        //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
        if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
               return 1;//retourne 1
        }
        //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
        else{
            //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
            if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
               return 1;//retourne 1
           }
           else{
               return 0;//retourne 0
           }
        }
    }

    //Si le monstre n'est pas sur le block tout en haut a gauche (et donc, n'est pas sur le coin haut a gauche)
    else{

            //Si le monstre est sur le block tout en bas a gauche (coin bas a gauche)
            if(actualPosxIDMonstre==11 && actualPosyIDMonstre==0){

                //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
                    return 1;//retourne 1
                }
                //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                else{
                    //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                    if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                        return 1;//retourne 1
                    }
                    else{
                        return 0;//retourne 0
                    }
                }
            }

            //Si le monstre n'est pas sur le block tout en bas a gauche (et donc, n'est pas sur le coin bas a gauche)
            else{

                //Si le monstre est sur un block tout en haut mais qu'il n'est pas dans un coin de la grille
                if((actualPosxIDMonstre==0) && (actualPosyIDMonstre > 0) && (actualPosyIDMonstre < 11)){

                    //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                    if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
                        return 1;//retourne 1
                    }
                    //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                    else{
                        //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                        if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
                            return 1;//retourne 1
                        }
                        //Si le block en bas du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                        else{
                                //Si le block a gauche du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockLeft.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre-1)){
                                    return 1;//retourne 1
                                }
                                else{
                                    return 0;//retourne 0
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
                            return 1;//retourne 1
                        }
                        //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                        else{
                            //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                            if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                                return 1;//retourne 1
                            }
                            //Si le block en haut du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                            else{
                                //Si le block a gauche du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockLeft.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre-1)){
                                    return 1;//retourne 1
                                }
                                else{
                                    return 0;//retourne 0
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
                                return 1;//retourne 1
                            }
                            //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                            else{
                                //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
                                    return 1;//retourne 1
                                }
                                //Si le block en bas du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                                else{
                                     //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                     if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                                        return 1;//retourne 1
                                    }
                                    else{
                                        return 0;//retourne 0
                                    }
                                }
                            }
                        }

                        //Si le monstre n'est pas sur un block tout a gauche de la grille (et donc, n'est pas sur un bord de la grille)
                        else{

                            //Si le block a droite du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                            if((nextBlockRight.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre+1)){
                                return 1;//retourne 1
                            }
                            //Si le block a droite du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                            else{
                                //Si le block en bas du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                if((nextBlockBottom.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre+1)){
                                    return 1;//retourne 1
                                }
                                //Si le block en bas du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                                else{
                                    //Si le block en haut du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                    if((nextBlockTop.getm_colorBlockID() == 1) && (previousPosxIDMonstre != actualPosxIDMonstre-1)){
                                        return 1;//retourne 1
                                    }
                                    //Si le block en haut du block ou se trouve actuellement le monstre ne fait pas parti du chemin ou que le monstre y etait avant
                                    else{
                                        //Si le block a gauche du block ou se trouve actuellement le monstre fait parti du chemin et que le monstre n'y etait pas avant
                                        if((nextBlockLeft.getm_colorBlockID() == 1) && (previousPosyIDMonstre != actualPosyIDMonstre-1)){
                                            return 1;//retourne 1
                                        }
                                        else{
                                            return 0;//retourne 0
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




/*
@description:
Renvoie un string avec le nom de la classe actuelle (à savoir ici: "IAOnePath")

@param: null
*/
string IAOnePath::getClass() const {
    return "IAOnePath";
}
