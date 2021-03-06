#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"
#include "Monstre.h"
#include "Joueur.h"

//La Class FastMonstre herite de la Class Monstre
class FastMonstre: public Monstre{

protected:

    /******ATTRIBUTS******/


public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    FastMonstre(): Monstre(new IASeveralPaths(), 0, 0, 0, 0, 0, 0, LibMatrix::loadIntInFileWithDirectory("InitialLifeFastMonstre","InitialLifeMonstre/"), 100.0, 0, 0, 10){}

    /******CONSTRUCTEUR A PARAMETRES******/
	FastMonstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, int vie=LibMatrix::loadIntInFileWithDirectory("InitialLifeFastMonstre","InitialLifeMonstre/"), float speed=100.0, int timer=0, int isArrive=0, int damageAttack=10): Monstre(monstreIA, posx1, posy1, posx2, posy2, posx3, posy3, vie, speed, timer, isArrive, damageAttack) {}


    /******DESTRUCTEUR******/
    virtual ~FastMonstre() {
        delete m_monstreIA;
    }

    /******ACCESSEURS******/
    //Les accesseurs de la Class Monstre


    /******MUTATEURS******/
    //Les mutateurs de la Class Monstre


    /******PROTOTYPES DES METHODES******/
    virtual std::string getClass() const;//Renvoie le nom de la Class (ici, le string "FastMonstre")

    virtual void draw(Joueur* player) const;

    virtual void walk(Joueur* player, std::string const& stringNameDirectory="Files_Levels/");


    /******PROTOTYPE OPERATEURS******/
    FastMonstre& operator=(FastMonstre const& monstreAcopier);

};
