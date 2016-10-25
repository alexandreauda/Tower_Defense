#pragma once
#include "Grille.h"


class MonstreIA{

protected:

    /******ATTRIBUT******/
    BlockGrille m_actualPosition(); //initialisation
	BlockGrille m_previousPosition();//initialisation
	int m_mi1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	MonstreIA(): m_mi1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual BlockGrille searchInitWay()= 0; //méthode virtuelle pure

    virtual BlockGrille searchWay()= 0; //méthode virtuelle pure

};
