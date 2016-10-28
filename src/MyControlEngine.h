#pragma once
#include "Engine.h"
#include "Windows.h"
#include "Grille.h"
#include "Store.h"
#include "TowerDefense.h"
#include "TowerDefenseYellow.h"
#include "TowerDefenseOrange.h"
#include "TowerDefensePurple.h"

class MyControlEngine:public ControlEngine {

private:

    /******ATTRIBUT******/
    int m_stockColorTower;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    MyControlEngine():m_stockColorTower(0){}

    /******PROTOTYPES DES METHODES******/
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
