#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){

    int widthWindows;
    int heigthWindows;

    Windows gameWindows;
    gameWindows.loadDimensionWindows("Files_Levels/DimensionWindows.txt",widthWindows, heigthWindows);//on initialise les variables widthWindows et heigthWindows avec les valeurs lues dans le fichier

    int mousePosx=(x-widthWindows)/widthWindows;//position en abscisse de la souris dans la fenetre GLUT
    int mousePosy=(-(y-heigthWindows)/heigthWindows);//position en ordonne de la souris dans la fenetre GLUT

        //On load la grille de Jeu
        BlockGrille grilleDeJeu[12][12];
        Grille grilleDamier;
        grilleDamier.loadGrille("Files_Levels/Level_1.txt",grilleDeJeu);

        //On load le Store
        BlockStore stockStore[12];
		Store shop;
		shop.loadStore(stockStore);//Load le Store


    //Si le bouton gauche de la souris est enfoncé alors...
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        //...TODO
    }
}
