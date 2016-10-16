#ifndef LIBMATRIX_H_INCLUDED
#define LIBMATRIX_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>


class LibMatrix{

private:

    /******ATTRIBUT******/
    int m_lm1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	LibMatrix():m_lm1(0){}

    /******PROTOTYPES DES METHODES******/

    void readMatrix(int matrix[12][12]) const;

    void identity(int matrix[12][12]) const;

    void axialSymmetryIdentity(int matrix[12][12]) const;

    void transpose(int matrix[12][12]) const;

    void matrixCopy(int matrix[12][12], int matrix1[12][12]) const;

    void matrixProduct(int matrixproduct[12][12], int matrix1[12][12], int matrix2[12][12]) const;

    void matrixRot90(int matrix[12][12]) const;

    void matrixRot180(int matrix[12][12]) const;

};


#endif // LIBMATRIX_H_INCLUDED
