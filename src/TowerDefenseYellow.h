#pragma once
#include "TowerDefense.h"


class TowerDefenseYellow: public TowerDefense{

private:

    /******ATTRIBUT******/
    int m_tdy1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	TowerDefenseYellow(): TowerDefense(), m_tdy1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual void draw(BlockGrille blockBase) const; //Dessine la tourelle


};
