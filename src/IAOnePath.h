#pragma once
#include "Grille.h"
#include "MonstreIA.h"


class IAOnePath: public MonstreIA{

private:

    /******ATTRIBUT******/
	int m_iao1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	IAOnePath(): m_iao1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual BlockGrille searchInitWay();

    virtual BlockGrille searchWay();

};
