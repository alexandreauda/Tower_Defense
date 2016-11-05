#ifndef STORE_H
#define STORE_H

#include "BlockStore.h"

class Store
{

private:

    /******ATTRIBUT******/
    float m_shopCellWidth;
    float m_shopCellHeight;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    Store(float shopCellWidth=0.13, float shopCellHeight=0.13):m_shopCellWidth(shopCellWidth), m_shopCellHeight(shopCellHeight){}


    /******ACCESSEURS******/
    //null


    /******MUTATEURS******/
    //null


    /******PROTOTYPES DES METHODES******/
    void loadStore(BlockStore stockStore[12]) const;

    void draw() const ;//dessine le Store


};

#endif // STORE_H
