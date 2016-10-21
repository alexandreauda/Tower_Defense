#include "Level.h"
#include "LibMatrix.h"
#include "Grille.h"
#include "Store.h"

class MyGraphicEngine:public GraphicEngine {

protected:

    /******ATTRIBUT******/
    int m_mg;

public:

    /******CONSTRUCTEUR******/
    MyGraphicEngine():m_mg(0){}

    /******PROTOTYPES DES METHODES******/

    virtual void Draw();

};
