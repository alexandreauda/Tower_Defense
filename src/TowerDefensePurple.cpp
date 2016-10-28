#include "TowerDefensePurple.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode draw de la classe TowerDefensePurple permet de dessiner des tourelles violettes de maniere graphique dans le block pris en parametre.

@param: La methode draw prend un parametre obligatoire: un BlockGrille.
-param1: Ce parametre permet de designer le block dans lequel on va dessiner la tourelle.
*/
void TowerDefensePurple::draw(BlockGrille blockBase) const{

    //Met les valeurs RGB dans la couleur violette
    float const r=1.0;
    float const g=0.1;
    float const b=0.9;
    float const alpha = 1.0;

    //Recupere les attributs du block pris en parametre
    float const posx = blockBase.getm_posx();
    float const posy = blockBase.getm_posy();
    float const width = blockBase.getm_width();
    float const height = blockBase.getm_height();

    //Dessine la tourelle dans le block pris en parametre
    GraphicPrimitives::drawFillRect2D(posx+width/6, posy+height/6, width*2/3, height*2/3, r, g, b, alpha);

}
