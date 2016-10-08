#pragma once

#include "Engine.h"

class MyGameEngine:public GameEngine {

private:

    /******ATTRIBUT******/
    int g1;

public:

    /******CONSTRUCTEUR******/
    MyGameEngine():g1(0){}

    /******PROTOTYPES DES METHODES******/
    virtual void idle();

};
