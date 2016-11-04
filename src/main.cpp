#include <iostream>
#include <vector>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"

#include "TowerDefense.h"
#include "Monstre.h"

#include "Windows.h"

using namespace std;


int main(int argc, char * argv[])
{
    char * title=new char[40]{'T','o','w','e','r',' ','D','e','f','e','n','c','e',' ','P','r','o','j','e','c','t',' ','B','y',' ','A','l','e','x','a','n','d','r','e',' ','A','U','D','A','\0'};
    float widthWindows,heigthWindows;
    Windows dimensionWindows;
    dimensionWindows.loadDimensionWindows("Files_Levels/DimensionWindows.txt",widthWindows, heigthWindows);//on initialise les variables widthWindows et heigthWindows avec les valeurs lues dans le fichier

    vector <TowerDefense *> m_TowerDefenseList;
    vector <Monstre *> m_MonstreList;//NEW

    Engine e(argc,argv,widthWindows,heigthWindows,title);//definition de la dimension de la fenetre et de son titre

    //Initialisation des objets
    GraphicEngine * ge=new MyGraphicEngine(&m_TowerDefenseList, &m_MonstreList);//NEW
    GameEngine * gme=new MyGameEngine(&m_MonstreList);//NEW
    ControlEngine * ce=new MyControlEngine(&m_TowerDefenseList,&m_MonstreList);//NEW

    //parametrage des objets
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);

    glClearColor(0.3, 0.3, 0.3, 1.0);//Permet de changer la couleur de vidange par défaut du tampon de couleur, qui par defaut est le noir. Cela permet entre autre de changer la couleur de fond de la fenetre.


    //lance l'application
    e.start();


    return 0;
}
