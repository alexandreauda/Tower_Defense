#include <vector>
#include "Level.h"
#include "LibMatrix.h"
#include "Grille.h"
#include "Store.h"
#include "TowerDefense.h"
#include "TowerDefenseRicochet.h"
#include "Monstre.h"
#include "ExplosedFastMonstre.h"
#include "ExplosedStrongMonstre.h"
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
    int m_rewardFastMonstre;
    int m_rewardStrongMonstre;
    int m_rewardExplosedFastMonstre;
    int m_rewardExplosedStrongMonstre;

public:

    /******CONSTRUCTEUR******/
    MyGraphicEngine(std::vector <TowerDefense *> *TowerDefenseList, std::vector <Monstre *> *MonstreList, Joueur* player): m_TowerDefenseList(TowerDefenseList), m_MonstreList(MonstreList), m_buttonStartMonstre(), m_player(player){
        m_rewardFastMonstre=LibMatrix::loadIntInFile("RewardMonstre/RewardFastMonstre.txt");
        m_rewardStrongMonstre=LibMatrix::loadIntInFile("RewardMonstre/RewardStrongMonstre.txt");
        m_rewardExplosedFastMonstre=LibMatrix::loadIntInFile("RewardMonstre/RewardExplosedFastMonstre.txt");
        m_rewardExplosedStrongMonstre=LibMatrix::loadIntInFile("RewardMonstre/RewardExplosedStrongMonstre.txt");
    }

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
