#pragma once
#include "GraphicPrimitives.h"


class Papillon {

private:

    /******ATTRIBUT******/
    float posX,posY,width,height;
    float VposX,VposY,Vwidth,Vheight;

public:


    /******CONSTRUCTEUR PAR DEFAUT******/
    Papillon(float posX_ = 0.0,float posY_ = 0.0):posX(posX_),posY(posY_),width(0.1),height(0.1),VposX(0.01),VposY(0.02),Vwidth(0.01),Vheight(-0.02){}

    /******PROTOTYPES DES METHODES******/
    void draw();
    void tick();

};
