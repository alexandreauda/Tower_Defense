#include "Block.h"
#include "Value.h"

Block::Block(int posx, int posy, int width, int height, float r, float g, float  b, float a, int groundID, int airID)
{
	this->groundID = groundID;
	this->airID = airID;
	this->posx= posx;
	this->posy= posy;
	this->width= width;
	this->height= height;
	this->r= r;
	this->g= g;
	this->b= b;
	this->a= a;


}

void Block::draw()
{
    drawFillRect2D(posx,posy,width,height, r, g,  b, a);
	if (airID != Value::airAir)
	{

	}
}
