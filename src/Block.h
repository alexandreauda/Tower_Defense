#pragma once

class Block {
public:
    /******ATTRIBUT******/
	int groundID = 0;
	int airID = 0;
	int posx;
	int posy;
	int width;
	int height;
	float r, g, b, a;//Couleur RGB + a=Alpha (transparence)

    /******CONSTRUCTEUR A PARAMETRE******/
	Block(int posx, int posy, int width, int height, float r, float g, float  b, float a, int groundID, int airID);//constructeur

    /******PROTOTYPES DES METHODES******/
	virtual void draw();//draw the block

};
