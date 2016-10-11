#include "Block.h"
//#include "Value.h"
#include <iostream>
using namespace std;


/******IMPLEMENTATION DES METHODES******/

void Block::draw()
{
    Value v;

    float const r=0.0;
    float const g=1.0;
    float const b=0.0;

     if (m_grassID == v.getm_groundGrass()){
        GraphicPrimitives::drawFillRect2D(m_posx,m_posy,m_width,m_height, r, g, b, m_a);
    }
    else{
        GraphicPrimitives::drawFillRect2D(m_posx,m_posy,m_width,m_height, 1, 0,  0, m_a);
    }

}


//Setteur de l'attribut m_grassID
void Block::setm_grassID (int grassID){
 m_grassID=grassID;
}
