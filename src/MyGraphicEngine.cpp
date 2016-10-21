#include "MyGraphicEngine.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode Draw de la classe MyGraphicEngine permet de dessiner le damier graphique avec le(s) chemins accesibles ou va se derouler le jeu.

@param: null.
*/
void MyGraphicEngine::Draw(){

        //On affiche la grille de Jeu
        Grille grilleDeJeu;
        grilleDeJeu.draw("Files_Levels/Level_1.txt");

        //On affiche le Store
		Store shop;
		shop.draw();//Draw le Store

}

