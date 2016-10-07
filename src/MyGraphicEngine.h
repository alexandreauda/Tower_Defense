#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Papillon.h"

class MyGraphicEngine:public GraphicEngine {

private:

    /******ATTRIBUT******/
    int const worldWidth = 12;
	int const worldHeight = 12;
	int blockSize = 52;

	Block block [][];


public:

    /******CONSTRUCTEUR A PARAMETRE******/
    MyGraphicEngine(){}

    /******PROTOTYPES DES METHODES******/

    virtual void physic();

    virtual void Draw();

};
