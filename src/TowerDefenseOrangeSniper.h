#pragma once
#include "Grille.h"
#include "TowerDefense.h"

//La Class TowerDefenseOrangeSniper herite de la Class TowerDefense
class TowerDefenseOrangeSniper: public TowerDefense{

private:

    /******ATTRIBUT******/
    int m_tdo1;

public:

    /******CONSTRUCTEUR A PARAMETRES******/
	TowerDefenseOrangeSniper(BlockGrille blockBase, int portee=10, int cadence=10, int timer=0): TowerDefense(blockBase,blockBase.getm_posx()+blockBase.getm_width()/2,blockBase.getm_posy()+blockBase.getm_height()/2,blockBase.getm_posx()+blockBase.getm_width()/2,blockBase.getm_posy()+blockBase.getm_height()/2,portee,cadence,timer), m_tdo1(0){}


    /******ACCESSEURS******/
    //null


    /******MUTATEURS******/
    //null


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie un string avec le nom de la classe actuelle (à savoir ici: "TowerDefenseOrangeSniper")

    virtual void draw() const; //Dessine la tourelle

    virtual void drawTir() const;//Dessine les tirs des tourelles

    virtual void attaque(Monstre* monstreEnnemi);


};
