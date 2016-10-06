#pragma once
#include "Engine.h"
#include "Papillon.h"
class MyControlEngine:public ControlEngine {

    private:

    /******ATTRIBUT******/
    std::vector<Papillon * > *paps;

public:

    /******CONSTRUCTEUR******/
    MyControlEngine(std::vector<Papillon * > * paps_):paps(paps_){}

    /******PROTOTYPES DES METHODES******/
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
