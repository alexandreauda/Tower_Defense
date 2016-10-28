#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Windows{

private:

    /******ATTRIBUT******/
    int m_w1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	Windows():m_w1(0){}

    /******PROTOTYPES DES METHODES******/

    void loadDimensionWindows(string const& stringWindows, float &windowsWidth, float &windowsHeight) const;

};
