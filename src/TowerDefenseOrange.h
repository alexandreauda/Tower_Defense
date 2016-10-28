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


    /******PROTOTYPES DES METHODES******/

    virtual void draw(BlockGrille blockBase) const; //Dessine la tourelle


};
