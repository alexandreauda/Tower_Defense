#pragma once
#include "Block.h"
#include "LibMatrix.h"

//La Class BlockSaveGame herite de la Class Block
class BlockSaveGame : public Block {

private:

    /******ATTRIBUTS******/
    //Les attributs de la Class Block

public:

    /******CONSTRUCTEUR A PARAMETRES******/
	BlockSaveGame(float posx=0.815, float posy=0.50, float width=0.17, float height=0.17, int colorBlockID=2, int colorPlayID=0): Block(posx,posy,width,height,colorBlockID){}//constructeur a parametre


    /******ACCESSEURS******/
    //null

    /******MUTATEURS******/
    //null

    /******PROTOTYPES DES METHODES******/
    virtual void draw() const;//Dessine le bouton qui sert a lancer les vagues de Monstres

};

