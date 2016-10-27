#pragma once
#include "Grille.h"


class TowerDefense{

protected:

    /******ATTRIBUT******/
    float m_posx;
	float m_posy;
	float m_width;
	float m_height;

public:

    /******CONSTRUCTEUR A PARAMETRES******/
    TowerDefense(float posx=0, float posy=0, float width=0.13, float height=0.13): m_posx(posx), m_posy(posy), m_width(width), m_height(height) {}


    /******PROTOTYPES DES METHODES******/

    virtual void draw(BlockGrille blockBase) const =0; //Methode virtuelle pure


};
