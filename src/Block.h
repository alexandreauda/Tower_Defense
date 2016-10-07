#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"

class Block {
public:
    /******ATTRIBUT******/
	int posx;
	int posy;
	int width;
	int height;
	float r, g, b, a;//Couleur RGB + a=Alpha (transparence)
    int groundID = 0;
	int airID = 0;

    /******CONSTRUCTEUR A PARAMETRE******/
	Block(int posx, int posy, int width, int height, float r = 245.0, float g = 245.0, float  b = 220.0, float a = 1.0, int groundID = 0, int airID = 0);//constructeur

    /******PROTOTYPES DES METHODES******/
	virtual void draw();//draw the block

};

