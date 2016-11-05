#pragma once
#include "Grille.h"
#include "MonstreIA.h"

//La Class IAOnePath herite de la Class MonstreIA
class IAOnePath: public MonstreIA{

private:

    /******ATTRIBUTS******/
	int m_iao1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	IAOnePath(): MonstreIA(), m_iao1(0){}


    /******PROTOTYPES DES METHODES******/

    virtual BlockGrille searchInitWay(BlockGrille grilleDeJeu[12][12]) const;//Renvoie le premier block du chemin de la grille en considerant que celle-ci ne comporte qu' un seul chemin

    virtual BlockGrille searchWay(BlockGrille grilleDeJeu[12][12]);//Renvoie le prochain block sur lequel un monstre devra se rendre sur une grille avec un seul chemin

    virtual std::string getClass() const;//Renvoie un string avec le nom de la classe actuelle (à savoir ici: "IAOnePath")
};
