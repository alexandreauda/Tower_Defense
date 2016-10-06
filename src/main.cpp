

#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
using namespace std;


int main(int argc, char * argv[])
{
    char * titre=new char[40]{'T','o','w','e','r',' ','D','e','f','e','n','c','e',' ','P','r','o','j','e','c','t',' ','B','y',' ','A','l','e','x','a','n','d','r','e',' ','A','U','D','A','\0'};
    Engine e(argc,argv,800,600,titre);

    vector<Papillon *> paps;

    GraphicEngine * ge = new MyGraphicEngine(&paps);
    GameEngine * gme = new MyGameEngine(&paps);
    ControlEngine * ce = new MyControlEngine(&paps);

    e.setGraphicEngine(ge);//Trace le contenu dans la fenetre
    e.setGameEngine(gme);//Anime les objet anime du jeu apparaissant dans la fenetre
    e.setControlEngine(ce);//Active les interactions de l'utilisateur (Clic de souris, pression sur touche du clavier,...

    e.start();
    return 0;
}
