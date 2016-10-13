#include "Level.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

void Level::loadLevel(string stringLevel,int matLevel[12][12]){

    string const nomFichier(stringLevel);
    ifstream flux(nomFichier.c_str(),ios::app);
    int valueMatrix;
    int i=0;
    vector <int> v;

    if(flux)
    {
        while(flux>>valueMatrix){
            v.push_back(valueMatrix);
        }

        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){

				matLevel[y][x]=v[i];
				i++;
            }
        }

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

}


