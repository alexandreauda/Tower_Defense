#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"

//La Class StrongMonstre herite de la Class Monstre
class StrongMonstre: public Monstre{

protected:

    /******ATTRIBUTS******/


public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    StrongMonstre(): Monstre(new IAOnePath(), 0, 0, 0, 0, 0, 0, 200, 200.0, 0, 0, 10){}

    /******CONSTRUCTEUR A PARAMETRES******/
	StrongMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=200, float speed=200.0, int timer=0, int isArrive=0, int damageAttack=10): Monstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack) {}


    /******DESTRUCTEUR******/
    virtual ~StrongMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class Monstre


    /******MUTATEURS******/
    //Les mutateurs de la Class Monstre


    /******PROTOTYPES DES METHODES******/
    virtual void draw() const;


    /******PROTOTYPE OPERATEURS******/
    StrongMonstre& operator=(StrongMonstre const& monstreAcopier);

};
