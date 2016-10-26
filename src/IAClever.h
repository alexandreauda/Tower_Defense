#pragma once
#include "Grille.h"
#include "MonstreIA.h"


class IAClever: public MonstreIA{

private:

    /******ATTRIBUT******/
	int m_iac1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	IAClever(): MonstreIA(), m_iac1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual BlockGrille searchInitWay();

    virtual BlockGrille searchWay(BlockGrille grilleDeJeu[12][12]) const;

};
