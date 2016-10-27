#include "BlockStore.h"

using namespace std;


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode draw de la classe BlockStore permet de dessiner des blocs de maniere graphique.

@param: null
*/
void BlockStore::draw() const
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
int BlockStore::pointIsInBlock(int const& x, int const& y) const{
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
Accesseur de l'attribut m_posID.

@param: null
*/
int BlockStore::getm_posID() const{
    return m_posID;
}


/*
@description:
Mutateur de l'attribut m_posID.

@param: La methode setm_posID prend un parametre obligatoire: un int
-param1: le nouvel id pour m_posID
*/
void BlockStore::setm_posID (int const& posID){
 m_posID=posID;
}


/*
@description:
Mutateur de l'attribut m_colorBlockID.

@param: La methode setm_colorBlockID prend un parametre obligatoire: un int
-param1: le nouvel id pour m_colorBlockID
*/
void BlockStore::setm_colorBlockID (int const& colorBlockID){
 m_colorBlockID=colorBlockID;
}
