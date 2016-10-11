#pragma once

class Value{

private:

    /******ATTRIBUT******/
	 int m_groundGrass;

public:

    /******CONSTRUCTEUR******/
	Value(int groundGrass=0):m_groundGrass(groundGrass){}

    /******PROTOTYPES DES METHODES******/
	int getm_groundGrass ()const;//Getteur de l'attribut m_groundGrass


};
