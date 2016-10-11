#include <cstdio>
#include <cstdlib>
#include <ctime> //Ne pas oublier d'inclure le fichier ctime
#include "Block.h"

class MyGraphicEngine:public GraphicEngine {

public:

    /******ATTRIBUT******/
    float m_worldWidth;
	float m_worldHeight;
	float m_blockSize;



    /******CONSTRUCTEUR******/
    MyGraphicEngine():m_worldWidth(12),m_worldHeight(12),m_blockSize(0.06){}

    /******PROTOTYPES DES METHODES******/

    //virtual void physic();

    virtual void Draw();

};
