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

		//On affiche le bouton qui sert a lancer les vagues de Monstres
		m_buttonStartMonstre.draw();


		for(int i=0;i<m_TowerDefenseList->size();i++){
            (*m_TowerDefenseList)[i]->draw();
		}


        for(int i=0;i<m_MonstreList->size();i++){
            if((*m_MonstreList)[i]->getm_isArrive() == 0){
                (*m_MonstreList)[i]->draw();
            }
            else{
                //supprime l'element
                (*m_MonstreList).erase((*m_MonstreList).begin()+i);
            }
		}
}

