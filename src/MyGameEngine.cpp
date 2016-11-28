#include "MyGameEngine.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/
//null


/******IMPLEMENTATION DES MUTATEURS******/
//null


/******IMPLEMENTATION DES METHODES******/

void MyGameEngine::idle(){

        //On load le level courant
        Grille grilleDeJeu;
        BlockGrille grilleBlock[12][12];
        grilleDeJeu.loadGrille(m_player->getm_level(), grilleBlock);//On initialise la variable grilleBlock avec la grille du level courant

        //Pour chaque tourelle
        for(int i=0;i<m_TowerDefenseList->size();i++){
            (*m_TowerDefenseList)[i]->watchdog(m_MonstreList);
		}

        //Pour chaque Monstre
        for(int i=0;i<m_MonstreList->size();i++){
            //Si il existe un chemin pour que le Monstre puisse continuer (i.e: le Monstre n'est pas dans une impasse)
            if((*m_MonstreList)[i]->searchIfPath(grilleBlock) == 1){
                (*m_MonstreList)[i]->walk(m_player);
            }
            //Si il n'existe pas de chemin pour que le Monstre puisse continuer (i.e: le Monstre est dans une impasse)
            else{
                //supprime l'element (ici, le Monstre)
                (*m_MonstreList).erase((*m_MonstreList).begin()+i);
            }
		}

        //Pour chaque Monstre qui est un ExplosedFastMonstre
        for(int i=0;i<m_MonstreList->size();i++){
            //Si le Monstre est un ExplosedFastMonstre
            if((*m_MonstreList)[i]->getClass() == "ExplosedFastMonstre" || (*m_MonstreList)[i]->getClass() == "ExplosedStrongMonstre"){
            (*m_MonstreList)[i]->explosed(m_MonstreList);
            }
		}
}
