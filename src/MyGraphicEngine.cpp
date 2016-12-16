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

    //Si le Joueur n'est pas dans le Jeu
    if(m_player->getm_isInGame() == false){
        m_menuBeforeGame.draw();//Dessine le menu initial
    }
    //Sinon, si le Joueur est dans le Jeu
    else{

        //Si le niveau du Joueur est different de 0
        if(m_player->getm_level() != 0){
            //Si le score du Joueur atteint une valeur superieur ou egale a m_stepLevel*(la valeur du niveau de la grille)
            if(m_currentDrawLevel*m_stepLevel <= m_player->getm_score()){
               m_player->increaseLevel();//On incremente le niveau du Joueur
               m_player->setm_isAttack(false);//Le Joueur n'est plus attaque
            }
        }
        //Sinon, si le niveau du Joueur est egal a 0
        else{
            //Si le score du Joueur atteint une valeur superieur ou egale a m_stepLevel
            if(m_stepLevel <= m_player->getm_score()){
               m_winLevelJoueur=true;//On set l'attribut m_winLevelJoueur a true
            }
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
            //Si l'attribut m_winLevelJoueur == false
            if(m_winLevelJoueur == false){

                //Si le player n'est pas mort
                if(m_player->isDead() == 0){

                    //On affiche les attributs du Joueur
                    m_player->drawAttribut();

                    //Si le niveau du Joueur est different de 0
                    if(m_player->getm_level() != 0){
                        //On affiche la grille de Jeu
                        Grille grilleDeJeu;
                        grilleDeJeu.draw(m_player->getm_level());
                    }
                    //Sinon, si le niveau du Joueur est egale a 0
                    else{
                        //On affiche la grille de Jeu
                        Grille grilleDeJeu;
                        grilleDeJeu.draw(m_player->getm_level(),"Level_Player/");
                    }

                    //On affiche le Store
                    Store shop;
                    shop.draw();//Draw le Store

                    //On affiche le bouton qui sert a lancer les vagues de Monstres
                    m_buttonStartMonstre.draw();

                    //Si le niveau du Joueur est different de 0
                    if(m_player->getm_level() != 0){
                        //On affiche le bouton qui sert a sauver un partie
                        m_buttonSaveGame.draw();
                    }

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
                            (*m_MonstreList)[i]->draw(m_player);
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
                                //Sinon, si le Monstre qui n'a plus de vie est un RegenerationFastMonstre
                                else if((*m_MonstreList)[i]->getClass() == "RegenerationFastMonstre"){//Si le Monstre qui n'a plus de vie est un RegenerationFastMonstre
                                        m_player->earnMoney(m_rewardRegenerationFastMonstre);//Le Joueur gagne une certaine somme d'argent
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardRegenerationFastMonstre);//On augmente le score du player
                                        //supprime l'element (ici, le Monstre)
                                        (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                                }
                                //Sinon, si le Monstre qui n'a plus de vie est un RegenerationStrongMonstre
                                else if((*m_MonstreList)[i]->getClass() == "RegenerationStrongMonstre"){//Si le Monstre qui n'a plus de vie est un RegenerationStrongMonstre
                                        m_player->earnMoney(m_rewardRegenerationStrongMonstre);//Le Joueur gagne une certaine somme d'argent
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardRegenerationStrongMonstre);//On augmente le score du player
                                        //supprime l'element (ici, le Monstre)
                                        (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                                }
                                //Sinon, si le Monstre qui n'a plus de vie est un RegenerationExplosedFastMonstre
                                else if((*m_MonstreList)[i]->getClass() == "RegenerationExplosedFastMonstre"){//Si le Monstre qui n'a plus de vie est un RegenerationExplosedFastMonstre
                                        m_player->earnMoney(m_rewardRegenerationExplosedFastMonstre);//Le Joueur gagne une certaine somme d'argent
                                        (*m_MonstreList)[i]->drawExplosion();//Le RegenerationExplosedFastMonstre trace l'explosion lorsqu'il n'a plus de vie
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardRegenerationExplosedFastMonstre);//On augmente le score du player
                                        //supprime l'element (ici, le Monstre)
                                        (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                                }
                                //Sinon, si le Monstre qui n'a plus de vie est un RegenerationExplosedStrongMonstre
                                else if((*m_MonstreList)[i]->getClass() == "RegenerationExplosedStrongMonstre"){//Si le Monstre qui n'a plus de vie est un RegenerationExplosedStrongMonstre
                                        m_player->earnMoney(m_rewardRegenerationExplosedStrongMonstre);//Le Joueur gagne une certaine somme d'argent
                                        (*m_MonstreList)[i]->drawExplosion();//Le RegenerationExplosedStrongMonstre trace l'explosion lorsqu'il n'a plus de vie
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardRegenerationExplosedStrongMonstre);//On augmente le score du player
                                        //supprime l'element (ici, le Monstre)
                                        (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                                }
                                //Sinon, si le Monstre qui n'a plus de vie est un ThiefFastMonstre
                                else if((*m_MonstreList)[i]->getClass() == "ThiefFastMonstre"){//Si le Monstre qui n'a plus de vie est un ThiefFastMonstre
                                        m_player->earnMoney(m_rewardThiefFastMonstre);//Le Joueur gagne une certaine somme d'argent
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardThiefFastMonstre);//On augmente le score du player
                                        //supprime l'element (ici, le Monstre)
                                        (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                                }
                                //Sinon, si le Monstre qui n'a plus de vie est un ThiefStrongMonstre
                                else if((*m_MonstreList)[i]->getClass() == "ThiefStrongMonstre"){//Si le Monstre qui n'a plus de vie est un ThiefStrongMonstre
                                        m_player->earnMoney(m_rewardThiefStrongMonstre);//Le Joueur gagne une certaine somme d'argent
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardThiefStrongMonstre);//On augmente le score du player
                                        //supprime l'element (ici, le Monstre)
                                        (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                                }
                                //Sinon, si le Monstre qui n'a plus de vie est un ThiefExplosedFastMonstre
                                else if((*m_MonstreList)[i]->getClass() == "ThiefExplosedFastMonstre"){//Si le Monstre qui n'a plus de vie est un ThiefExplosedFastMonstre
                                        m_player->earnMoney(m_rewardThiefExplosedFastMonstre);//Le Joueur gagne une certaine somme d'argent
                                        (*m_MonstreList)[i]->drawExplosion();//Le ThiefExplosedFastMonstre trace l'explosion lorsqu'il n'a plus de vie
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardThiefExplosedFastMonstre);//On augmente le score du player
                                        //supprime l'element (ici, le Monstre)
                                        (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                                }
                                //Sinon, si le Monstre qui n'a plus de vie est un ThiefExplosedStrongMonstre
                                else if((*m_MonstreList)[i]->getClass() == "ThiefExplosedStrongMonstre"){//Si le Monstre qui n'a plus de vie est un ThiefExplosedStrongMonstre
                                        m_player->earnMoney(m_rewardThiefExplosedStrongMonstre);//Le Joueur gagne une certaine somme d'argent
                                        (*m_MonstreList)[i]->drawExplosion();//Le ThiefExplosedStrongMonstre trace l'explosion lorsqu'il n'a plus de vie
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardThiefExplosedStrongMonstre);//On augmente le score du player
                                        //supprime l'element (ici, le Monstre)
                                        (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                                }
                                //Sinon, si le Monstre qui n'a plus de vie est un ThiefRegenerationFastMonstre
                                else if((*m_MonstreList)[i]->getClass() == "ThiefRegenerationFastMonstre"){//Si le Monstre qui n'a plus de vie est un ThiefRegenerationFastMonstre
                                        m_player->earnMoney(m_rewardThiefRegenerationFastMonstre);//Le Joueur gagne une certaine somme d'argent
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardThiefRegenerationFastMonstre);//On augmente le score du player
                                        //supprime l'element (ici, le Monstre)
                                        (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                                }
                                //Sinon, si le Monstre qui n'a plus de vie est un ThiefRegenerationStrongMonstre
                                else if((*m_MonstreList)[i]->getClass() == "ThiefRegenerationStrongMonstre"){//Si le Monstre qui n'a plus de vie est un ThiefRegenerationStrongMonstre
                                        m_player->earnMoney(m_rewardThiefRegenerationStrongMonstre);//Le Joueur gagne une certaine somme d'argent
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardThiefRegenerationStrongMonstre);//On augmente le score du player
                                        //supprime l'element (ici, le Monstre)
                                        (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                                }
                                //Sinon, si le Monstre qui n'a plus de vie est un ThiefRegenerationExplosedFastMonstre
                                else if((*m_MonstreList)[i]->getClass() == "ThiefRegenerationExplosedFastMonstre"){//Si le Monstre qui n'a plus de vie est un ThiefRegenerationExplosedFastMonstre
                                        m_player->earnMoney(m_rewardThiefRegenerationExplosedFastMonstre);//Le Joueur gagne une certaine somme d'argent
                                        (*m_MonstreList)[i]->drawExplosion();//Le ThiefRegenerationExplosedFastMonstre trace l'explosion lorsqu'il n'a plus de vie
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardThiefRegenerationExplosedFastMonstre);//On augmente le score du player
                                        //supprime l'element (ici, le Monstre)
                                        (*m_MonstreList).erase((*m_MonstreList).begin()+i);
                                }
                                //Sinon, si le Monstre qui n'a plus de vie est un ThiefRegenerationExplosedStrongMonstre
                                else if((*m_MonstreList)[i]->getClass() == "ThiefRegenerationExplosedStrongMonstre"){//Si le Monstre qui n'a plus de vie est un ThiefRegenerationExplosedStrongMonstre
                                        m_player->earnMoney(m_rewardThiefRegenerationExplosedStrongMonstre);//Le Joueur gagne une certaine somme d'argent
                                        (*m_MonstreList)[i]->drawExplosion();//Le ThiefRegenerationExplosedStrongMonstre trace l'explosion lorsqu'il n'a plus de vie
                                        m_player->oneMoreKilled();//On incremente l'attribut m_numberMonstreKilled du player
                                        m_player->increaseScore(m_rewardThiefRegenerationExplosedStrongMonstre);//On augmente le score du player
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
            //Sinon, si l'attribut m_winLevelJoueur == true
            else{
                m_player->winGame();//On affiche le menu du winGame
            }
        }
    }
}

