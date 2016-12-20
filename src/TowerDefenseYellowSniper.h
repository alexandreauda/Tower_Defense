#pragma once
#include "Grille.h"
#include "TowerDefense.h"

//La Class TowerDefenseYellowSniper herite de la Class TowerDefense
class TowerDefenseYellowSniper: public TowerDefense{

private:

    /******ATTRIBUT******/
    int m_tdy1;

public:

    /******CONSTRUCTEUR A PARAMETRES******/
	TowerDefenseYellowSniper(BlockGrille blockBase, int portee=10, int cadence=5, int timer=0): TowerDefense(blockBase,(blockBase.getm_posx()+blockBase.getm_width()/2),(blockBase.getm_posy()+blockBase.getm_height()/2),(blockBase.getm_posx()+blockBase.getm_width()/2),(blockBase.getm_posy()+blockBase.getm_height()/2),portee,cadence,timer), m_tdy1(0){}


    /******ACCESSEURS******/
    //null


    /******MUTATEURS******/
    //null


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie un string avec le nom de la classe actuelle (� savoir ici: "TowerDefenseYellowSniper")

    virtual void draw() const; //Dessine la tourelle

    virtual void drawTir() const;//Dessine les tirs des tourelles

    virtual void attaque(Monstre* monstreEnnemi);


};
