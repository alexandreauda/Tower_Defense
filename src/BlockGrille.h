#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"

class BlockGrille {

protected:

    /******ATTRIBUT******/
	float m_posx;
	float m_posy;
	float m_width;
	float m_height;
    int m_posxID;//ID de position en abscisse sur la grille
    int m_posyID;//ID de position en ordonne sur la grille
    int m_colorBlockID;//Determine la couleur du Block

public:

    /******CONSTRUCTEUR A PARAMETRE******/
	BlockGrille(float posx=0, float posy=0, float width=0.13, float height=0.13, float posxID=0, float posyID=0, int colorBlockID=0):m_posx(posx), m_posy(posy), m_width(width), m_height(height), m_posxID(posxID), m_posyID(posyID), m_colorBlockID(colorBlockID){}//constructeur

    /******PROTOTYPES DES METHODES******/
    void draw() const;//draw the block

    int getm_posxID() const;//Accesseur de l'attribut m_posxID

    int getm_posyID() const;//Accesseur de l'attribut m_posyID

    int getm_colorBlockID() const;//Accesseur de l'attribut m_colorBlockID

    void setm_posxID (int const& posxID);//Setteur de l'attribut m_posxID

    void setm_posyID (int const& posyID);//Setteur de l'attribut m_posyID

    void setm_colorBlockID (int const& colorBlockID);//Setteur de l'attribut m_colorBlockID

};

