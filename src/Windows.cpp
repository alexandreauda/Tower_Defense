#include "Windows.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/
/*
@description:
La methode loadDimensionWindows permet d'initialiser deux parametres avec les valeurs presents dans un fichier specifie.
Les deux variables param2 et param3 passees en parametre sont modifiees par la methode car elles sont passees par reference.

@param: La methode loadDimensionWindows prend trois parametres obligatoires: un string, un int qui definira la largeur de la fenetre et un int qui definira la hauteur de la fenetre.
-param1: le string permet de specifier le chemin du fichier contenant les valeurs qui serviront a initialiser les deux autres parametres param2 et param3 qui seront utilises pour definir respectivement la largeur et la hauteur de la fenetre.
-param2: un int qui sera initialise avec une valeur lu dans le fichier specifie par le param1 et qui correspondra a la largeur de la fenetre.
-param3: un int qui sera initialise avec une valeur lu dans le fichier specifie par le param1 et qui correspondra a la hauteur de la fenetre.
*/
void Windows::loadDimensionWindows(string const& stringWindows, int &windowsWidth, int &windowsHeight) const{

    ifstream flux(stringWindows.c_str(),ios::app);//ouverture du flux de lecture
    int valueWindows;
    int i=0;

    if(flux)//si l'ouverture du fichier reussi
    {
        while(flux>>valueWindows){//on lit le fichier mot par mot jusqu'a la fin de celui-ci
                switch(i){
                    case 0://Si le mot rencontrer est le premier mot, alors on initialise windowsWidth avec ce premier mot
                        windowsWidth=valueWindows;//on initialise windowsWidth avec le premier mot du fichier
                        i++;
                        break;

                     case 1://Si le mot rencontrer est le deuxieme mot, alors on initialise windowsHeight avec ce deuxieme mot
                        windowsHeight=valueWindows;//on initialise windowsHeight avec le deuxieme mot du fichier
                        i++;
                        break;

                     default://Sinon, on affiche un message d'erreur
                        cout<<"ERROR in file: "<<stringWindows<<" -> Le fichier ne doit contenir que deux valeurs representant dans l'ordre, la largeur et la hauteur de la fenetre."<<endl;
                        break;
                }
        }

    }
    else// En cas de probleme lors de l'ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;// on affiche un message d'erreur
    }

}


