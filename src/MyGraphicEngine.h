#include <vector>
#include "Level.h"
#include "LibMatrix.h"
#include "Grille.h"
#include "Store.h"
#include "TowerDefense.h"
#include "Monstre.h"
#include "BlockStartMonstre.h"
#include "Joueur.h"

//La Class MyGraphicEngine herite de la Class GraphicEngine
class MyGraphicEngine:public GraphicEngine {

private:

    /******ATTRIBUTS******/
    std::vector <Monstre *> *m_MonstreList;
    std::vector <TowerDefense *> *m_TowerDefenseList;
    BlockStartMonstre m_buttonStartMonstre;
    Joueur* m_player;

public:

    /******CONSTRUCTEUR******/
    MyGraphicEngine(std::vector <TowerDefense *> *TowerDefenseList, std::vector <Monstre *> *MonstreList, Joueur* player): m_TowerDefenseList(TowerDefenseList), m_MonstreList(MonstreList), m_buttonStartMonstre(), m_player(player){}

    /******DESTRUCTEUR******/
    virtual ~MyGraphicEngine() {
        delete m_TowerDefenseList;
        delete m_MonstreList;
        delete m_player;
    }


    /******ACCESSEURS******/
    //null


    /******MUTATEURS******/
    //null


    /******PROTOTYPES DES METHODES******/
    virtual void Draw();

};
