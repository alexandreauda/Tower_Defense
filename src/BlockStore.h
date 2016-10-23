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
    int m_posID;//ID de position en abscisse sur la grille
    int m_colorBlockID;//Determine la couleur du Block

public:

    /******CONSTRUCTEUR A PARAMETRE******/
	BlockStore(float posx=0, float posy=0, float width=0.13, float height=0.13, float posID=0, int colorBlockID=0):m_posx(posx), m_posy(posy), m_width(width), m_height(height), m_posID(posID), m_colorBlockID(colorBlockID){}//constructeur

    /******PROTOTYPES DES METHODES******/
    void draw() const;//draw the block

    int getm_posID() const;//Accesseur de l'attribut m_posID

    void setm_posID (int const& posID);//Setteur de l'attribut m_posID

    void setm_colorBlockID (int const& colorBlockID);//Setteur de l'attribut m_grassID

};

