#ifndef STORE_H
#define STORE_H

#include "Block.h"

class Store
{
    private:

        /******ATTRIBUT******/
        float const m_shopCellSize;

    public:

        /******CONSTRUCTEUR PAR DEFAUT******/
        Store(float shopCellSize=0.13):m_shopCellSize(shopCellSize){}


    /******PROTOTYPES DES METHODES******/

    void draw()const;//draw the block


};

#endif // STORE_H
