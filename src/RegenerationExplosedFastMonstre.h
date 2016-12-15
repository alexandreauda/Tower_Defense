#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "FastMonstre.h"
#include "ExplosedFastMonstre.h"
#include "Joueur.h"

//La Class RegenerationExplosedFastMonstre herite de la Class ExplosedFastMonstre
class RegenerationExplosedFastMonstre: public ExplosedFastMonstre{

protected:

    /******ATTRIBUTS******/
    int m_rateRegeneration;


public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    RegenerationExplosedFastMonstre(): ExplosedFastMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeRegenerationExplosedFastMonstre","InitialLifeMonstre/"), 100.0, 0, 0, 20, 2, 10), m_rateRegeneration(10){}

    /******CONSTRUCTEUR A PARAMETRES******/
	RegenerationExplosedFastMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeRegenerationExplosedFastMonstre","InitialLifeMonstre/"), float speed=100.0, int timer=0, int isArrive=0, int damageAttack=20, int portee=2, int damageExplosed=10, int rateRegeneration=10): ExplosedFastMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack, portee, damageExplosed), m_rateRegeneration(rateRegeneration) {}


    /******DESTRUCTEUR******/
    virtual ~RegenerationExplosedFastMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class ExplosedFastMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class ExplosedFastMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "RegenerationExplosedFastMonstre")

    virtual void draw(Joueur* player) const; //Dessine le monstre

    void regeneration();

    void increaseRateRegeneration(int const& rateRegenerationWin=1);

    virtual void increaseLevelMonstre(Joueur* player, std::string const& nameAttribut="random", int unsigned const& stepIncrease=1);

    /******PROTOTYPE OPERATEURS******/
    RegenerationExplosedFastMonstre& operator=(RegenerationExplosedFastMonstre const& monstreAcopier);

};
