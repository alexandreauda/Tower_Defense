#pragma once
#include "Engine.h"

class MyControlEngine:public ControlEngine {

    private:

    /******ATTRIBUT******/
    int m_c1;

public:

    /******CONSTRUCTEUR******/
    MyControlEngine():m_c1(0){}

    /******PROTOTYPES DES METHODES******/
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
