#pragma once
#include "Engine.h"

class MyControlEngine:public ControlEngine {

    private:

    /******ATTRIBUT******/


public:

    /******CONSTRUCTEUR******/
    MyControlEngine();

    /******PROTOTYPES DES METHODES******/
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
