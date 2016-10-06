#pragma once

#include "Engine.h"
#include "Papillon.h"
class MyGameEngine:public GameEngine {

private:

    /******ATTRIBUT******/
    std::vector<Papillon * > *paps;

public:

    /******CONSTRUCTEUR******/
    MyGameEngine(std::vector<Papillon * > * paps_):paps(paps_){}

    /******PROTOTYPES DES METHODES******/
    virtual void idle();

};
