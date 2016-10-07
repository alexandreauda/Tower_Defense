

#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
using namespace std;


int main(int argc, char * argv[])
{
    char * title=new char[40]{'T','o','w','e','r',' ','D','e','f','e','n','c','e',' ','P','r','o','j','e','c','t',' ','B','y',' ','A','l','e','x','a','n','d','r','e',' ','A','U','D','A','\0'};
    double const height=800,widht=600;
    Engine e(argc,argv,height,widht,title);


    //GraphicEngine * ge = new MyGraphicEngine();
    GameEngine * gme = new MyGameEngine();
    ControlEngine * ce = new MyControlEngine();

    e.setGraphicEngine(ge);//Trace le contenu dans la fenetre
    e.setGameEngine(gme);//Anime les objet anime du jeu apparaissant dans la fenetre
    e.setControlEngine(ce);//Active les interactions de l'utilisateur (Clic de souris, pression sur touche du clavier,...

    e.start();
    return 0;
}
