#include "Papillon.h"

void Papillon::draw(){
    GraphicPrimitives::drawFillRect2D(posX,posY,width,height,1.0,1.0,0.0);//PositionX;PositionY;Largeur;Hauteur; R;G;B->Des Papillons
}



void Papillon::tick(){
    posX += VposX;
    if (posX > 1.0 - height || posX < -1.0) {
        VposX = -VposX;
        posX += VposX;
    }

    posY += VposY;
    if (posY > 1.0 - width || posY < -1.0) {
        VposY = -VposY;
        posY += VposY;
    }

    width += Vwidth;
    if (width > 0.4 || width < 0.05) {
        Vwidth = - Vwidth;
        width += Vwidth;
    }

    height += Vheight;
    if (height > 0.2 || height < 0.02) {
        Vheight = - Vheight;
        height += Vheight;
    }
}
