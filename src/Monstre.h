#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"


class Monstre{

private:

    /******ATTRIBUT******/
	MonstreIA* m_monstreIA=NULL;//initialisation

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	Monstre(MonstreIA* monstreIA): m_monstreIA(monstreIA) {}


    /******PROTOTYPES DES METHODES******/

    void init(std::string nomIA="IAOnePath");

    BlockGrille searchInitPath();

    BlockGrille searchPath();

    void moveSmoothly();

    void walk();


};
