#include "TowerDefenseRicochet.h"

using namespace std;


/******IMPLEMENTATION DES ACCESSEURS******/
//null


/******IMPLEMENTATION DES MUTATEURS******/
//null



/******IMPLEMENTATION DES METHODES******/

/*
@description:
Renvoie un string avec le nom de la classe actuelle (à savoir ici: "TowerDefenseRicochet")

@param: null
*/
string TowerDefenseRicochet::getClass() const {
    return "TowerDefenseRicochet";
}

/*
@description:
La methode draw de la classe TowerDefenseRicochet permet de dessiner des tourelles jaunes de maniere graphique dans le m_blockBase.

@param: null
*/
void TowerDefenseRicochet::draw() const{

    //Met les valeurs RGB dans la couleur rouge
    float const r=1.0;
    float const g=0.0;
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
La methode drawTir de la classe TowerDefenseRicochet permet de dessiner les tirs des tourelles rouges de maniere graphique.

@param: null
*/
void TowerDefenseRicochet::drawTir() const{

    //Met les valeurs RGB dans la couleur blanche
    float const r=1.0;
    float const g=1.0;
    float const b=1.0;
    float const alpha = 1.0;

 GraphicPrimitives::drawLine2D(m_centerTowerx, m_centerTowery, m_targetx, m_targety, r, g, b, alpha);
}

/*
@description:
La methode drawTirRicochet de la classe TowerDefenseRicochet permet de dessiner les ricochets des tirs des tourelles rouges de maniere graphique.

@param: null
*/
void TowerDefenseRicochet::drawTirRicochet(vector <Monstre *> *MonstreList) const{

    //Met les valeurs RGB dans la couleur blanche
    float const r=1.0;
    float const g=1.0;
    float const b=1.0;
    float const alpha = 1.0;

    int currentNbRicochet;

    //Si le nombre de ricochet est inferieur ou egal aux nombres de Monstres a proximites de la tourelle
    if(m_nbRicochet<=MonstreList->size()){
       currentNbRicochet=m_nbRicochet;
    }
    //Si le nombre de ricochet est superieur aux nombres de Monstres a proximites  de la tourelle
    else{
        currentNbRicochet=MonstreList->size();
    }

    //Trace les ricochets
    for(int i=0; i<currentNbRicochet; i++){
        GraphicPrimitives::drawLine2D((*MonstreList)[i]->monsterCenterx(), (*MonstreList)[i]->monsterCentery(), (*MonstreList)[i+1]->monsterCenterx(), (*MonstreList)[i+1]->monsterCentery(), r, g, b, alpha);
    }
}


/*
@description:
La methode attaque de la classe TowerDefenseRicochet prend un pointeur de Monstre en parametre et fait baisser la vie du monstre pointe par le pointeur.

@param: La methode attaque prend un parametre obligatoire: un pointeur de Monstre.
-param1: un pointeur pointant sur le Monstre que la tourelle attaque
*/
void TowerDefenseRicochet::attaque(Monstre* monstreEnnemi){
monstreEnnemi->receiveDamage(m_attackDamage);//Le monstre recoit des dommages
}
