#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"


class Monstre{

private:

    /******ATTRIBUT******/
	MonstreIA* m_monstreIA=NULL;//initialisation (objet membre)
	int m_m1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    Monstre(): m_m1(0) {}

    /******CONSTRUCTEUR A PARAMETRES******/
	Monstre(MonstreIA* monstreIA, int m1=0): m_monstreIA(monstreIA), m_m1(m1) {}


    /******PROTOTYPES DES METHODES******/

    void init(std::string nomIA="IAOnePath");

    BlockGrille searchInitPath();

    BlockGrille searchPath(BlockGrille grilleDeJeu[12][12]) const;

    void moveSmoothly();

    void walk();


};
