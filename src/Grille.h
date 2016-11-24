#pragma once
#include <string>
#include <sstream>
#include "Level.h"
#include "BlockGrille.h"


class Grille{

private:

    /******ATTRIBUTS******/
    float m_worldWidth;
	float m_worldHeight;
	float m_blockWidth;
	float m_blockHeight;

public:

    /******CONSTRUCTEUR A PARAMETRES******/
	Grille(float worldWidth=12.0, float worldHeight=12.0, float blockWidth=0.13, float blockHeight=0.13):m_worldWidth(worldWidth), m_worldHeight(worldHeight), m_blockWidth(blockWidth), m_blockHeight(blockHeight){}


    /******PROTOTYPES DES METHODES******/

    void loadGrille(int const& intLevel, BlockGrille grilleBlock[12][12], std::string const& stringNameDirectory="Files_Levels/") const;

    void draw(int const& intLevel, std::string const& stringNameDirectory="Files_Levels/") const;

};
