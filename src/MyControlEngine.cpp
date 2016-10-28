#include "MyControlEngine.h"

using namespace std;

void MyControlEngine::MouseCallback(int button, int state, int x, int y){

    //Si le bouton gauche de la souris est enfoncé alors...
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        float widthWindows;
        float heigthWindows;

        Windows gameWindows;
        gameWindows.loadDimensionWindows("Files_Levels/DimensionWindows.txt",widthWindows, heigthWindows);//on initialise les variables widthWindows et heigthWindows avec les valeurs lues dans le fichier

        widthWindows/=2.0;
        heigthWindows/=2.0;

        float mousePosx=(x-widthWindows)/widthWindows;//position en abscisse de la souris dans la fenetre GLUT
        float mousePosy=(-(y-heigthWindows)/heigthWindows);//position en ordonne de la souris dans la fenetre GLUT

        //On load la grille de Jeu
        BlockGrille grilleDeJeu[12][12];
        Grille grilleDamier;
        grilleDamier.loadGrille("Files_Levels/Level_1.txt",grilleDeJeu);//Load la matrice grilleDeJeu

        //On load le Store
        BlockStore stockStore[12];
        Store shop;
        shop.loadStore(stockStore);//Load le Store

        for(int x=0;x<12;x++){
            for(int y=0;y<12;y++){
                if((grilleDeJeu[x][y]).pointIsInBlockFree(mousePosx,mousePosy) == 1){
                    switch(m_stockColorTower){

                        case 0:break;

                        case 1:m_TowerDefenseList->push_back(new TowerDefenseYellow((grilleDeJeu[x][y])));
                               (grilleDeJeu[x][y]).setm_isFreeID(1);
                                break;

                        case 2:m_TowerDefenseList->push_back(new TowerDefenseOrange((grilleDeJeu[x][y])));
                               (grilleDeJeu[x][y]).setm_isFreeID(1);
                                break;

                        case 3:m_TowerDefenseList->push_back(new TowerDefensePurple((grilleDeJeu[x][y])));
                               (grilleDeJeu[x][y]).setm_isFreeID(1);
                                break;

                        default:break;
                    }
                }
            }
        }

        for(int i=0; i<12;i++){
            if((stockStore[i]).pointIsInBlock(mousePosx,mousePosy) == 1){//Si la souris appuie sur un block du Store
                    switch((stockStore[i]).getm_posID()){

                        case 0:m_stockColorTower=0;
                               break;

                        case 1:m_stockColorTower=1;
                               break;

                        case 2:m_stockColorTower=2;
                               break;

                        case 3:m_stockColorTower=3;
                               break;

                        default:break;
                    }
            }
        }

    }

    //Si le bouton droit de la souris est enfoncé alors...
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

        m_stockColorTower=0;//on met l'attribut m_stockColorTower a 0. Ainsi, cela permet a l'utilisateur qui a choisit une couleur de tourelle de se retracter pour choisir une autre couleur de tourelle ou simplement pour eviter de mettre une tourelle sur la grille involontairement.
    }
}
