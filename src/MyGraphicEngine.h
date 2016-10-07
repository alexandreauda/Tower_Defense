#include "Block.h"

class MyGraphicEngine:public GraphicEngine {

public:

    /******ATTRIBUT******/
    int worldWidth;
	int worldHeight;
	int blockSize;



    /******CONSTRUCTEUR******/
    MyGraphicEngine():GraphicEngine(),worldWidth(12),worldHeight(12),blockSize(52){}

    /******PROTOTYPES DES METHODES******/

    virtual void physic();

    virtual void Draw();

};
