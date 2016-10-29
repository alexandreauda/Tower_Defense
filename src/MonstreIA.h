#pragma once
#include "Grille.h"

using namespace std;

class MonstreIA{

protected:

    /******ATTRIBUT******/
    BlockGrille m_actualPosition;
	BlockGrille m_previousPosition;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	MonstreIA(): m_actualPosition(),m_previousPosition(){}


    /******PROTOTYPES DES METHODES******/

    int isEndWay() const;//Renvoie 1 si le monstre est sur la derniere colonne de la grille et 0 sinon

    virtual BlockGrille searchInitWay(BlockGrille grilleDeJeu[12][12]) const = 0; //Methode virtuelle pure

    virtual BlockGrille searchWay(BlockGrille grilleDeJeu[12][12]) const = 0; //Methode virtuelle pure

    virtual string getClass() const = 0; //Methode virtuelle pure

};
