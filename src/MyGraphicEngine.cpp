
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){

    GraphicPrimitives::drawLine2D(x1,0.5,x2,-0.5,1.0,0.0,1.0);//Trace les lignes au debut du jeu
    GraphicPrimitives::drawText2D(str,-1.0,0.9,0.0,0.0, 1.0);//Trace le texte (Clic and Enjoy)

    for (int i = 0; i < paps->size(); i++) {
        (*paps)[i]->draw();
    }


    x1 += vx1;
    if (x1 > 0.9f || x1 < -0.9f) {
        vx1 = -vx1;
        x1 += vx1;
    }

    x2 += vx2;
    if (x2 > 0.9f || x2 < -0.9f) {
        vx2 = -vx2;
        x2 += vx2;
    }


}

