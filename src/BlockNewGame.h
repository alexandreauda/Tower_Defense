#pragma once
#include "Block.h"
#include "LibMatrix.h"

//La Class BlockNewGame herite de la Class Block
class BlockNewGame : public Block {

private:

    /******ATTRIBUTS******/
    //Les attributs de la Class Block

public:

    /******CONSTRUCTEUR A PARAMETRES******/
	BlockNewGame(float posx=-0.15, float posy=0.26, float width=0.40, float height=0.17, int colorBlockID=2, int colorPlayID=0): Block(posx,posy,width,height,colorBlockID){}//constructeur a parametre


    /******ACCESSEURS******/
    //null

    /******MUTATEURS******/
    //null

    /******PROTOTYPES DES METHODES******/
    virtual void draw() const;//Dessine le bouton qui sert a lancer une nouvelle partie

};

