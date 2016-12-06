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

            //Si le timer modulo (le temps de latance aleatoire) est egal a 0
            if(m_timer%m_tempsLatanceAleatoire == 0){

                int const monstreAleatoire=LibMatrix::varAleatoire(16);//Variable permettant d'avoir une creation aleatoire de type de Monstre

                //Suivant le nombre aleatoire
                switch(monstreAleatoire){

                    case 1: m_MonstreList->push_back(new FastMonstre());//On cree un Monstre de type FastMonstre
                            break;

                    case 2: m_MonstreList->push_back(new StrongMonstre());//On cree un Monstre de type StrongMonstre
                            break;

                    case 3: m_MonstreList->push_back(new ExplosedFastMonstre());//On cree un Monstre de type ExplosedFastMonstre
                            break;

                    case 4: m_MonstreList->push_back(new ExplosedStrongMonstre());//On cree un Monstre de type ExplosedStrongMonstre
                            break;

                    case 5: m_MonstreList->push_back(new RegenerationFastMonstre());//On cree un Monstre de type RegenerationFastMonstre
                            break;

                    case 6: m_MonstreList->push_back(new RegenerationStrongMonstre());//On cree un Monstre de type RegenerationStrongMonstre
                            break;

                    case 7: m_MonstreList->push_back(new RegenerationExplosedFastMonstre());//On cree un Monstre de type RegenerationExplosedFastMonstre
                            break;

                    case 8: m_MonstreList->push_back(new RegenerationExplosedStrongMonstre());//On cree un Monstre de type RegenerationExplosedStrongMonstre
                            break;

                    case 9: m_MonstreList->push_back(new ThiefFastMonstre());//On cree un Monstre de type ThiefFastMonstre
                            break;

                    case 10: m_MonstreList->push_back(new ThiefStrongMonstre());//On cree un Monstre de type ThiefStrongMonstre
                             break;

                    case 11: m_MonstreList->push_back(new ThiefExplosedFastMonstre());//On cree un Monstre de type ThiefExplosedFastMonstre
                             break;

                    case 12: m_MonstreList->push_back(new ThiefExplosedStrongMonstre());//On cree un Monstre de type ThiefExplosedStrongMonstre
                             break;

                    case 13: m_MonstreList->push_back(new ThiefRegenerationFastMonstre());//On cree un Monstre de type ThiefRegenerationFastMonstre
                             break;

                    case 14: m_MonstreList->push_back(new ThiefRegenerationStrongMonstre());//On cree un Monstre de type ThiefRegenerationStrongMonstre
                             break;

                    case 15: m_MonstreList->push_back(new ThiefRegenerationExplosedFastMonstre());//On cree un Monstre de type ThiefRegenerationExplosedFastMonstre
                             break;

                    case 16: m_MonstreList->push_back(new ThiefRegenerationExplosedStrongMonstre());//On cree un Monstre de type ThiefRegenerationExplosedStrongMonstre
                             break;

                    default: m_MonstreList->push_back(new FastMonstre());//On cree un Monstre de type FastMonstre
                             break;

                }//Fin du switch

                BlockGrille const initBlock=((*m_MonstreList)[m_MonstreList->size()-1]->searchInitPath(grilleBlock));//Le dernier Monstre qui a ete cree cherche l'entree de la grille. La facon dont il cherche l'entree de la grille depend de l'IA du Monstre.

                //Block d'instruction permettant de positionner correctement les Monstres a leur creation
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

                (*m_MonstreList)[m_MonstreList->size()-1]->increaseLevelMonstre(m_player, "random", 1);//Ajustement du niveau des Monstres

                m_tempsLatanceAleatoire=LibMatrix::varAleatoireBetweenTwoNumbers(100,300);//Definit le temps de latance entre deux creations de Monstres

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

        //Pour chaque Monstre qui est un ExplosedFastMonstre ou un ExplosedStrongMonstre ou un RegenerationExplosedFastMonstre ou un RegenerationExplosedStrongMonstre ou un ThiefExplosedFastMonstre ou un ThiefExplosedStrongMonstre ou un ThiefRegenerationExplosedFastMonstre ou un ThiefRegenerationExplosedStrongMonstre
        for(int i=0;i<m_MonstreList->size();i++){
            //Si le Monstre est un ExplosedFastMonstre
            if((*m_MonstreList)[i]->getClass() == "ExplosedFastMonstre" || (*m_MonstreList)[i]->getClass() == "ExplosedStrongMonstre" || (*m_MonstreList)[i]->getClass() == "RegenerationExplosedFastMonstre" || (*m_MonstreList)[i]->getClass() == "RegenerationExplosedStrongMonstre" || (*m_MonstreList)[i]->getClass() == "ThiefExplosedFastMonstre" || (*m_MonstreList)[i]->getClass() == "ThiefExplosedStrongMonstre" || (*m_MonstreList)[i]->getClass() == "ThiefRegenerationExplosedFastMonstre" || (*m_MonstreList)[i]->getClass() == "ThiefRegenerationExplosedStrongMonstre"){
            (*m_MonstreList)[i]->explosed(m_MonstreList);
            }
		}

        //Pour chaque Monstre qui est un RegenerationFastMonstre ou un RegenerationStrongMonstre ou un RegenerationExplosedFastMonstre ou un RegenerationExplosedStrongMonstre ou un ThiefRegenerationFastMonstre ou un ThiefRegenerationExplosedFastMonstre ou un ThiefRegenerationExplosedStrongMonstre
        for(int i=0;i<m_MonstreList->size();i++){
            //Si le Monstre est un RegenerationFastMonstre
            if((*m_MonstreList)[i]->getClass() == "RegenerationFastMonstre" || (*m_MonstreList)[i]->getClass() == "RegenerationStrongMonstre" || (*m_MonstreList)[i]->getClass() == "RegenerationExplosedFastMonstre" || (*m_MonstreList)[i]->getClass() == "RegenerationExplosedStrongMonstre" || (*m_MonstreList)[i]->getClass() == "ThiefRegenerationFastMonstre" || (*m_MonstreList)[i]->getClass() == "ThiefRegenerationStrongMonstre" || (*m_MonstreList)[i]->getClass() == "ThiefRegenerationExplosedFastMonstre" || (*m_MonstreList)[i]->getClass() == "ThiefRegenerationExplosedStrongMonstre"){
            (*m_MonstreList)[i]->regeneration();//Les Monstres se regenere
            }
		}
}
