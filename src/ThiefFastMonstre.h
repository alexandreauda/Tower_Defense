#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "FastMonstre.h"
#include "Joueur.h"

//La Class ThiefFastMonstre herite de la Class FastMonstre
class ThiefFastMonstre: public FastMonstre{

protected:

    /******ATTRIBUTS******/
    int m_moneyStolen;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    ThiefFastMonstre(): FastMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefFastMonstre","InitialLifeMonstre/"), 100.0, 0, 0, 5), m_moneyStolen(20){}

    /******CONSTRUCTEUR A PARAMETRES******/
	ThiefFastMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefFastMonstre","InitialLifeMonstre/"), float speed=100.0, int timer=0, int isArrive=0, int damageAttack=5): FastMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack), m_moneyStolen(20) {}


    /******DESTRUCTEUR******/
    virtual ~ThiefFastMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class FastMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class FastMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "ThiefFastMonstre")

    virtual void draw(Joueur* player) const;

    virtual void walk(Joueur* player, std::string const& stringNameDirectory="Files_Levels/");

    void increaseMoneyStolen(int const& rateMoneyStolen=1);

    virtual void increaseLevelMonstre(Joueur* player, std::string const& nameAttribut="random", int unsigned const& stepIncrease=1);


    /******PROTOTYPE OPERATEURS******/
    ThiefFastMonstre& operator=(ThiefFastMonstre const& monstreAcopier);

};
