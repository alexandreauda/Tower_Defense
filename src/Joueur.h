#pragma once
#include "Grille.h"
#include "LibMatrix.h"


class Joueur{

private:

    /******ATTRIBUT******/
    int m_vie;
    int m_argent;
    int m_level;
    //int m_matLevel[12][12];


public:

    /******CONSTRUCTEUR A PARAMETRES******/
    Joueur(int vie=100, int argent=100, int level=1): m_vie(vie), m_argent(argent), m_level(level){
    //LibMatrix::loadLevelByInt(level,m_matLevel);
    }


    /******ACCESSEURS******/
    int getm_vie() const;//Accesseur de l'attribut m_vie

    int getm_argent() const;//Accesseur de l'attribut m_argent

    int getm_level() const;//Accesseur de l'attribut m_level

    /******MUTATEURS******/
    void setm_vie(int const& vie);//Setteur de l'attribut m_vie

    void setm_argent(int const& argent);//Setteur de l'attribut m_argent

    void setm_level(int const& level);//Setteur de l'attribut m_level


    /******PROTOTYPES DES METHODES******/
    void drawAttribut() const;

};
