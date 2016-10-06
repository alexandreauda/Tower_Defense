#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Papillon.h"

class MyGraphicEngine:public GraphicEngine {

private:

    /******ATTRIBUT******/
    std::vector<Papillon * > *paps;
    char * str;
    float x1,x2,vx1,vx2;

public:

    /******CONSTRUCTEUR******/
    MyGraphicEngine(std::vector<Papillon * > * paps_):paps(paps_),str(new char[13]{'C','l','i','c',' ','&',' ','E','n','j','o','y','\0'}),x1(0.5),x2(-0.5),vx1(0.01),vx2(-0.02){}

    /******PROTOTYPES DES METHODES******/
    virtual void Draw();

};
