#include "Block.h"

class MyGraphicEngine:public GraphicEngine {

public:

    /******ATTRIBUT******/
    int m_worldWidth;
	int m_worldHeight;
	int m_blockSize;



    /******CONSTRUCTEUR******/
    MyGraphicEngine():GraphicEngine(),m_worldWidth(12),m_worldHeight(12),m_blockSize(50){}

    /******PROTOTYPES DES METHODES******/

    //virtual void physic();

    virtual void Draw();

};
