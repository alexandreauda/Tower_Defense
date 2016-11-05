#pragma once
#include <iostream>
#include <fstream>
#include <string>


class Windows{

private:

    /******ATTRIBUT******/
    int m_w1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	Windows():m_w1(0){}


    /******ACCESSEURS******/
    //null

    /******MUTATEURS******/
    //null

    /******PROTOTYPES DES METHODES******/
    void loadDimensionWindows(std::string const& stringWindows, float &windowsWidth, float &windowsHeight) const;

};
