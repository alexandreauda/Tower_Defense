#include "MyGraphicEngine.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode Draw de la classe MyGraphicEngine permet de dessiner le damier graphique avec le(s) chemins accesibles ou va se derouler le jeu.

@param: null.
*/
void MyGraphicEngine::Draw(){

    Block block[12][12];//on definit une matrice vide 12*12 de type Block
    float const r=0.0;
    float const g=1.0;
    float const b=0.0;
    float const alpha=1.0;

    Level level;
    int matLevel[12][12]; //on definit une matrice vide 12*12 nommee matLevel
    level.loadLevel("Files_Levels/Level_1.txt",matLevel);// on initialise la matrice precedente matLevel avec les donnes lues dans le fichier specifie

        //on parcourt la grille
		for(int y=0;y<12;y++){
			for(int x=0;x<12;x++){
            Value v;

				block[y][x]= Block(-x*m_blockSize-0.1*x+0.8,-y*m_blockSize+0.2*y-0.8,m_blockSize,m_blockSize,r,g,b,alpha, v.getm_groundGrass());//on initialise la matrice block[][] avec des blocs

                    (block[y][x]).setm_grassID(matLevel[y][x]);//on set le m_grassID des blocs en fonction de la valeur de l'element correspondant dans matLevel
                                                               //Ainsi, si le bloc est un morceau de chemin dans le fichier Files_Levels, son m_grassID sera parametre
                                                               //en consequence pour qu'il s'affiche in fine dans la bonne couleur. De meme, si le bloc en question est un
                                                               //morceau d'herbe.

                   (block[y][x]).draw();//on dessine le bloc correspondant (dependamment de son m_grassID, il sera dessine dans une couleur specifique)


			}
		}

}

