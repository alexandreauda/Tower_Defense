#ifndef STORE_H
#define STORE_H


class Store
{
    private:

        /******ATTRIBUT******/
        int const m_shopwidth;
        int const m_buttonSize;
        int const m_cellSpace;

    protected:

    public:

        /******CONSTRUCTEUR PAR DEFAUT******/
        Store():m_shopwidth(8), m_buttonSize(32), m_cellSpace(2){}


    /******PROTOTYPES DES METHODES******/

    void draw()const;//draw the block


};

#endif // STORE_H
