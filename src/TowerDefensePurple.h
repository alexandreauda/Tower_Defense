#pragma once
#include "Grille.h"
#include "TowerDefense.h"

//La Class TowerDefensePurple herite de la Class TowerDefense
class TowerDefensePurple: public TowerDefense{

private:

    /******ATTRIBUT******/
    int m_tdy1;

public:

    /******CONSTRUCTEUR A PARAMETRES******/
	TowerDefensePurple(BlockGrille blockBase, int portee=1, int cadence=10, int timer=0): TowerDefense(blockBase,blockBase.getm_posx()+blockBase.getm_width()/2,blockBase.getm_posy()+blockBase.getm_height()/2,blockBase.getm_posx()+blockBase.getm_width()/2,blockBase.getm_posy()+blockBase.getm_height()/2,portee,cadence,timer), m_tdy1(0){}


    /******ACCESSEURS******/
    //null


    /******MUTATEURS******/
    //null


    /******PROTOTYPES DES METHODES******/
    virtual void draw() const; //Dessine la tourelle

    virtual void drawTir() const;//Dessine les tirs des tourelles

    virtual void attaque(Monstre* monstreEnnemi);


};
