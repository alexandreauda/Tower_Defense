#pragma once
#include "BlockNewGame.h"
#include "BlockLoadGame.h"

class WindowsBeforeGame{

private:

    /******ATTRIBUT******/
    int m_wbg;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    WindowsBeforeGame(): m_wbg(0){}


    /******ACCESSEURS******/
    //null


    /******MUTATEURS******/
    //null


    /******PROTOTYPES DES METHODES******/
    void draw() const ;//dessine le menu avant le Jeu


};
