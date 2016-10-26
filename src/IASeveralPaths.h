#pragma once
#include "Grille.h"
#include "MonstreIA.h"


//La Class IASeveralPaths herite de la Class MonstreIA
class IASeveralPaths: public MonstreIA{

private:

    /******ATTRIBUT******/
	int m_ias1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	IASeveralPaths(): MonstreIA(), m_ias1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual BlockGrille searchInitWay();

    virtual BlockGrille searchWay(BlockGrille grilleDeJeu[12][12]) const;

};
