#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"

#include "Windows.h"

using namespace std;


int main(int argc, char * argv[])
{
    char * title=new char[40]{'T','o','w','e','r',' ','D','e','f','e','n','c','e',' ','P','r','o','j','e','c','t',' ','B','y',' ','A','l','e','x','a','n','d','r','e',' ','A','U','D','A','\0'};
    int widht,height;
    Windows dimensionWindows;
    dimensionWindows.loadDimensionWindows("Files_Levels/DimensionWindows.txt",widht, height);
    Engine e(argc,argv,widht,height,title);//definition de la dimension de la fenetre et de son titre

    //Initialisation des objets
    GraphicEngine * ge=new MyGraphicEngine();
    GameEngine * gme=new MyGameEngine();
    ControlEngine * ce=new MyControlEngine();

    //parametrage des objets
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);

    glClearColor(0.3, 0.3, 0.3, 1.0);//Permet de changer la couleur de vidange par défaut du tampon de couleur, qui par defaut est le noir. Cela permet entre autre de changer la couleur de fond de la fenetre.


    //lance l'application
    e.start();


    return 0;
}
