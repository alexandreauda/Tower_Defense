#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Level{

private:

    /******ATTRIBUT******/
    int m_l1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	Level():m_l1(0){}


    /******ACCESSEURS******/
    //null

    /******MUTATEURS******/
    //null

    /******PROTOTYPES DES METHODES******/
    void loadLevel(std::string const& stringLevel, int matLevel[12][12]) const;

};
