#pragma once
#include "Block.h"

class BlockStore : public Block {

private:

    /******ATTRIBUT******/
    int m_posID;//ID de position en abscisse sur la grille

public:

    /******CONSTRUCTEUR A PARAMETRE******/
	BlockStore(float posx=0, float posy=0, float width=0.13, float height=0.13, float posID=0, int colorBlockID=2): Block(posx,posy,width,height,colorBlockID), m_posID(posID){}//constructeur a parametre


    /******ACCESSEURS******/
    int getm_posID() const;//Accesseur de l'attribut m_posID

    /******MUTATEURS******/
    void setm_posID (int const& posID);//Setteur de l'attribut m_posID

    /******PROTOTYPES DES METHODES******/
    virtual void draw() const;//Dessine le block du Store

};

