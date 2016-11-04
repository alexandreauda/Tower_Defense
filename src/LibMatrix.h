#ifndef LIBMATRIX_H_INCLUDED
#define LIBMATRIX_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

    static void loadLevel(std::string const& stringLevel, int matLevel[12][12]);

    static void loadGrille(std::string const& stringLevel, BlockGrille grilleBlock[12][12], float blockWidth, float blockHeight);

    static void loadStore(BlockStore stockStore[12], float shopCellWidth, float shopCellHeight);

};


#endif // LIBMATRIX_H_INCLUDED
