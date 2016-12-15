#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "FastMonstre.h"
#include "RegenerationFastMonstre.h"
#include "Joueur.h"

//La Class ThiefRegenerationFastMonstre herite de la Class RegenerationFastMonstre
class ThiefRegenerationFastMonstre: public RegenerationFastMonstre{

protected:

    /******ATTRIBUTS******/
    int m_moneyStolen;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    ThiefRegenerationFastMonstre(): RegenerationFastMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefRegenerationFastMonstre","InitialLifeMonstre/"), 100.0, 0, 0, 5, 10), m_moneyStolen(20){}

    /******CONSTRUCTEUR A PARAMETRES******/
	ThiefRegenerationFastMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefRegenerationFastMonstre","InitialLifeMonstre/"), float speed=100.0, int timer=0, int isArrive=0, int damageAttack=5, int rateRegeneration=10): RegenerationFastMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack, rateRegeneration), m_moneyStolen(20) {}


    /******DESTRUCTEUR******/
    virtual ~ThiefRegenerationFastMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class RegenerationFastMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class RegenerationFastMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "ThiefRegenerationFastMonstre")

    virtual void draw(Joueur* player) const;

    virtual void walk(Joueur* player);

    void increaseMoneyStolen(int const& rateMoneyStolen=1);

    void increaseRateRegeneration(int const& rateRegenerationWin=1);

    virtual void increaseLevelMonstre(Joueur* player, std::string const& nameAttribut="random", int unsigned const& stepIncrease=1);

    void regeneration();


    /******PROTOTYPE OPERATEURS******/
    ThiefRegenerationFastMonstre& operator=(ThiefRegenerationFastMonstre const& monstreAcopier);

};
