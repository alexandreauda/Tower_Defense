#include "TowerDefense.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
Mutateur de l'attribut m_blockBase.

@param: La methode setm_blockBase prend un parametre obligatoire: un BlockGrille
-param1: le nouveau block pour m_blockBase
*/
void TowerDefense::setm_blockBase (BlockGrille const& blockBase){
 m_blockBase=blockBase;
}
