#ifndef LIBMATRIX_H_INCLUDED
#define LIBMATRIX_H_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <math.h>
#include "Level.h"
#include "BlockGrille.h"
#include "BlockStore.h"


class LibMatrix{

private:

    /******ATTRIBUT******/
    int m_lm1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	LibMatrix():m_lm1(0){}

    /******PROTOTYPES DES METHODES******/

    static void readMatrix(int matrix[12][12]);

    static void identity(int matrix[12][12]);

    static void axialSymmetryIdentity(int matrix[12][12]);

    static void transpose(int matrix[12][12]);

    static void matrixCopy(int matrix[12][12], int matrix1[12][12]);

    static void matrixProduct(int matrixproduct[12][12], int matrix1[12][12], int matrix2[12][12]);

    static void matrixRot90(int matrix[12][12]);

    static void matrixRot180(int matrix[12][12]);

    static int puissance(int const& x, int const& y);//Retourne x^y

    static int isContained(std::vector<float> const& vectorTest, float const& x);//Retourne 1 si x se trouve dans le vecteur et 0 sinon

    static void drawLargeText2D(char * str, float const& x, float const& y, int const& taille=1, float const& r=1.0, float const& g=1.0, float const& b=1.0, float const& alpha=1.0);

    static float distanceBetweenPoint(float const& pointx1, float const& pointy1, float const& pointx2, float const& pointy2);

    static void loadLevelByInt(int const& intLevel, int matLevel[12][12], std::string const& stringNameDirectory="Files_Levels/");

    static void loadLevel(std::string const& stringLevel, int matLevel[12][12]);

    static void loadGrille(std::string const& stringLevel, BlockGrille grilleBlock[12][12], float blockWidth, float blockHeight);

    static void loadStore(BlockStore stockStore[12], float shopCellWidth, float shopCellHeight);

    static int loadIntInFile(std::string const& stringLevel);

    static int varAleatoire(int const& nbMax);

    static int varAleatoireBetweenTwoNumbers(int const& nbMin, int const& nbMax);

};


#endif // LIBMATRIX_H_INCLUDED
