#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Value.h"

class BlockGrille {

protected:

    /******ATTRIBUT******/
	float m_posx;
	float m_posy;
	float m_width;
	float m_height;
	float m_r, m_g, m_b, m_a;//Couleur RGB + a=Alpha (transparence)
    int m_grassID;

    public:

    /******CONSTRUCTEUR A PARAMETRE******/
	BlockGrille(float posx=0, float posy=0, float width=5, float height=5, float r = 0.0, float g = 1.0, float  b = 0.0, float a = 1.0, int grassID = 0):m_posx(posx),
                                                                                                                                                                 m_posy(posy),
                                                                                                                                                                 m_width(width),
                                                                                                                                                                 m_height(height),
                                                                                                                                                                 m_r(r),m_g(g),
                                                                                                                                                                 m_b(b),m_a(a),
                                                                                                                                                                 m_grassID(grassID)
                                                                                                                                                                 {}//constructeur

    /******PROTOTYPES DES METHODES******/
    void draw() const;//draw the block

    void setm_grassID (int const& grassID);//Setteur de l'attribut m_grassID

};

