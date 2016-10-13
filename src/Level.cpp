#include "Level.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/
/*
@description:
La methode loadLevel permet d'initialiser une matrice prise en parametre avec la matrice presente dans un fichier.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode loadLevel prend deux parametres obligatoires: un string, et une matrice statique de int 12*12.
-param1: le string permet de specifier le chemin du fichier contenant la matrice qui sert a initialiser la matrice passee en second parametre
-param2: une matrice  de int 12*12 qui va etre modifiee pour etre initialisee avec les donnees lues dans le fichier.
*/
void Level::loadLevel(string const& stringLevel,int matLevel[12][12]) const{

    ifstream flux(stringLevel.c_str(),ios::app);//ouverture du flux de lecture
    int valueMatrix;
    int i=0;
    vector <int> v;

    if(flux)//si l'ouverture du fichier reussi
    {
        while(flux>>valueMatrix){//on lit le fichier mot par mot jusqu'a la fin de celui-ci
            v.push_back(valueMatrix);//on met les nombres lus dans un vecteur
        }

        //on parcourt la matrice passee en parametre et on initialise chaque element
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){

				matLevel[y][x]=v[i];//on initialise la matrice passee en parametre avec les donnees du fichier que l'on a stocke dans un vecteur.
				i++;
            }
        }

    }
    else// En cas de probleme lors de l'ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;// on affiche un message d'erreur
    }

}


