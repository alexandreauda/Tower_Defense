#include "MonstreIA.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/

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
Accesseur de l'attribut m_direction.

@param: null
*/
string MonstreIA::getm_direction() const{
    return m_direction;
}


/******IMPLEMENTATION DES MUTATEURS******/

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


/******IMPLEMENTATION DES METHODES******/
//Methode virtuelle pure

