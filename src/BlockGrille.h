#pragma once
#include "Block.h"

class BlockGrille : public Block {

private:

    /******ATTRIBUTS******/
    int m_posxID;//ID de position en abscisse sur la grille
    int m_posyID;//ID de position en ordonne sur la grille
    int m_isFreeID;//ID indiquant si le block est libre ou pas. m_isFreeID=0 si le block est libre et m_isFreeID=1 si il est occupe (par une tourelle par exemple)
    int m_colorTowerID;//ID indiquant quel est la couleur de tourelle qui se trouve sur le block. Ainsi 0 correspond a qu'il n'y a aucune tourelle sur le block, 1 correspond a ce qu'il y a une tourelle jaune sur le block, 2 correspond a ce qu'il y a une tourelle orange sur le block, 3 correspond a ce qu'il y a une tourelle violette sur le block, ...

public:

    /******CONSTRUCTEUR A PARAMETRES******/
	BlockGrille(float posx=0, float posy=0, float width=0.13, float height=0.13, int posxID=0, int posyID=0, int colorBlockID=0, int isFreeID=0, int colorTowerID=0): Block(posx,posy,width,height,colorBlockID), m_posxID(posxID), m_posyID(posyID), m_isFreeID(isFreeID), m_colorTowerID(colorTowerID){}//constructeur a parametre


    /******ACCESSEURS******/
    int getm_posxID() const;//Accesseur de l'attribut m_posxID

    int getm_posyID() const;//Accesseur de l'attribut m_posyID

    int getm_isFreeID() const;//Accesseur de l'attribut m_isFreeID

    int getm_colorTowerID() const;//Accesseur de l'attribut m_colorTowerID


    /******MUTATEURS******/
    void setm_posxID (int const& posxID);//Setteur de l'attribut m_posxID

    void setm_posyID (int const& posyID);//Setteur de l'attribut m_posyID

    void setm_isFreeID (int const& isFreeID);//Setteur de l'attribut m_isFreeID

    void setm_colorTowerID (int const& colorTowerID);//Setteur de l'attribut m_colorTowerID


    /******PROTOTYPES DES METHODES******/
    virtual void draw() const;//Dessine le block de la grille

    int pointIsInBlockFree(float const& x, float const& y) const;//renvoi 1 si les coordonnées (x,y) sont dans le block et que ce dernier est libre et 0 sinon

};

