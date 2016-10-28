#pragma once
#include "Grille.h"


class TowerDefense{

protected:

    /******ATTRIBUT******/
    BlockGrille m_blockBase;//(objet membre)


public:

    /******CONSTRUCTEUR A PARAMETRES******/
    TowerDefense(BlockGrille blockBase): m_blockBase(blockBase){}


    /******PROTOTYPES DES METHODES******/

    void setm_blockBase(BlockGrille blockBase);//Setteur de l'attribut m_blockBase

    virtual void draw() const = 0; //Methode virtuelle pure


};
