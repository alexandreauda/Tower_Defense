#pragma once

#include "Engine.h"
#include "Monstre.h"
#include "TowerDefense.h"

//La Class MyGameEngine herite de la Class GameEngine
class MyGameEngine:public GameEngine {

private:

    /******ATTRIBUT******/
    std::vector <Monstre *> *m_MonstreList;
    std::vector <TowerDefense *> *m_TowerDefenseList;

public:

    /******CONSTRUCTEUR A PARAMETRES******/
    MyGameEngine(std::vector <TowerDefense *> *TowerDefenseList, std::vector <Monstre *> *MonstreList): m_TowerDefenseList(TowerDefenseList), m_MonstreList(MonstreList){}

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
