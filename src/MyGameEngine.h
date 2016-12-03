#pragma once

#include "Engine.h"
#include "Monstre.h"
#include "Grille.h"
#include "TowerDefense.h"
#include "Joueur.h"
#include "ExplosedFastMonstre.h"
#include "ExplosedStrongMonstre.h"
#include "RegenerationFastMonstre.h"

//La Class MyGameEngine herite de la Class GameEngine
class MyGameEngine: public GameEngine {

private:

    /******ATTRIBUT******/
    std::vector <Monstre *> *m_MonstreList;
    std::vector <TowerDefense *> *m_TowerDefenseList;
    Joueur* m_player;
    int m_timer;
    int m_tempsLatanceAleatoire;

public:

    /******CONSTRUCTEUR A PARAMETRES******/
    MyGameEngine(std::vector <TowerDefense *> *TowerDefenseList, std::vector <Monstre *> *MonstreList, Joueur* player): m_TowerDefenseList(TowerDefenseList), m_MonstreList(MonstreList), m_player(player), m_timer(0), m_tempsLatanceAleatoire(1){}

    /******DESTRUCTEUR******/
    virtual ~MyGameEngine() {
        delete m_MonstreList;
        delete m_TowerDefenseList;
        delete m_player;
    }

    /******ACCESSEURS******/
    //null


    /******MUTATEURS******/
    //null


    /******PROTOTYPES DES METHODES******/
    virtual void idle();

};
