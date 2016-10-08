#pragma once

#include "Engine.h"

class MyGameEngine:public GameEngine {

private:

    /******ATTRIBUT******/
    int m_g1;

public:

    /******CONSTRUCTEUR******/
    MyGameEngine():m_g1(0){}

    /******PROTOTYPES DES METHODES******/
    virtual void idle();

};
