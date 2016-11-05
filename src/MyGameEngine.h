#pragma once

#include "Engine.h"
#include "Monstre.h"

//La Class MyGameEngine herite de la Class GameEngine
class MyGameEngine:public GameEngine {

private:

    /******ATTRIBUT******/
    std::vector <Monstre *> *m_MonstreList;

public:

    /******CONSTRUCTEUR A PARAMETRES******/
    MyGameEngine(std::vector <Monstre *> *MonstreList): m_MonstreList(MonstreList){}

    /******DESTRUCTEUR******/
    virtual ~MyGameEngine() {
        delete m_MonstreList;
    }

    /******ACCESSEURS******/
    //null


    /******MUTATEURS******/
    //null


    /******PROTOTYPES DES METHODES******/
    virtual void idle();

};
