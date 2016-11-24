#include "Grille.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode loadGrille permet d'initialiser une matrice prise en parametre avec la matrice presente dans un fichier.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode loadGrille prend deux parametres obligatoires: un string, et une matrice statique de BlockGrille 12*12.
-param1: le string permet de specifier le chemin du fichier contenant la matrice qui sert a initialiser la matrice passee en second parametre
-param2: une matrice de BlockGrille 12*12 qui va etre modifiee pour etre initialisee avec les donnees lues dans le fichier.
*/
void Grille::loadGrille(string const& stringLevel, BlockGrille grilleBlock[12][12]) const{

    Level level;
    int matLevel[12][12]; //on definit une matrice vide 12*12 nommee matLevel
    level.loadLevel(stringLevel, matLevel); //on initialise la matrice precedente matLevel avec les donnes lues dans le fichier specifie

        //on parcourt la grille
		for(int y=0;y<12;y++){
			for(int x=0;x<12;x++){

				grilleBlock[11-y][11-x]= BlockGrille(-x*m_blockWidth-0.000*x+0.67, -y*m_blockHeight+0.26*y-0.638, m_blockWidth, m_blockHeight);//on initialise la matrice block[][] avec des blocs

                    (grilleBlock[11-y][11-x]).setm_posxID(11-x);//on set le m_posxID des blocs en fonction de leurs numeros en abscisse

                    (grilleBlock[11-y][11-x]).setm_posyID(11-y);//on set le m_posyID des blocs en fonction de leurs numeros en ordonne

                    (grilleBlock[11-y][11-x]).setm_colorBlockID(matLevel[11-y][11-x]);//on set le m_colorBlockID des blocs en fonction de la valeur de l'element correspondant dans matLevel
                                                                          //Ainsi, si le bloc est un morceau de chemin dans le fichier Files_Levels, son m_colorBlockID sera parametre
                                                                          //en consequence pour qu'il s'affiche in fine dans la bonne couleur. De meme, si le bloc en question est un
                                                                          //morceau d'herbe.

			}
		}

}


/*
@description:
La methode draw permet d'afficher la Grille de Jeu en fonction de la matrice presente dans un fichier.

@param: La methode draw prend un parametre obligatoire: un string.
-param1: le string permet de specifier le chemin du fichier contenant la matrice spécifiant le trace de la grille de Jeu.
*/
void Grille::draw(string const& stringLevel) const{

BlockGrille grilleBlock[12][12];
loadGrille(stringLevel, grilleBlock);//on initialise la matrice grilleBlock prise en parametre avec la matrice presente dans le fichier, specifie par le chemin stringLevel.

        //on parcourt la grille
		for(int y=0;y<12;y++){
			for(int x=0;x<12;x++){

                (grilleBlock[y][x]).draw();//on dessine le bloc correspondant (dependamment de son m_colorBlockID, il sera dessine dans une couleur specifique)

			}
		}
}


