#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"

class Block {
public:
    /******ATTRIBUT******/
	int m_posx;
	int m_posy;
	int m_width;
	int m_height;
	float m_r, m_g, m_b, m_a;//Couleur RGB + a=Alpha (transparence)
    int m_groundID;
	int m_airID;

    /******CONSTRUCTEUR A PARAMETRE******/
	Block(int posx=0, int posy=0, int width=5, int height=5, float r = 245.0, float g = 245.0, float  b = 220.0, float a = 1.0, int groundID = 0, int airID = 0):m_posx(posx),
                                                                                                                                                                 m_posy(posy),
                                                                                                                                                                 m_width(width),
                                                                                                                                                                 m_height(height),
                                                                                                                                                                 m_r(r),m_g(g),
                                                                                                                                                                 m_b(b),m_a(a),
                                                                                                                                                                 m_groundID(groundID),
                                                                                                                                                                 m_airID(airID){}//constructeur

    /******PROTOTYPES DES METHODES******/
	virtual void draw();//draw the block

};

