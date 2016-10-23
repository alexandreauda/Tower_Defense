#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"

class BlockStore {

protected:

    /******ATTRIBUT******/
	float m_posx;
	float m_posy;
	float m_width;
	float m_height;
    int m_colorBlockID;//Determine la couleur du Block

    public:

    /******CONSTRUCTEUR A PARAMETRE******/
    BlockStore(float posx=0, float posy=0, float width=0.13, float height=0.13, int colorBlockID=0):m_posx(posx), m_posy(posy), m_width(width), m_height(height), m_colorBlockID(colorBlockID){}//constructeur

    /******PROTOTYPES DES METHODES******/
    void draw() const;//draw the block

    void setm_colorBlockID (int const& colorBlockID);//Setteur de l'attribut m_grassID

};

