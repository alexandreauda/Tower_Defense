#pragma once

#include "Engine.h"
#include "Monstre.h"//NEW

class MyGameEngine:public GameEngine {

private:

    /******ATTRIBUT******/
    std::vector <Monstre *> *m_MonstreList;//NEW

public:

    /******CONSTRUCTEUR******/
    MyGameEngine(std::vector <Monstre *> *MonstreList): m_MonstreList(MonstreList){}//NEW

    /******DESTRUCTEUR******/
    virtual ~MyGameEngine() {
        delete m_MonstreList;//NEW
    }

    /******PROTOTYPES DES METHODES******/
    virtual void idle();

};
