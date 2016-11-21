#include "TowerDefense.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/

/*
@description:
Accesseur de l'attribut m_centerTowerx.

@param: null
*/
float TowerDefense::getm_centerTowerx() const{
    return m_centerTowerx;
}

/*
@description:
Accesseur de l'attribut m_centerTowery.

@param: null
*/
float TowerDefense::getm_centerTowery() const{
    return m_centerTowery;
}

/*
@description:
Accesseur de l'attribut m_targetx.

@param: null
*/
float TowerDefense::getm_targetx() const{
    return m_targetx;
}

/*
@description:
Accesseur de l'attribut m_targety.

@param: null
*/
float TowerDefense::getm_targety() const{
    return m_targety;
}

/*
@description:
Accesseur de l'attribut m_portee.

@param: null
*/
int TowerDefense::getm_portee() const{
    return m_portee;
}

/*
@description:
Accesseur de l'attribut m_cadence.

@param: null
*/
int TowerDefense::getm_cadence() const{
    return m_cadence;
}

/*
@description:
Accesseur de l'attribut m_timer.

@param: null
*/
int TowerDefense::getm_timer() const{
    return m_timer;
}

/******IMPLEMENTATION DES MUTATEURS******/

/*
@description:
Mutateur de l'attribut m_blockBase.

@param: La methode setm_blockBase prend un parametre obligatoire: un BlockGrille
-param1: le nouveau block pour m_blockBase
*/
void TowerDefense::setm_blockBase (BlockGrille const& blockBase){
 m_blockBase=blockBase;
}

/*
@description:
Mutateur de l'attribut m_targetx.

@param: La methode setm_targetx prend un parametre obligatoire: un float
-param1: le nouveau float pour m_targetx
*/
void TowerDefense::setm_targetx (float const& targetx){
 m_targetx=targetx;
}

/*
@description:
Mutateur de l'attribut m_targety.

@param: La methode setm_targety prend un parametre obligatoire: un float
-param1: le nouveau float pour m_targety
*/
void TowerDefense::setm_targety (float const& targety){
 m_targety=targety;
}

/*
@description:
Mutateur de l'attribut m_portee.

@param: La methode setm_portee prend un parametre obligatoire: un int
-param1: le nouveau int pour m_portee
*/
void TowerDefense::setm_portee(int const& portee){
 m_portee=portee;
}

/*
@description:
Mutateur de l'attribut m_cadence.

@param: La methode setm_cadence prend un parametre obligatoire: un int
-param1: le nouveau int pour m_cadence
*/
void TowerDefense::setm_cadence(int const& cadence){
 m_cadence=cadence;
}

/*
@description:
Mutateur de l'attribut m_timer.

@param: La methode setm_timer prend un parametre obligatoire: un int
-param1: le nouveau int pour m_timer
*/
void TowerDefense::setm_timer(int const& timer){
 m_timer=timer;
}


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode watchdog de la classe TowerDefense etablie la procedure d'attaque des tourelles.

@param: La methode watchdog prend un parametre obligatoire: un pointeur sur un vecteur de pointeur de type Monstre.
-param1: Le pointeur sur un vecteur de pointeur de type Monstre qui contient la liste de tout les Monstres present sur la grille
*/
void TowerDefense::watchdog(vector <Monstre *> *MonstreList){
    float distanceTowerMonstre=10.0;
    float currentDistanceTowerMonstre=0.0;
    int index=0;

    //Si il n'y a pas de Monstre sur la grille
    if(MonstreList->size() == 0){
        m_targetx=m_centerTowerx;//On place le target sur le centre de la tourelle
        m_targety=m_centerTowery;//On place le target sur le centre de la tourelle
    }
    //Sinon
    else{
        //Pour chaque Monstre present sur la grille
        for(int i=0;i<MonstreList->size();i++){
            //Mettre a jour la variable currentDistanceTowerMonstre qui est la distance entre le centre de la tourelle et le centre du Monstre courant
            currentDistanceTowerMonstre=LibMatrix::distanceBetweenPoint(m_centerTowerx,m_centerTowery,(*MonstreList)[i]->monsterCenterx(),(*MonstreList)[i]->monsterCentery());

            //Si la distance entre le centre de la tourelle et le Monstre courant est inferieur strictement avec la plus petite distance entre le centre de la tourelle et un Monstre touvee jusqu'a present, et que cette distance est inferieur a m_portee*(distance entre le centre de deux blocks positionnes en diagonnal).
            if((currentDistanceTowerMonstre<distanceTowerMonstre) && (currentDistanceTowerMonstre<=(m_portee*sqrt(m_blockBase.getm_width()*m_blockBase.getm_width()+m_blockBase.getm_height()*m_blockBase.getm_height())))){
                distanceTowerMonstre=currentDistanceTowerMonstre;
                index=i;//On retient l'index ou est situe le Monstre le plus proche de la tourelle
            }
        }//Fin de la boucle for
        //Si m_timer modulo m_cadence est egale a 0 et que la distance entre la tourelle et le monstre est inferieur a m_portee*(distance entre le centre de deux blocks positionnes en diagonnal) -> Formule donnee par l'application du theoreme de Pythagore en fonction de la largeur et de la hauteur des blocks.
        if(m_timer%m_cadence == 0 && distanceTowerMonstre<=(m_portee*sqrt(m_blockBase.getm_width()*m_blockBase.getm_width()+m_blockBase.getm_height()*m_blockBase.getm_height()))){
            //Si la tourelle n'est pas une tourelle violette
            if(this->getClass() != "TowerDefensePurple"){
                m_targetx=(*MonstreList)[index]->monsterCenterx();//On met a jour le target de la tourelle qui se place au centre du Monstre
                m_targety=(*MonstreList)[index]->monsterCentery();//On met a jour le target de la tourelle qui se place au centre du Monstre
                this->attaque((*MonstreList)[index]);//La tourelle attaque le Monstre le plus proche d'elle
                m_timer++;//On incremente le compteur
            }
            //Si la tourelle est une tourelle violette
            else{
                //Si le Monstre est au centre d'un block
                if((*MonstreList)[index]->getm_timer()%(int)(*MonstreList)[index]->getm_speed() == 0){
                    m_targetx=(*MonstreList)[index]->monsterCenterx();//On met a jour le target de la tourelle qui se place au centre du Monstre
                    m_targety=(*MonstreList)[index]->monsterCentery();//On met a jour le target de la tourelle qui se place au centre du Monstre
                    this->attaque((*MonstreList)[index]);//La tourelle attaque le Monstre le plus proche d'elle et ralenti donc le Monstre
                    m_timer++;//On incremente le compteur
                }
                //Si le Monstre n'est pas au centre d'un block
                else{
                    //on trace un trait (c'est plus visuelle ainsi) mais on n'attaque pas!
                    m_targetx=(*MonstreList)[index]->monsterCenterx();//On met a jour le target de la tourelle qui se place au centre du Monstre
                    m_targety=(*MonstreList)[index]->monsterCentery();//On met a jour le target de la tourelle qui se place au centre du Monstre
                }
            }
        }
        //Sinon
        else{
            m_targetx=m_centerTowerx;//On place le target sur le centre de la tourelle
            m_targety=m_centerTowery;//On place le target sur le centre de la tourelle
            m_timer++;//On incremente le compteur
        }
    }
}

/*
@description:
Methode qui sera override si la Tower Defense est du type TowerDefenseRicochet.
*/
void TowerDefense::drawTirRicochet(std::vector <Monstre *> *MonstreList) const{

}
