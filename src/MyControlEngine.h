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

class MyControlEngine:public ControlEngine {

private:

    /******ATTRIBUT******/
    std::vector <TowerDefense *> *m_TowerDefenseList;
    int m_stockColorTower; //Permet de stocker une couleur de tourelle dans la souris
    BlockGrille m_grilleDeJeu[12][12];

public:

    /******CONSTRUCTEUR A PARAMETRES******/
    MyControlEngine(std::vector <TowerDefense *> *TowerDefenseList): m_TowerDefenseList(TowerDefenseList), m_stockColorTower(1){
    Grille grilleInit;
    grilleInit.loadGrille("Files_Levels/Level_1.txt",m_grilleDeJeu);//Load la matrice m_grilleDeJeu
    }

    /******PROTOTYPES DES METHODES******/
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
