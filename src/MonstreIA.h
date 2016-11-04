#pragma once
#include "Grille.h"


class MonstreIA{

protected:

    /******ATTRIBUT******/
    BlockGrille m_actualPosition;
	BlockGrille m_previousPosition;
    std::string m_direction;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	MonstreIA(): m_actualPosition(),m_previousPosition(), m_direction("UNKNOWN"){}


    /******PROTOTYPES DES METHODES******/

    virtual BlockGrille searchInitWay(BlockGrille grilleDeJeu[12][12]) const = 0; //Methode virtuelle pure

    virtual BlockGrille searchWay(BlockGrille grilleDeJeu[12][12]) = 0; //Methode virtuelle pure

    virtual std::string getClass() const = 0; //Methode virtuelle pure

    BlockGrille getm_actualPosition() const;//Accesseur de l'attribut m_actualPosition

    BlockGrille getm_previousPosition() const;//Accesseur de l'attribut m_previousPosition

    std::string getm_direction() const;//Accesseur de l'attribut m_direction

    void setm_actualPosition (BlockGrille const& actualPosition);//Setteur de l'attribut m_actualPosition

    void setm_previousPosition (BlockGrille const& previousPosition);//Setteur de l'attribut m_previousPosition

};
