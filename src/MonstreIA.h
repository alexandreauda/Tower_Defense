#pragma once
#include "Grille.h"


class MonstreIA{

protected:

    /******ATTRIBUT******/
    BlockGrille m_actualPosition;
	BlockGrille m_previousPosition;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	MonstreIA(): m_actualPosition(),m_previousPosition(){}


    /******PROTOTYPES DES METHODES******/

    virtual int isEndWay() const = 0; //méthode virtuelle pure

    virtual BlockGrille searchInitWay()= 0; //méthode virtuelle pure

    virtual BlockGrille searchWay(BlockGrille grilleDeJeu[12][12]) const = 0; //méthode virtuelle pure

};
