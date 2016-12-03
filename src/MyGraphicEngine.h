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
#include "RegenerationFastMonstre.h"
#include "BlockStartMonstre.h"
#include "BlockSaveGame.h"
#include "Joueur.h"
#include "WindowsBeforeGame.h"

//La Class MyGraphicEngine herite de la Class GraphicEngine
class MyGraphicEngine:public GraphicEngine {

private:

    /******ATTRIBUTS******/
    std::vector <Monstre *> *m_MonstreList;
    std::vector <TowerDefense *> *m_TowerDefenseList;
    BlockStartMonstre m_buttonStartMonstre;
    BlockSaveGame m_buttonSaveGame;
    Joueur* m_player;
    int m_rewardFastMonstre;
    int m_rewardStrongMonstre;
    int m_rewardExplosedFastMonstre;
    int m_rewardExplosedStrongMonstre;
    int m_rewardRegenerationFastMonstre;
    int m_currentDrawLevel;
    int m_stepLevel;
    WindowsBeforeGame m_menuBeforeGame;

public:

    /******CONSTRUCTEUR******/
    MyGraphicEngine(std::vector <TowerDefense *> *TowerDefenseList, std::vector <Monstre *> *MonstreList, Joueur* player): m_TowerDefenseList(TowerDefenseList), m_MonstreList(MonstreList), m_buttonStartMonstre(), m_buttonSaveGame(), m_player(player), m_currentDrawLevel(player->getm_level()), m_menuBeforeGame(){
        m_rewardFastMonstre=LibMatrix::loadIntInFile("RewardMonstre/RewardFastMonstre.txt");
        m_rewardStrongMonstre=LibMatrix::loadIntInFile("RewardMonstre/RewardStrongMonstre.txt");
        m_rewardExplosedFastMonstre=LibMatrix::loadIntInFile("RewardMonstre/RewardExplosedFastMonstre.txt");
        m_rewardExplosedStrongMonstre=LibMatrix::loadIntInFile("RewardMonstre/RewardExplosedStrongMonstre.txt");
        m_rewardRegenerationFastMonstre=LibMatrix::loadIntInFile("RewardMonstre/RewardRegenerationFastMonstre.txt");
        m_stepLevel=LibMatrix::loadIntInFile("StepLevel/StepLevel.txt");
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
