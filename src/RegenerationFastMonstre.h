#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "FastMonstre.h"
#include "Joueur.h"

//La Class RegenerationFastMonstre herite de la Class FastMonstre
class RegenerationFastMonstre: public FastMonstre{

protected:

    /******ATTRIBUTS******/
    int m_rateRegeneration;


public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    RegenerationFastMonstre(): FastMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeRegenerationFastMonstre","InitialLifeMonstre/"), 100.0, 0, 0, 10), m_rateRegeneration(10){}

    /******CONSTRUCTEUR A PARAMETRES******/
	RegenerationFastMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeRegenerationFastMonstre","InitialLifeMonstre/"), float speed=100.0, int timer=0, int isArrive=0, int damageAttack=10, int rateRegeneration=10): FastMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack), m_rateRegeneration(rateRegeneration) {}


    /******DESTRUCTEUR******/
    virtual ~RegenerationFastMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class FastMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class FastMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "RegenerationFastMonstre")

    virtual void draw(Joueur* player) const; //Dessine le monstre

    void regeneration();

    void increaseRateRegeneration(int const& rateRegenerationWin=1);

    virtual void increaseLevelMonstre(Joueur* player, std::string const& nameAttribut="random", int unsigned const& stepIncrease=1);

    /******PROTOTYPE OPERATEURS******/
    RegenerationFastMonstre& operator=(RegenerationFastMonstre const& monstreAcopier);

};
