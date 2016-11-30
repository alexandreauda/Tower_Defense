#pragma once
#include <cstdio>
#include <cstdlib>
#include "LibMatrix.h"
#include "Grille.h"
#include "MonstreIA.h"


//La Class IASeveralPaths herite de la Class MonstreIA
class IASeveralPaths: public MonstreIA{

private:

    /******ATTRIBUT******/
	int m_ias1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	IASeveralPaths(): MonstreIA(), m_ias1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual BlockGrille searchInitWay(BlockGrille grilleDeJeu[12][12]) const;

    virtual BlockGrille searchWay(BlockGrille grilleDeJeu[12][12]);

    virtual int searchIfWay(BlockGrille grilleDeJeu[12][12]) const;//La methode searchIfWay de la classe IAOnePath renvoie 1 s'il existe un block sur lequel un monstre peut se rendre sur la grille pour continuer a avancer et 0 si le Monstre ne trouve aucun block sur lequel il peut avancer.

    virtual std::string getClass() const;//Renvoie un string avec le nom de la classe actuelle (à savoir ici: "IASeveralPaths")

};
