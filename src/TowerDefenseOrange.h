#pragma once
#include "Grille.h"
#include "TowerDefense.h"

//La Class TowerDefenseOrange herite de la Class TowerDefense
class TowerDefenseOrange: public TowerDefense{

private:

    /******ATTRIBUT******/
    int m_tdo1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	TowerDefenseOrange(): TowerDefense(), m_tdo1(0){}

    /******CONSTRUCTEUR A PARAMETRES******/
	TowerDefenseOrange(BlockGrille blockBase): TowerDefense(blockBase), m_tdo1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual void draw() const; //Dessine la tourelle


};
