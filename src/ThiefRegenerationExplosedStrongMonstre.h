#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "StrongMonstre.h"
#include "ExplosedStrongMonstre.h"
#include "RegenerationExplosedStrongMonstre.h"
#include "Joueur.h"

//La Class ThiefRegenerationExplosedStrongMonstre herite de la Class RegenerationExplosedStrongMonstre
class ThiefRegenerationExplosedStrongMonstre: public RegenerationExplosedStrongMonstre{

protected:

    /******ATTRIBUTS******/
    int m_moneyStolen;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    ThiefRegenerationExplosedStrongMonstre(): RegenerationExplosedStrongMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefRegenerationExplosedStrongMonstre","InitialLifeMonstre/"), 200.0, 0, 0, 10, 2, 5, 10), m_moneyStolen(50){}

    /******CONSTRUCTEUR A PARAMETRES******/
	ThiefRegenerationExplosedStrongMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefRegenerationExplosedStrongMonstre","InitialLifeMonstre/"), float speed=200.0, int timer=0, int isArrive=0, int damageAttack=10, int portee=2, int damageExplosed=5, int rateRegeneration=10): RegenerationExplosedStrongMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack, portee, damageExplosed, rateRegeneration), m_moneyStolen(50) {}


    /******DESTRUCTEUR******/
    virtual ~ThiefRegenerationExplosedStrongMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class RegenerationExplosedStrongMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class RegenerationExplosedStrongMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "ThiefRegenerationExplosedStrongMonstre")

    virtual void draw(Joueur* player) const;

    virtual void walk(Joueur* player, std::string const& stringNameDirectory="Files_Levels/");

    void increaseMoneyStolen(int const& rateMoneyStolen=1);

    void increaseRateRegeneration(int const& rateRegenerationWin=1);

    virtual void increaseLevelMonstre(Joueur* player, std::string const& nameAttribut="random", int unsigned const& stepIncrease=1);

    void regeneration();


    /******PROTOTYPE OPERATEURS******/
    ThiefRegenerationExplosedStrongMonstre& operator=(ThiefRegenerationExplosedStrongMonstre const& monstreAcopier);

};
