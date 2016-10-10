#include "Block.h"
//#include "Value.h"
#include <iostream>
using namespace std;


/******IMPLEMENTATION DES METHODES******/
void Block::draw(float r, float g, float  b)
{

    GraphicPrimitives::drawFillRect2D(m_posx,m_posy,m_width,m_height, r, g,  b, m_a);

	//if (airID != Value::airAir)
	//{
    //
	//}
}
