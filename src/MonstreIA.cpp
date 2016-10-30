#include "MonstreIA.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode isEndWay renvoie 1 si le monstre est sur la derniere colonne de la grille et 0 sinon.

@param: null
*/
int MonstreIA::isEndWay() const{
    //Si le monstre se trouve sur la derniere colonne de grille
    if(m_actualPosition.getm_posyID() == 11){
        return 1;//Renvoi 1
    }
    //Sinon
    else{
        return 0;//Renvoi 0
    }
}

/*
@description:
Accesseur de l'attribut m_actualPosition.

@param: null
*/
BlockGrille MonstreIA::getm_actualPosition() const{
    return m_actualPosition;
}

/*
@description:
Accesseur de l'attribut m_previousPosition.

@param: null
*/
BlockGrille MonstreIA::getm_previousPosition() const{
    return m_previousPosition;
}


/*
@description:
Mutateur de l'attribut m_actualPosition.

@param: La methode setm_actualPosition prend un parametre obligatoire: un BlockGrille
-param1: un nouveau block pour m_actualPosition
*/
void MonstreIA::setm_actualPosition (BlockGrille const& actualPosition){
 m_actualPosition=actualPosition;
}

/*
@description:
Mutateur de l'attribut m_previousPosition.

@param: La methode setm_previousPosition prend un parametre obligatoire: un BlockGrille
-param1: un nouveau block pour m_previousPosition
*/
void MonstreIA::setm_previousPosition (BlockGrille const& previousPosition){
 m_previousPosition=previousPosition;
}
