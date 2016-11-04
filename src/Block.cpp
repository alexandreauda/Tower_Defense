#include "Block.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/

/*
@description:
Accesseur de l'attribut m_posx.

@param: null
*/
float Block::getm_posx() const{
    return m_posx;
}

/*
@description:
Accesseur de l'attribut m_posy.

@param: null
*/
float Block::getm_posy() const{
    return m_posy;
}

/*
@description:
Accesseur de l'attribut m_width.

@param: null
*/
float Block::getm_width() const{
    return m_width;
}

/*
@description:
Accesseur de l'attribut m_height.

@param: null
*/
float Block::getm_height() const{
    return m_height;
}


/*
@description:
Accesseur de l'attribut m_colorBlockID.

@param: null
*/
int Block::getm_colorBlockID() const{
    return m_colorBlockID;
}

/******IMPLEMENTATION DES MUTATEURS******/

/*
@description:
Mutateur de l'attribut m_colorBlockID.

@param: La methode setm_colorBlockID prend un parametre obligatoire: un int
-param1: le nouvel id pour m_colorBlockID
*/
void Block::setm_colorBlockID (int const& colorBlockID){
 m_colorBlockID=colorBlockID;
}


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode pointIsInBlock renvoie 1 si les coordonnées (x,y) sont dans le block et 0 sinon.

@param:  La methode pointIsInBlock prend deux parametres obligatoires: un float, un float.
-param1: Ce premier parametre designe l'abscisse du point que l'on veut tester.
-param2: Ce deuxieme parametre designe l'ordonnee du point que l'on veut tester.
*/
int Block::pointIsInBlock(float const& x, float const& y) const{
    //Si le point se trouve dans le block
    if((m_posx <= x) && (x <= m_posx+m_width) && (m_posy <= y) && (y <= m_posy+m_height)){
        return 1;//renvoi 1
    }
    //Sinon
    else{
        return 0;//renvoi 0;
    }
}
