#include "BlockGrille.h"

using namespace std;


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode draw de la classe BlockGrille permet de dessiner des blocs de maniere graphique.

@param: null
*/
void BlockGrille::draw() const
{
    float const alpha=1.0;

     if (m_colorBlockID == 0){ //si le m_colorBlockID du bloc est egale a 0
         //on met les contantes RGB a vert
        float const r=0.0;
        float const g=1.0;
        float const b=0.0;
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha); //on affiche le bloc en carre vert
     }
    else if(m_colorBlockID == 1){ //si le m_colorBlockID du bloc est egale a 1
        //on met les contantes RGB au rouge
        float const r=1.0;
        float const g=0.0;
        float const b=0.0;
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha);//on affiche le bloc en carre rouge
         }
    else{ //si le m_colorBlockID possede toutes autres valeurs
        //on met les contantes RGB au bleu
        float const r=0.0;
        float const g=0.0;
        float const b=1.0;
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha); //on affiche le bloc en carre bleu

    }
}

/*
@description:
La methode pointIsInBlock renvoi 1 si les coordonnées (x,y) sont dans le block et 0 sinon.

@param:  La methode pointIsInBlock prend deux parametres obligatoires: un int, un int.
-param1: Ce premier parametre designe l'abscisse du point que l'on veut tester.
-param2: Ce deuxieme parametre designe l'ordonnee du point que l'on veut tester.
*/
int BlockGrille::pointIsInBlock(int const& x, int const& y) const{
    //Si le point se trouve dans le block
    if((m_posx <= x) && (x <= m_posx+m_width) && (m_posy <= y) && (y <= m_posy+m_height)){
        return 1;//renvoi 1
    }
    //Sinon
    else{
        return 0;//renvoi 0;
    }
}


/*
@description:
La methode pointIsInBlockFree renvoi 1 si les coordonnées (x,y) sont dans le block et que ce dernier est libre et 0 sinon.

@param:  La methode pointIsInBlockFree prend deux parametres obligatoires: un int, un int.
-param1: Ce premier parametre designe l'abscisse du point que l'on veut tester.
-param2: Ce deuxieme parametre designe l'ordonnee du point que l'on veut tester.
*/
int BlockGrille::pointIsInBlockFree(int const& x, int const& y) const{
    int const pointisinblock=pointIsInBlock(x,y);
    //Si le point se trouve dans le block et que le block est libre
    if((pointisinblock == 1) && (m_isFreeID == 0)){
        return 1;//renvoi 1
    }
    //Sinon
    else{
        return 0;//renvoi 0;
    }
}


/*
@description:
Accesseur de l'attribut m_posxID.

@param: null
*/
int BlockGrille::getm_posxID() const{
    return m_posxID;
}

/*
@description:
Accesseur de l'attribut m_posyID.

@param: null
*/
int BlockGrille::getm_posyID() const{
    return m_posyID;
}

/*
@description:
Accesseur de l'attribut m_colorBlockID.

@param: null
*/
int BlockGrille::getm_colorBlockID() const{
    return m_colorBlockID;
}

/*
@description:
Accesseur de l'attribut m_isFreeID.

@param: null
*/
int BlockGrille::getm_isFreeID() const{
    return m_isFreeID;
}


/*
@description:
Mutateur de l'attribut m_posxID.

@param: La methode setm_posxID prend un parametre obligatoire: un int
-param1: le nouvel id pour m_posxID
*/
void BlockGrille::setm_posxID (int const& posxID){
 m_posxID=posxID;
}

/*
@description:
Mutateur de l'attribut m_posyID.

@param: La methode setm_posyID prend un parametre obligatoire: un int
-param1: le nouvel id pour m_posyID
*/
void BlockGrille::setm_posyID (int const& posyID){
 m_posyID=posyID;
}

/*
@description:
Mutateur de l'attribut m_colorBlockID.

@param: La methode setm_colorBlockID prend un parametre obligatoire: un int
-param1: le nouvel id pour m_colorBlockID
*/
void BlockGrille::setm_colorBlockID (int const& colorBlockID){
 m_colorBlockID=colorBlockID;
}

/*
@description:
Mutateur de l'attribut m_isFreeID.

@param: La methode setm_isFreeID prend un parametre obligatoire: un int
-param1: le nouvel id pour m_isFreeID
*/
void BlockGrille::setm_isFreeID (int const& isFreeID){
 m_isFreeID=isFreeID;
}
