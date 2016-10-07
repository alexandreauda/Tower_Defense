#include "Block.h"
//#include "Value.h"
#include <iostream>
using namespace std;


/******IMPLEMENTATION DES METHODES******/
void Block::draw()
{

    GraphicPrimitives::drawFillRect2D(m_posx,m_posy,m_width,m_height, m_r, m_g,  m_b, m_a);
	//if (airID != Value::airAir)
	//{
    //
	//}
}
