#pragma once
#include "Grille.h"
#include "TowerDefense.h"

//La Class TowerDefensePurple herite de la Class TowerDefense
class TowerDefensePurple: public TowerDefense{

private:

    /******ATTRIBUT******/
    int m_tdy1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	TowerDefensePurple(): TowerDefense(), m_tdy1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual void draw(BlockGrille blockBase) const; //Dessine la tourelle


};
