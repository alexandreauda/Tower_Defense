#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"

class Block {
public:
    /******ATTRIBUT******/
	float m_posx;
	float m_posy;
	float m_width;
	float m_height;
	float m_r, m_g, m_b, m_a;//Couleur RGB + a=Alpha (transparence)
    int m_groundID;
	int m_airID;

    /******CONSTRUCTEUR A PARAMETRE******/
	Block(float posx=0, float posy=0, float width=5, float height=5, float r = 0.0, float g = 1.0, float  b = 0.0, float a = 1.0, int groundID = 0, int airID = 0):m_posx(posx),
                                                                                                                                                                 m_posy(posy),
                                                                                                                                                                 m_width(width),
                                                                                                                                                                 m_height(height),
                                                                                                                                                                 m_r(r),m_g(g),
                                                                                                                                                                 m_b(b),m_a(a),
                                                                                                                                                                 m_groundID(groundID),
                                                                                                                                                                 m_airID(airID){}//constructeur

    /******PROTOTYPES DES METHODES******/
    void draw(float r, float g, float  b);//draw the block

};

