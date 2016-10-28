#pragma once
#include "Grille.h"


class TowerDefense{

protected:

    /******ATTRIBUT******/
    BlockGrille m_blockBase;


public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    TowerDefense(): m_blockBase() {}

    /******CONSTRUCTEUR A PARAMETRES******/
    TowerDefense(BlockGrille blockBase): m_blockBase(blockBase) {}


    /******PROTOTYPES DES METHODES******/

    void setm_blockBase(BlockGrille const& blockBase);//Setteur de l'attribut m_blockBase

    virtual void draw() const = 0; //Methode virtuelle pure


};
