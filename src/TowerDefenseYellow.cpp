#include "TowerDefenseYellow.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode draw de la classe TowerDefenseYellow permet de dessiner des tourelles jaunes de maniere graphique dans le m_blockBase.

@param: null
*/
void TowerDefenseYellow::draw() const{

    //Met les valeurs RGB dans la couleur jaune
    float const r=1.0;
    float const g=1.0;
    float const b=0.0;
    float const alpha = 1.0;

    //Recupere les attributs du block pris en parametre
    float const posx = m_blockBase.getm_posx();
    float const posy = m_blockBase.getm_posy();
    float const width = m_blockBase.getm_width();
    float const height = m_blockBase.getm_height();

    //Dessine la tourelle dans le block pris en parametre
    GraphicPrimitives::drawFillRect2D(posx+width/6, posy+height/6, width*2/3, height*2/3, r, g, b, alpha);

}
