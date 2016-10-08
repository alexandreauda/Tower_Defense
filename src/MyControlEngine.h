#pragma once
#include "Engine.h"

class MyControlEngine:public ControlEngine {

    private:

    /******ATTRIBUT******/
    int c1;

public:

    /******CONSTRUCTEUR******/
    MyControlEngine():c1(0){}

    /******PROTOTYPES DES METHODES******/
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
