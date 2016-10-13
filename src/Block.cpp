#include "Block.h"

using namespace std;


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode draw de la classe Block permet de dessiner des blocs de maniere graphique.

@param: null
*/
void Block::draw() const
{
    Value v;

    float const r=0.0;
    float const g=1.0;
    float const b=0.0;

     if (m_grassID == v.getm_groundGrass()){ //si le m_grassID du bloc est egale a 0
        GraphicPrimitives::drawFillRect2D(m_posx,m_posy,m_width,m_height, r, g, b, m_a); //on affiche le bloc en carre vert
    }
    else if(m_grassID == 1){ //si le m_grassID du bloc est egale a 1
        GraphicPrimitives::drawFillRect2D(m_posx,m_posy,m_width,m_height, 1, 0,  0, m_a);//on affiche le bloc en carre rouge
    }
    else{ //si le m_grassID possede toutes autres valeurs
        GraphicPrimitives::drawFillRect2D(m_posx,m_posy,m_width,m_height, 0, 0,  1, m_a); //on affiche le bloc en carre bleu

    }

}


/*
@description:
Mutateur de l'attribut m_grassID.

@param: La methode setm_grassID prend un parametre obligatoire: un int
-param1: le nouvel id pour m_grassID
*/
void Block::setm_grassID (int const& grassID){
 m_grassID=grassID;
}
