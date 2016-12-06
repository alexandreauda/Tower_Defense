#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "FastMonstre.h"
#include "ExplosedFastMonstre.h"
#include "Joueur.h"

//La Class ThiefExplosedFastMonstre herite de la Class ExplosedFastMonstre
class ThiefExplosedFastMonstre: public ExplosedFastMonstre{

protected:

    /******ATTRIBUTS******/
    int m_moneyStolen;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    ThiefExplosedFastMonstre(): ExplosedFastMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefExplosedFastMonstre","InitialLifeMonstre/"), 100.0, 0, 0, 5, 2, 5), m_moneyStolen(30){}

    /******CONSTRUCTEUR A PARAMETRES******/
	ThiefExplosedFastMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefExplosedFastMonstre","InitialLifeMonstre/"), float speed=100.0, int timer=0, int isArrive=0, int damageAttack=5, int portee=2, int damageExplosed=5): ExplosedFastMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack, portee, damageExplosed), m_moneyStolen(30) {}


    /******DESTRUCTEUR******/
    virtual ~ThiefExplosedFastMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class ExplosedFastMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class ExplosedFastMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "ThiefExplosedFastMonstre")

    virtual void draw(Joueur* player) const;

    virtual void walk(Joueur* player);

    void increaseMoneyStolen(int const& rateMoneyStolen=1);

    virtual void increaseLevelMonstre(Joueur* player, std::string const& nameAttribut="random", int unsigned const& stepIncrease=1);


    /******PROTOTYPE OPERATEURS******/
    ThiefExplosedFastMonstre& operator=(ThiefExplosedFastMonstre const& monstreAcopier);

};
