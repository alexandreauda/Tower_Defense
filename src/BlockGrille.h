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
    int m_isFreeID;//Id indiquant si le block est libre ou pas. m_isFreeID=0 si le block est libre et m_isFreeID=1 si il est occupe (par une tourelle par exemple)

public:

    /******CONSTRUCTEUR A PARAMETRE******/
	BlockGrille(float posx=0, float posy=0, float width=0.13, float height=0.13, float posxID=0, float posyID=0, int colorBlockID=0, int isFreeID=0):m_posx(posx), m_posy(posy), m_width(width), m_height(height), m_posxID(posxID), m_posyID(posyID), m_colorBlockID(colorBlockID), m_isFreeID(isFreeID){}//constructeur

    /******PROTOTYPES DES METHODES******/
    void draw() const;//Dessine le block

    int pointIsInBlock(float const& x, float const& y) const;//renvoi 1 si les coordonnées (x,y) sont dans le block et 0 sinon

    int pointIsInBlockFree(float const& x, float const& y) const;//renvoi 1 si les coordonnées (x,y) sont dans le block et que ce dernier est libre et 0 sinon

    float getm_posx() const;//Accesseur de l'attribut m_posx

    float getm_posy() const;//Accesseur de l'attribut m_posy

    float getm_width() const;//Accesseur de l'attribut m_width

    float getm_height() const;//Accesseur de l'attribut m_height

    int getm_posxID() const;//Accesseur de l'attribut m_posxID

    int getm_posyID() const;//Accesseur de l'attribut m_posyID

    int getm_colorBlockID() const;//Accesseur de l'attribut m_colorBlockID

    int getm_isFreeID() const;//Accesseur de l'attribut m_isFreeID

    void setm_posxID (int const& posxID);//Setteur de l'attribut m_posxID

    void setm_posyID (int const& posyID);//Setteur de l'attribut m_posyID

    void setm_colorBlockID (int const& colorBlockID);//Setteur de l'attribut m_colorBlockID

    void setm_isFreeID (int const& m_isFreeID);//Setteur de l'attribut m_isFreeID

};

