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

        //Pour chaque Monstre qui est un ExplosedFastMonstre
        for(int i=0;i<m_MonstreList->size();i++){
            //Si le Monstre est un ExplosedFastMonstre
            if((*m_MonstreList)[i]->getClass() == "ExplosedFastMonstre" || (*m_MonstreList)[i]->getClass() == "ExplosedStrongMonstre"){
            (*m_MonstreList)[i]->explosed(m_MonstreList);
            }
		}
}
