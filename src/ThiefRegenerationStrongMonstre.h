#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "StrongMonstre.h"
#include "RegenerationStrongMonstre.h"
#include "Joueur.h"

//La Class ThiefRegenerationStrongMonstre herite de la Class RegenerationStrongMonstre
class ThiefRegenerationStrongMonstre: public RegenerationStrongMonstre{

protected:

    /******ATTRIBUTS******/
    int m_moneyStolen;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    ThiefRegenerationStrongMonstre(): RegenerationStrongMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefRegenerationStrongMonstre","InitialLifeMonstre/"), 200.0, 0, 0, 5, 10), m_moneyStolen(20){}

    /******CONSTRUCTEUR A PARAMETRES******/
	ThiefRegenerationStrongMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefRegenerationStrongMonstre","InitialLifeMonstre/"), float speed=200.0, int timer=0, int isArrive=0, int damageAttack=5, int rateRegeneration=10): RegenerationStrongMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack, rateRegeneration), m_moneyStolen(20) {}


    /******DESTRUCTEUR******/
    virtual ~ThiefRegenerationStrongMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class RegenerationStrongMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class RegenerationStrongMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "ThiefRegenerationStrongMonstre")

    virtual void draw(Joueur* player) const;

    virtual void walk(Joueur* player, std::string const& stringNameDirectory="Files_Levels/");

    void increaseMoneyStolen(int const& rateMoneyStolen=1);

    void increaseRateRegeneration(int const& rateRegenerationWin=1);

    virtual void increaseLevelMonstre(Joueur* player, std::string const& nameAttribut="random", int unsigned const& stepIncrease=1);

    void regeneration();


    /******PROTOTYPE OPERATEURS******/
    ThiefRegenerationStrongMonstre& operator=(ThiefRegenerationStrongMonstre const& monstreAcopier);

};
