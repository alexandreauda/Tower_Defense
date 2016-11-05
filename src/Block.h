#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"

class Block {

protected:

    /******ATTRIBUTS******/
	float m_posx;
	float m_posy;
	float m_width;
	float m_height;
    int m_colorBlockID;//Determine la couleur du Block

public:

    /******CONSTRUCTEUR A PARAMETRES******/
	Block(float posx=0, float posy=0, float width=0.13, float height=0.13, int colorBlockID=0):m_posx(posx), m_posy(posy), m_width(width), m_height(height), m_colorBlockID(colorBlockID){}//constructeur a parametre


    /******ACCESSEURS******/
    float getm_posx() const;//Accesseur de l'attribut m_posx

    float getm_posy() const;//Accesseur de l'attribut m_posy

    float getm_width() const;//Accesseur de l'attribut m_width

    float getm_height() const;//Accesseur de l'attribut m_height

    int getm_colorBlockID() const;//Accesseur de l'attribut m_colorBlockID

    /******MUTATEURS******/
    void setm_colorBlockID (int const& colorBlockID);//Setteur de l'attribut m_colorBlockID


    /******PROTOTYPES DES METHODES******/
    virtual void draw() const = 0;//methode virtuelle pure

    int pointIsInBlock(float const& x, float const& y) const;//renvoi 1 si les coordonnées (x,y) sont dans le block et 0 sinon

};

