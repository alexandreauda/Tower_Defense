#pragma once
#include "Grille.h"
#include "MonstreIA.h"


//La Class IAOnePath herite de la Class MonstreIA
class IAOnePath: public MonstreIA{

private:

    /******ATTRIBUT******/
	int m_iao1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	IAOnePath(): MonstreIA(), m_iao1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual BlockGrille searchInitWay(BlockGrille grilleDeJeu[12][12]) const;//Renvoie le block sur lequel un monstre devra entrer sur une grille avec un seul chemin

    virtual BlockGrille searchWay(BlockGrille grilleDeJeu[12][12]) const;//Renvoie le prochain block sur lequel un monstre devra se rendre sur une grille avec un seul chemin

};
