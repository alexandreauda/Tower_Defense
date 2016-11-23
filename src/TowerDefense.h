#pragma once
#include "Grille.h"
#include "Monstre.h"
#include "LibMatrix.h"


class TowerDefense{

protected:

    /******ATTRIBUT******/
    BlockGrille m_blockBase;//(objet membre)
    float m_centerTowerx;
    float m_centerTowery;
    float m_targetx;
    float m_targety;
    int m_portee;
    int m_cadence;//Attention: plus la valeur de m_cadence est elevee plus la cadence est faible. Inversement, si celle si est faible la cadence de tir sera elevee.
    int m_timer;


public:

    /******CONSTRUCTEUR A PARAMETRES******/
    TowerDefense(BlockGrille blockBase, float centerTowerx, float centerTowery, float targetx, float targety, int portee=1, int cadence=5, int timer=0): m_blockBase(blockBase), m_centerTowerx(centerTowerx), m_centerTowery(centerTowery), m_targetx(targetx), m_targety(targety), m_portee(portee), m_cadence(cadence), m_timer(timer){}


    /******ACCESSEURS******/
    float getm_centerTowerx() const;//Accesseur de l'attribut m_centerTowerx

    float getm_centerTowery() const;//Accesseur de l'attribut m_centerTowery

    float getm_targetx() const;//Accesseur de l'attribut m_targetx

    float getm_targety() const;//Accesseur de l'attribut m_targety

    int getm_portee() const;//Accesseur de l'attribut m_portee

    int getm_cadence() const;//Accesseur de l'attribut m_cadence

    int getm_timer() const;//Accesseur de l'attribut m_timer

    /******MUTATEURS******/
    void setm_blockBase(BlockGrille const& blockBase);//Setteur de l'attribut m_blockBase

    void setm_targetx(float const& targetx);//Setteur de l'attribut m_targetx

    void setm_targety(float const& targety);//Setteur de l'attribut m_targety

    void setm_portee(int const& portee);//Setteur de l'attribut m_portee

    void setm_cadence(int const& cadence);//Setteur de l'attribut m_cadence

    void setm_timer(int const& timer);//Setteur de l'attribut m_timer


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const = 0; //Methode virtuelle pure

    virtual void draw() const = 0; //Methode virtuelle pure

    virtual void drawTir() const = 0;//Methode virtuelle pure

    virtual void attaque(Monstre* monstreEnnemi) = 0;//Methode virtuelle pure

    void watchdog(std::vector <Monstre *> *MonstreList);//Etablie la procedure d'attaque des tourelles

    virtual void drawTirRicochet(std::vector <Monstre *> *MonstreList) const;//Dessine les tirs des tourelles les ricochets des tirs des tourelles Ricochet

};
