#pragma once
#include "Grille.h"
#include "TowerDefense.h"
#include "Monstre.h"

//La Class TowerDefenseRicochet herite de la Class TowerDefense
class TowerDefenseRicochet: public TowerDefense{

private:

    /******ATTRIBUT******/
    int m_nbRicochet;
    int m_attackDamage;

public:

    /******CONSTRUCTEUR A PARAMETRES******/
	TowerDefenseRicochet(BlockGrille blockBase, int portee=3, int cadence=10, int timer=0, int attackDamage=4): TowerDefense(blockBase,(blockBase.getm_posx()+blockBase.getm_width()/2),(blockBase.getm_posy()+blockBase.getm_height()/2),(blockBase.getm_posx()+blockBase.getm_width()/2),(blockBase.getm_posy()+blockBase.getm_height()/2),portee,cadence,timer), m_nbRicochet(2), m_attackDamage(attackDamage){}


    /******ACCESSEURS******/
    int getm_nbRicochet() const;//Accesseur de l'attribut m_nbRicochet

    int getm_attackDamage() const;//Accesseur de l'attribut m_attackDamage

    virtual void watchdog(std::vector <Monstre *> *MonstreList);//Etablie la procedure d'attaque des tourelles


    /******MUTATEURS******/
    //null


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie un string avec le nom de la classe actuelle (à savoir ici: "TowerDefenseRicochet")

    virtual void draw() const; //Dessine la tourelle

    virtual void drawTir() const;//Dessine les tirs des tourelles

    void drawTirRicochet(std::vector <Monstre *> *MonstreList) const;//Dessine les tirs des tourelles les ricochets des tirs des tourelles Ricochet

    void attaquer(Monstre* monstreEnnemi, int const& g);

    virtual void attaque(Monstre* monstreEnnemi);


};
