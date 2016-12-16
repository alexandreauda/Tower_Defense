#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "StrongMonstre.h"
#include "ExplosedStrongMonstre.h"
#include "Joueur.h"

//La Class ThiefExplosedStrongMonstre herite de la Class ExplosedStrongMonstre
class ThiefExplosedStrongMonstre: public ExplosedStrongMonstre{

protected:

    /******ATTRIBUTS******/
    int m_moneyStolen;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    ThiefExplosedStrongMonstre(): ExplosedStrongMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefExplosedStrongMonstre","InitialLifeMonstre/"), 200.0, 0, 0, 5, 2, 5), m_moneyStolen(30){}

    /******CONSTRUCTEUR A PARAMETRES******/
	ThiefExplosedStrongMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefExplosedStrongMonstre","InitialLifeMonstre/"), float speed=200.0, int timer=0, int isArrive=0, int damageAttack=5, int portee=2, int damageExplosed=5): ExplosedStrongMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack, portee, damageExplosed), m_moneyStolen(30) {}


    /******DESTRUCTEUR******/
    virtual ~ThiefExplosedStrongMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class ExplosedStrongMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class ExplosedStrongMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "ThiefExplosedStrongMonstre")

    virtual void draw(Joueur* player) const;

    virtual void walk(Joueur* player, std::string const& stringNameDirectory="Files_Levels/");

    void increaseMoneyStolen(int const& rateMoneyStolen=1);

    virtual void increaseLevelMonstre(Joueur* player, std::string const& nameAttribut="random", int unsigned const& stepIncrease=1);


    /******PROTOTYPE OPERATEURS******/
    ThiefExplosedStrongMonstre& operator=(ThiefExplosedStrongMonstre const& monstreAcopier);

};
