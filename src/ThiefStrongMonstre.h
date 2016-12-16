#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "StrongMonstre.h"
#include "Joueur.h"

//La Class ThiefFastMonstre herite de la Class StrongMonstre
class ThiefStrongMonstre: public StrongMonstre{

protected:

    /******ATTRIBUTS******/
    int m_moneyStolen;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    ThiefStrongMonstre(): StrongMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefStrongMonstre","InitialLifeMonstre/"), 200.0, 0, 0, 5), m_moneyStolen(20){}

    /******CONSTRUCTEUR A PARAMETRES******/
	ThiefStrongMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefStrongMonstre","InitialLifeMonstre/"), float speed=200.0, int timer=0, int isArrive=0, int damageAttack=5): StrongMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack), m_moneyStolen(20) {}


    /******DESTRUCTEUR******/
    virtual ~ThiefStrongMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class StrongMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class StrongMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "ThiefStrongMonstre")

    virtual void draw(Joueur* player) const;

    virtual void walk(Joueur* player, std::string const& stringNameDirectory="Files_Levels/");

    void increaseMoneyStolen(int const& rateMoneyStolen=1);

    virtual void increaseLevelMonstre(Joueur* player, std::string const& nameAttribut="random", int unsigned const& stepIncrease=1);


    /******PROTOTYPE OPERATEURS******/
    ThiefStrongMonstre& operator=(ThiefStrongMonstre const& monstreAcopier);

};
