#include <vector>
#include "Level.h"
#include "LibMatrix.h"
#include "Grille.h"
#include "Store.h"
#include "TowerDefense.h"
#include "TowerDefenseYellow.h"
#include "TowerDefenseOrange.h"
#include "TowerDefensePurple.h"
#include "Monstre.h"
#include "BlockStartMonstre.h"

class MyGraphicEngine:public GraphicEngine {

private:

    /******ATTRIBUTS******/
    std::vector <Monstre *> *m_MonstreList;
    std::vector <TowerDefense *> *m_TowerDefenseList;
    BlockStartMonstre m_buttonStartMonstre;

public:

    /******CONSTRUCTEUR******/
    MyGraphicEngine(std::vector <TowerDefense *> *TowerDefenseList, std::vector <Monstre *> *MonstreList): m_TowerDefenseList(TowerDefenseList), m_MonstreList(MonstreList), m_buttonStartMonstre(){}

    /******DESTRUCTEUR******/
    virtual ~MyGraphicEngine() {
        delete m_TowerDefenseList;
        delete m_MonstreList;
    }

    /******PROTOTYPES DES METHODES******/

    virtual void Draw();

};
