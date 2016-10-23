#include "Store.h"
using namespace std;


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode loadStore permet d'initialiser un vecteur statique pris en parametre avec des blocks de carasteristiques differentes.
Le vecteur statique en parametre est modifiee par la methode car il est passe par reference.

@param: La methode loadStore prend un parametre obligatoire: un vecteur statique de type BlockStore et de dimension 12.
-param1: un vecteur statique de type BlockStore et de dimension 12 qui va etre modifie pour etre initialise avec des blocks de carasteristiques differentes.
*/
void Store::loadStore(BlockStore stockStore[12]) const {

for(int i=0;i<12;i++){

				stockStore[i]= BlockStore(-i*m_shopCellWidth-0.004*i+0.67, -0.85, m_shopCellWidth, m_shopCellHeight);//on initialise le tableau stockStore[] avec des blocs

                (stockStore[i]).setm_posID(11-i);//on numerote les blocks au fur et a mesure

                (stockStore[i]).setm_colorBlockID(2);//on set l'ID

			}
}


/*
@description:
La methode draw de la classe Store permet de dessiner l'inventaire de maniere graphique.

@param: null
*/
void Store::draw() const {

BlockStore stockStore[12];//on definit un tableau vide de longueur 12 de type BlockStore
loadStore(stockStore);//on initialise le vecteur statique stockStore pris en parametre avec des blocks de carasteristiques differentes

//on parcourt le vecteur statique
for(int i=0;i<12;i++){

                   (stockStore[i]).draw();//on dessine le bloc correspondant (dependamment de son m_colorBlockID, il sera dessine dans une couleur specifique)

			}
}
