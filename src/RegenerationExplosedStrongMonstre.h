#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "FastMonstre.h"
#include "ExplosedStrongMonstre.h"
#include "Joueur.h"

//La Class RegenerationExplosedStrongMonstre herite de la Class ExplosedStrongMonstre
class RegenerationExplosedStrongMonstre: public ExplosedStrongMonstre{

protected:

    /******ATTRIBUTS******/
    int m_rateRegeneration;


public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    RegenerationExplosedStrongMonstre(): ExplosedStrongMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeRegenerationExplosedStrongMonstre","InitialLifeMonstre/"), 200.0, 0, 0, 20, 2, 10), m_rateRegeneration(10){}

    /******CONSTRUCTEUR A PARAMETRES******/
	RegenerationExplosedStrongMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeRegenerationExplosedStrongMonstre","InitialLifeMonstre/"), float speed=200.0, int timer=0, int isArrive=0, int damageAttack=20, int portee=2, int damageExplosed=10, int rateRegeneration=10): ExplosedStrongMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack, portee, damageExplosed), m_rateRegeneration(rateRegeneration) {}


    /******DESTRUCTEUR******/
    virtual ~RegenerationExplosedStrongMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class ExplosedStrongMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class ExplosedStrongMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "RegenerationExplosedStrongMonstre")

    virtual void draw(Joueur* player) const; //Dessine le monstre

    void regeneration();

    void increaseRateRegeneration(int const& rateRegenerationWin=1);

    virtual void increaseLevelMonstre(Joueur* player, std::string const& nameAttribut="random", int unsigned const& stepIncrease=1);

    /******PROTOTYPE OPERATEURS******/
    RegenerationExplosedStrongMonstre& operator=(RegenerationExplosedStrongMonstre const& monstreAcopier);

};
