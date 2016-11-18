#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "FastMonstre.h"
#include "Joueur.h"

//La Class ExplosedFastMonstre herite de la Class FastMonstre
class ExplosedFastMonstre: public FastMonstre{

protected:

    /******ATTRIBUTS******/
    //float m_targetx;
    //float m_targety;
    int m_portee;
    //int m_cadence;//Attention: plus la valeur de m_cadence est elevee plus la cadence est faible. Inversement, si celle si est faible la cadence de tir sera elevee.


public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    ExplosedFastMonstre(): FastMonstre(new IAOnePath(), 0, 0, 0, 0, 0, 0, 100, 100.0, 0, 0, 10), m_portee(1){}

    /******CONSTRUCTEUR A PARAMETRES******/
	ExplosedFastMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=100, float speed=100.0, int timer=0, int isArrive=0, int damageAttack=20, int portee=1): FastMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack), m_portee(portee) {}


    /******DESTRUCTEUR******/
    virtual ~ExplosedFastMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class FastMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class FastMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "ExplosedFastMonstre")

    virtual void draw() const; //Dessine le monstre

    void drawExplosion() const; //Dessine l'explosion du monstre

    /******PROTOTYPE OPERATEURS******/
    ExplosedFastMonstre& operator=(ExplosedFastMonstre const& monstreAcopier);

};
