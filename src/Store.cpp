#include "Store.h"
using namespace std;



/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode draw de la classe Store permet de dessiner l'inventaire de maniere graphique.

@param: null
*/
void Store::draw() const {

Block stockStore[12];//on definit un tableau vide de longueur 12 de type Block
for(int i=0;i<12;i++){
            Value w;

				stockStore[i]= Block(-i*m_shopCellSize-0.004*i+0.67,-0.85,m_shopCellSize,m_shopCellSize,0.0,0.0,1.0,1.0, w.getm_groundGrass());//on initialise le tableau stockStore[] avec des blocs

                (stockStore[i]).setm_grassID(2);//on set l'ID

                   (stockStore[i]).draw();//on dessine le bloc correspondant

			}
}
