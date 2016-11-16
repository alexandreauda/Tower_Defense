#include "MyGameEngine.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/
//null


/******IMPLEMENTATION DES MUTATEURS******/
//null


/******IMPLEMENTATION DES METHODES******/

void MyGameEngine::idle(){

        //Pour chaque tourelle
        for(int i=0;i<m_TowerDefenseList->size();i++){
            (*m_TowerDefenseList)[i]->watchdog(m_MonstreList);
		}

        //Pour chaque Monstre
        for(int i=0;i<m_MonstreList->size();i++){
            (*m_MonstreList)[i]->walk(m_player);
		}
}
