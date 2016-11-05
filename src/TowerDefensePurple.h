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
	TowerDefensePurple(BlockGrille blockBase): TowerDefense(blockBase), m_tdy1(0){}


    /******ACCESSEURS******/
    //null


    /******MUTATEURS******/
    //null


    /******PROTOTYPES DES METHODES******/
    virtual void draw() const; //Dessine la tourelle


};
