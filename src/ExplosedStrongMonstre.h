#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "StrongMonstre.h"
#include "Joueur.h"

//La Class ExplosedFastMonstre herite de la Class StrongMonstre
class ExplosedStrongMonstre: public StrongMonstre{

protected:

    /******ATTRIBUTS******/
    int m_portee;
    int m_damageExplosed;


public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    ExplosedStrongMonstre(): StrongMonstre(new IAOnePath(), 0, 0, 0, 0, 0, 0, 200, 200.0, 0, 0, 20), m_portee(3), m_damageExplosed(10){}

    /******CONSTRUCTEUR A PARAMETRES******/
	ExplosedStrongMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=200, float speed=200.0, int timer=0, int isArrive=0, int damageAttack=20, int portee=3, int damageExplosed=10): StrongMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack), m_portee(portee), m_damageExplosed(damageExplosed) {}


    /******DESTRUCTEUR******/
    virtual ~ExplosedStrongMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class StrongMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class StrongMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "ExplosedStrongMonstre")

    virtual void draw() const; //Dessine le monstre

    void drawExplosion() const; //Dessine l'explosion du monstre

    void watchdog(std::vector <Monstre *> *MonstreList);

    void injuredWhenExplosed(Monstre* monstreEnnemi);

    void explosed(std::vector <Monstre *> *MonstreList);

    /******PROTOTYPE OPERATEURS******/
    ExplosedStrongMonstre& operator=(ExplosedStrongMonstre const& monstreAcopier);

};
