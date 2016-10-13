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

    /******CONSTRUCTEUR******/
	Level():m_l1(0){}

    /******PROTOTYPES DES METHODES******/

    void loadLevel(std::string stringLevel,int matLevel[12][12]);

};
