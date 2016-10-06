
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    //Si le bouton gauche de la souris est enfoncé alors...
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        paps->push_back(new Papillon((x-400) / 400.0, (y-300)/ -300.0 ));
    }
}
