#pragma once
#include <string>
#include "Level.h"
#include "BlockGrille.h"
#include "LibMatrix.h"


class Grille{

private:

    /******ATTRIBUT******/
    float m_worldWidth;
	float m_worldHeight;
	float m_blockWidth;
	float m_blockHeight;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	Grille(float worldWidth=12.0, float worldHeight=12.0, float blockWidth=0.13, float blockHeight=0.13):m_worldWidth(worldWidth), m_worldHeight(worldHeight), m_blockWidth(blockWidth), m_blockHeight(blockHeight){}


    /******PROTOTYPES DES METHODES******/

    void loadGrille(std::string const& stringLevel, BlockGrille grilleBlock[12][12]) const;

    void draw(std::string const& stringLevel) const;

};
