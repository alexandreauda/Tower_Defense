#include "MyGraphicEngine.h"

using namespace std;


/******IMPLEMENTATION DES ACCESSEURS******/
//null


/******IMPLEMENTATION DES MUTATEURS******/
//null



/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode Draw de la classe MyGraphicEngine permet de dessiner le damier graphique avec le(s) chemins accesibles ou va se derouler le jeu.

@param: null.
*/
void MyGraphicEngine::Draw(){

    //Si le score du Joueur atteint une valeur superieur ou egale a m_stepLevel*(la valeur du niveau de la grille)
    if(m_currentDrawLevel*m_stepLevel <= m_player->getm_score()){
       m_player->increaseLevel();//On incremente le niveau du Joueur
       m_player->setm_isAttack(false);//Le Joueur n'est plus attaque
    }

    //Si l'attribut m_currentDrawLevel est different du niveau du Joueur
    if(m_currentDrawLevel != m_player->getm_level()){
        //Supprime tous les Monstre present sur la grille de jeu
        (*m_MonstreList).clear();

        //Supprime toutes les Tourelles present sur la grille de jeu
        (*m_TowerDefenseList).clear();

        m_currentDrawLevel=m_player->getm_level();//On set la valeur de l'attribut m_currentDrawLevel a la valeur du niveau du Joueur
    }
    //Sinon, si l'attribut m_currentDrawLevel est identique au niveau du Joueur
    else{

        //Si le player n'est pas mort
        if(m_player->isDead() == 0){

            //On affiche les attributs du Joueur
            m_player->drawAttribut();

            //On affiche la grille de Jeu
            Grille grilleDeJeu;
            grilleDeJeu.draw(m_player->getm_level());

            //On affiche le Store
            Store shop;
            shop.draw();//Draw le Store

            //On affiche le bouton qui sert a lancer les vagues de Monstres
            m_buttonStartMonstre.draw();

            //On affiche le bouton qui sert a sauver un partie
            m_buttonSaveGame.draw();

            //On affiche les tourelles
            for(int i=0;i<m_TowerDefenseList->size();i++){
                (*m_TowerDefenseList)[i]->draw();
            }

            //On affiche les tirs des tourelles
            for(int i=0;i<m_TowerDefenseList->size();i++){
                (*m_TowerDefenseList)[i]->drawTir();
            }


            //On affiche les Monstres
            for(int i=0;i<m_MonstreList->size();i++){
                //Si le Monstre en question n'est pas arrive sur la derniere colonne
                if((*m_MonstreList)[i]->getm_isArrive() == 0){
                    (*m_MonstreList)[i]->draw();
                }
                //Si le Monstre en question est arrive sur la derniere colonne
                else{
                    //supprime l'element (ici, le Monstre)
                    (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                }
                //Si la vie d'un Monstre est inferieur ou egale a 0
                if((*m_MonstreList)[i]->getm_vie() <= 0){
                        //Si le Monstre qui n'a plus de vie est un FastMonstre
                        if((*m_MonstreList)[i]->getClass() == "FastMonstre"){
                            m_player->earnMoney(m_rewardFastMonstre);//Le Joueur gagne une certaine somme d'argent
                            m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                            m_player->increaseScore(m_rewardFastMonstre);//On augmente le score du player
                            //supprime l'element (ici, le Monstre)
                            (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                        }
                        //Sinon, si le Monstre qui n'a plus de vie est un StrongMonstre
                        else if((*m_MonstreList)[i]->getClass() == "StrongMonstre"){//Si le Monstre qui n'a plus de vie est un StrongMonstre
                                m_player->earnMoney(m_rewardStrongMonstre);//Le Joueur gagne une certaine somme d'argent
                                m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                m_player->increaseScore(m_rewardStrongMonstre);//On augmente le score du player
                                //supprime l'element (ici, le Monstre)
                                (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                        }
                        //Sinon, si le Monstre qui n'a plus de vie est un ExplosedFastMonstre
                        else if((*m_MonstreList)[i]->getClass() == "ExplosedFastMonstre"){//Si le Monstre qui n'a plus de vie est un ExplosedFastMonstre
                                m_player->earnMoney(m_rewardExplosedFastMonstre);//Le Joueur gagne une certaine somme d'argent
                                (*m_MonstreList)[i]->drawExplosion();//Le ExplosedFastMonstre trace l'explosion lorsqu'il n'a plus de vie
                                m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                m_player->increaseScore(m_rewardExplosedFastMonstre);//On augmente le score du player
                                //supprime l'element (ici, le Monstre)
                                (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                        }
                        //Sinon, si le Monstre qui n'a plus de vie est un ExplosedStrongMonstre
                        else if((*m_MonstreList)[i]->getClass() == "ExplosedStrongMonstre"){//Si le Monstre qui n'a plus de vie est un ExplosedStrongMonstre
                                m_player->earnMoney(m_rewardExplosedStrongMonstre);//Le Joueur gagne une certaine somme d'argent
                                (*m_MonstreList)[i]->drawExplosion();//Le ExplosedStrongMonstre trace l'explosion lorsqu'il n'a plus de vie
                                m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                m_player->increaseScore(m_rewardExplosedStrongMonstre);//On augmente le score du player
                                //supprime l'element (ici, le Monstre)
                                (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                        }
                        else{
                                m_player->earnMoney(5);//Le Joueur gagne une certaine somme d'argent
                                m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                m_player->increaseScore(5);//On augmente le score du player
                                //supprime l'element (ici, le Monstre)
                                (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                        }
                }
            }
        }
        //Si le Joueur est mort.
        else{
            m_player->gameOver();//On affiche le menu du Game Over
        }
    }
}

