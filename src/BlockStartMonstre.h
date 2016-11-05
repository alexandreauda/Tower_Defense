#pragma once
#include "Block.h"

//La Class BlockStartMonstre herite de la Class Block
class BlockStartMonstre : public Block {

private:

    /******ATTRIBUTS******/
    int m_colorPlayID;//Determine la couleur du Play

public:

    /******CONSTRUCTEUR A PARAMETRES******/
	BlockStartMonstre(float posx=0.815, float posy=0.75, float width=0.17, float height=0.17, int colorBlockID=2, int colorPlayID=0): Block(posx,posy,width,height,colorBlockID), m_colorPlayID(colorPlayID){}//constructeur a parametre


    /******ACCESSEURS******/
    //null

    /******MUTATEURS******/
    void setm_colorPlayID (int const& colorPlayID);//Setteur de l'attribut colorPlayID

    /******PROTOTYPES DES METHODES******/
    virtual void draw() const;//Dessine le bouton qui sert a lancer les vagues de Monstres

};

