#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "StrongMonstre.h"
#include "Joueur.h"

//La Class RegenerationStrongMonstre herite de la Class StrongMonstre
class RegenerationStrongMonstre: public StrongMonstre{

protected:

    /******ATTRIBUTS******/
    int m_rateRegeneration;


public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    RegenerationStrongMonstre(): StrongMonstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeRegenerationStrongMonstre","InitialLifeMonstre/"), 200.0, 0, 0, 10), m_rateRegeneration(10){}

    /******CONSTRUCTEUR A PARAMETRES******/
	RegenerationStrongMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeRegenerationStrongMonstre","InitialLifeMonstre/"), float speed=200.0, int timer=0, int isArrive=0, int damageAttack=10, int rateRegeneration=10): StrongMonstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack), m_rateRegeneration(rateRegeneration) {}


    /******DESTRUCTEUR******/
    virtual ~RegenerationStrongMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class StrongMonstre


    /******MUTATEURS******/
    //Les mutateurs de la Class StrongMonstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "RegenerationStrongMonstre")

    virtual void draw(Joueur* player) const; //Dessine le monstre

    void regeneration();

    /******PROTOTYPE OPERATEURS******/
    RegenerationStrongMonstre& operator=(RegenerationStrongMonstre const& monstreAcopier);

};
