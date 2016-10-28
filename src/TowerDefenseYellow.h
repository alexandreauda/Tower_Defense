#pragma once
#include "Grille.h"
#include "TowerDefense.h"

//La Class TowerDefenseYellow herite de la Class TowerDefense
class TowerDefenseYellow: public TowerDefense{

private:

    /******ATTRIBUT******/
    int m_tdy1;

public:

    /******CONSTRUCTEUR A PARAMETRES******/
	TowerDefenseYellow(BlockGrille blockBase): TowerDefense(blockBase), m_tdy1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual void draw() const; //Dessine la tourelle


};
