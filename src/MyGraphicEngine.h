#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Papillon.h"
//#include "Block.h"

class MyGraphicEngine:public GraphicEngine {

private:

    /******ATTRIBUT******/
    int const worldWidth = 12;
	int const worldHeight = 12;
	int blockSize = 52;

	//Block block [12][12];


public:

    /******CONSTRUCTEUR******/
    MyGraphicEngine();

    /******PROTOTYPES DES METHODES******/

    virtual void physic();

    virtual void Draw();

};
