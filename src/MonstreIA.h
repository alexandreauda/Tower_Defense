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

    virtual BlockGrille searchInitWay(BlockGrille grilleDeJeu[12][12]) const = 0; //Methode virtuelle pure

    virtual BlockGrille searchWay(BlockGrille grilleDeJeu[12][12]) const = 0; //Methode virtuelle pure

    virtual string getClass() const = 0; //Methode virtuelle pure

    BlockGrille getm_actualPosition() const;//Accesseur de l'attribut m_actualPosition

    BlockGrille getm_previousPosition() const;//Accesseur de l'attribut m_previousPosition

    void setm_actualPosition (BlockGrille const& actualPosition);//Setteur de l'attribut m_actualPosition

    void setm_previousPosition (BlockGrille const& previousPosition);//Setteur de l'attribut m_previousPosition

};
