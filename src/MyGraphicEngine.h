#include <vector>
#include "Level.h"
#include "LibMatrix.h"
#include "Grille.h"
#include "Store.h"
#include "TowerDefense.h"
#include "TowerDefenseYellow.h"
#include "TowerDefenseOrange.h"
#include "TowerDefensePurple.h"

class MyGraphicEngine:public GraphicEngine {

protected:

    /******ATTRIBUT******/
    std::vector <TowerDefense *> *m_TowerDefenseList;

public:

    /******CONSTRUCTEUR******/
    MyGraphicEngine(std::vector <TowerDefense *> *TowerDefenseList): m_TowerDefenseList(TowerDefenseList){}

    /******DESTRUCTEUR******/
    virtual ~MyGraphicEngine() {
        delete m_TowerDefenseList;
    }

    /******PROTOTYPES DES METHODES******/

    virtual void Draw();

};
