#pragma once
#include "Grille.h"
#include "MonstreIA.h"


class IASeveralPaths: public MonstreIA{

private:

    /******ATTRIBUT******/
	int m_ias1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	IASeveralPaths(): m_ias1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual BlockGrille searchInitWay();

    virtual BlockGrille searchWay();

};
