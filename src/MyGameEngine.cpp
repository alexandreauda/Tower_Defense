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

        //Si le Joueur a lance une vague de Monstre
        if(m_player->getm_isAttack() == 1){

            if(m_timer%m_varAleatoire == 0){

                int const monstreAleatoire=LibMatrix::varAleatoire(4);

                switch(monstreAleatoire){

                    case 1: m_MonstreList->push_back(new FastMonstre());
                            break;

                    case 2: m_MonstreList->push_back(new StrongMonstre());
                            break;

                    case 3: m_MonstreList->push_back(new ExplosedFastMonstre());
                            break;

                    case 4: m_MonstreList->push_back(new ExplosedStrongMonstre());
                            break;

                    default: m_MonstreList->push_back(new FastMonstre());
                             break;

                }//Fin du switch

                BlockGrille const initBlock=((*m_MonstreList)[m_MonstreList->size()-1]->searchInitPath(grilleBlock));//Le dernier Monstre qui a ete cree cherche l'entree de la grille. La facon dont il cherche l'entree de la grille depend de l'IA du Monstre.

                float const initBlockPosx= initBlock.getm_posx();
                float const initBlockPosy= initBlock.getm_posy();
                float const initBlockWidth= initBlock.getm_width();
                float const initBlockHeight= initBlock.getm_height();

                ((*m_MonstreList)[m_MonstreList->size()-1]->getm_monstreIA())->setm_actualPosition(initBlock);
                ((*m_MonstreList)[m_MonstreList->size()-1]->getm_monstreIA())->setm_previousPosition(initBlock);

                (*m_MonstreList)[m_MonstreList->size()-1]->setm_posx1(initBlockPosx+initBlockWidth/6);
                (*m_MonstreList)[m_MonstreList->size()-1]->setm_posy1(initBlockPosy+initBlockHeight/6);
                (*m_MonstreList)[m_MonstreList->size()-1]->setm_posx2(initBlockPosx+initBlockWidth*5/6);
                (*m_MonstreList)[m_MonstreList->size()-1]->setm_posy2(initBlockPosy+initBlockHeight/2);
                (*m_MonstreList)[m_MonstreList->size()-1]->setm_posx3(initBlockPosx+initBlockWidth/6);
                (*m_MonstreList)[m_MonstreList->size()-1]->setm_posy3(initBlockPosy+initBlockHeight*5/6);

                m_varAleatoire=LibMatrix::varAleatoire(50);
            }

            m_timer++;//On incremente le timer
        }

        //Pour chaque tourelle
        for(int i=0;i<m_TowerDefenseList->size();i++){
            (*m_TowerDefenseList)[i]->watchdog(m_MonstreList);//Surveille et attaque les Monstres
		}

        //Pour chaque Monstre
        for(int i=0;i<m_MonstreList->size();i++){
            //Si il existe un chemin pour que le Monstre puisse continuer (i.e: le Monstre n'est pas dans une impasse)
            if((*m_MonstreList)[i]->searchIfPath(grilleBlock) == 1 || ((*m_MonstreList)[i]->getm_monstreIA()->getm_previousPosition()).getm_posxID() != 11 && ((*m_MonstreList)[i]->getm_isLock() == 0)){
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
