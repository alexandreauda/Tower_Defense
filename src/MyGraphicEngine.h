#include "Level.h"
#include "LibMatrix.h"
#include "Store.h"

class MyGraphicEngine:public GraphicEngine {

protected:

    /******ATTRIBUT******/
    float m_worldWidth;
	float m_worldHeight;
	float m_blockSize;

public:

    /******CONSTRUCTEUR******/
    MyGraphicEngine():m_worldWidth(12),m_worldHeight(12),m_blockSize(0.13){}

    /******PROTOTYPES DES METHODES******/

    virtual void Draw();

};
