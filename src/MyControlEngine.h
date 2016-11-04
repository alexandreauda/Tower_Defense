#pragma once
#include <vector>
#include "Engine.h"
#include "Windows.h"
#include "Grille.h"
#include "Store.h"
#include "TowerDefense.h"
#include "TowerDefenseYellow.h"
#include "TowerDefenseOrange.h"
#include "TowerDefensePurple.h"
#include "Monstre.h"
#include "BlockStartMonstre.h"

class MyControlEngine:public ControlEngine {

private:

    /******ATTRIBUT******/
    std::vector <TowerDefense *> *m_TowerDefenseList;
    std::vector <Monstre *> *m_MonstreList;
    int m_stockColorTower; //Permet de stocker une couleur de tourelle dans la souris
    BlockGrille m_grilleDeJeu[12][12];
    BlockStartMonstre m_buttonStartMonstre;

public:

    /******CONSTRUCTEUR A PARAMETRES******/
    MyControlEngine(std::vector <TowerDefense *> *TowerDefenseList, std::vector <Monstre *> *MonstreList): m_TowerDefenseList(TowerDefenseList), m_MonstreList(MonstreList), m_stockColorTower(1), m_buttonStartMonstre(){
    Grille grilleInit;
    grilleInit.loadGrille("Files_Levels/Level_1.txt",m_grilleDeJeu);//Load la matrice m_grilleDeJeu
    }

    /******DESTRUCTEUR******/
    virtual ~MyControlEngine() {
        delete m_TowerDefenseList;
        delete m_MonstreList;
    }

    /******PROTOTYPES DES METHODES******/
    virtual void MouseCallback(int button, int state, int x, int y);

    virtual void KeyboardCallback(unsigned char key,int x, int y);

};
