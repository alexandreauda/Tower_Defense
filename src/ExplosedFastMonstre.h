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
    int m_portee;
    int m_damageExplosed;


public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    ExplosedFastMonstre(): FastMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeExplosedFastMonstre","InitialLifeMonstre/"), 100.0, 0, 0, 20), m_portee(3), m_damageExplosed(10){}

    /******CONSTRUCTEUR A PARAMETRES******/
	ExplosedFastMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeExplosedFastMonstre","InitialLifeMonstre/"), float speed=100.0, int timer=0, int isArrive=0, int damageAttack=20, int portee=3, int damageExplosed=10): FastMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack), m_portee(portee), m_damageExplosed(damageExplosed) {}


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

    virtual void draw(Joueur* player) const; //Dessine le monstre

    void drawExplosion() const; //Dessine l'explosion du monstre

    void watchdog(std::vector <Monstre *> *MonstreList);

    void injuredWhenExplosed(Monstre* monstreEnnemi);

    void explosed(std::vector <Monstre *> *MonstreList);

    /******PROTOTYPE OPERATEURS******/
    ExplosedFastMonstre& operator=(ExplosedFastMonstre const& monstreAcopier);

};
