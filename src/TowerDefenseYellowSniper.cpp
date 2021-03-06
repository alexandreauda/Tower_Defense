#include "TowerDefenseYellowSniper.h"

using namespace std;


/******IMPLEMENTATION DES ACCESSEURS******/
//null


/******IMPLEMENTATION DES MUTATEURS******/
//null



/******IMPLEMENTATION DES METHODES******/

/*
@description:
Renvoie un string avec le nom de la classe actuelle (� savoir ici: "TowerDefenseYellowSniper")

@param: null
*/
string TowerDefenseYellowSniper::getClass() const {
    return "TowerDefenseYellowSniper";
}

/*
@description:
La methode draw de la classe TowerDefenseYellowSniper permet de dessiner des tourelles jaunes tres fonce de maniere graphique dans le m_blockBase.

@param: null
*/
void TowerDefenseYellowSniper::draw() const{

    //Met les valeurs RGB dans la couleur jaune tres fonce
    float const r=0.6;
    float const g=0.6;
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

/*
@description:
La methode drawTir de la classe TowerDefenseYellowSniper permet de dessiner les tirs des tourelles jaunes de maniere graphique.

@param: null
*/
void TowerDefenseYellowSniper::drawTir() const{

    //Met les valeurs RGB dans la couleur blanche
    float const r=1.0;
    float const g=1.0;
    float const b=1.0;
    float const alpha = 1.0;

 GraphicPrimitives::drawLine2D(m_centerTowerx, m_centerTowery, m_targetx, m_targety, r, g, b, alpha);
}

/*
@description:
La methode attaque de la classe TowerDefenseYellowSniper prend un pointeur de Monstre en parametre et fait baisser la vie du monstre pointe par le pointeur.

@param: La methode attaque prend un parametre obligatoire: un pointeur de Monstre.
-param1: un pointeur pointant sur le Monstre que la tourelle attaque
*/
void TowerDefenseYellowSniper::attaque(Monstre* monstreEnnemi){
monstreEnnemi->receiveDamage(1);//Le monstre recoit des dommages
}
