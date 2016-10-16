#include "LibMatrix.h"

using namespace std;

/*
@description:
La methode readMatrix prend une matrice 12*12 en parametre qui va etre lue et affichee sur la console.
La matrice en parametre est modifiee par la methode car elle est passee par reference.
Note: Cete methode est particulierement utile pour le debogage.

@param: La methode readMatrix prend 1 parametre obligatoire: une matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre lue et affichee sur la console.
*/
void LibMatrix::readMatrix(int matrix[12][12]) const{
    vector <int> v;
    //on parcourt la matrice passee en parametre
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){
				v.push_back(matrix[y][x]);//on met les nombres lus dans un vecteur
            }
        }
    for(unsigned k=0;k<v.size();k++){
                if(k%12==0 && k!=0){
                    cout<<endl<<v[k];
                }
                else{
                    cout<<v[k];
                }
            }
}


/*
@description:
La methode identity prend une matrice 12*12 prise en parametre et modifie ses coefficients pour la transformer en matrice identite de meme dimension.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode identity prend 1 parametre obligatoire: une matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre modifiee pour donner la matrice identite de meme dimension.
*/
void LibMatrix::identity(int matrix[12][12]) const{
   //on parcourt la matrice passee en parametre
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){
                if(y==x){   //Sur la diagonnal, on initialise les coefficients a 1
				matrix[y][x]=1;
                }
                else{   //Pour tout les autres coefficients, on initialise ces derniers a 0
                matrix[y][x]=0;
                }
            }
        }
}

/*
@description:
La methode axialSymmetryIdentity prend une matrice 12*12 prise en parametre et modifie ses coefficients pour la transformer en le symetrique de la matrice identite par rapport a l'axe vertical.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode axialSymmetryIdentity prend 1 parametre obligatoire: une matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre modifiee pour donner le symetrique de la matrice identite par rapport a l'axe vertical.
*/
void LibMatrix::axialSymmetryIdentity(int matrix[12][12]) const{
//on parcourt la matrice passee en parametre
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){
                    if(y==11-x){
                        matrix[y][x]=1;
                    }
                    else{
                        matrix[y][x]=0;
                    }
            }
        }
}


/*
@description:
La methode transpose permet de transpose une matrice prise en parametre.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode transpose prend 1 parametre obligatoire: une matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre modifiee pour donner la transpose de cette matrice.
*/
void LibMatrix::transpose(int matrix[12][12]) const{
int stockMatrix[12][12];
//on parcourt la matrice passee en parametre
    for(int y=0;y<12;y++){
        for(int x=0;x<12;x++){

				stockMatrix[y][x]=matrix[x][y];//on transpose la matrice
        }
    }

//on parcourt la matrice passee en parametre
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){

				matrix[x][y]=stockMatrix[x][y];//on transpose la matrice
            }
        }
}


/*
@description:
La methode matrixCopy prend deux matrices 12*12 en parametre et initialise la premiere matrice avec les coefficients de la deuxieme matrice.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode matrixCopy prend 2 parametres obligatoires: 1 matrice statique de int 12*12, 1 matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre initialise avec les coefficients de la matrice param2.
-param2: une matrice de int 12*12 qui va etre lue pour initialise la matrice param1 avec les coefficients de param2.
*/
void LibMatrix::matrixCopy(int matrix[12][12], int matrix1[12][12]) const{
//on parcourt la matrice passee en parametre
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){

				matrix[x][y]=matrix1[x][y];//on transpose la matrice
            }
        }
}



/*
@description:
La methode matrixProduct prend trois matrices 12*12 en parametre, effectue le produit matriciel entre les deux matrices et initialise la troisieme matrice avec les coefficients de la matrice produit.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode matrixProduct prend 3 parametres obligatoires: 1 matrice statique de int 12*12, 1 matrice statique de int 12*12, 1 matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre initialise avec les coefficients de la matrice produit param2*param3.
-param2: une matrice de int 12*12 qui va etre servir a faire le produit param2*param3.
-param3: une matrice de int 12*12 qui va etre servir a faire le produit param2*param3.
*/
void LibMatrix::matrixProduct(int matrixproduct[12][12], int matrix1[12][12], int matrix2[12][12]) const{
//on parcourt la matrice passee en parametre
    int c=0;
    for(int x=0;x<12;x++){
        for(int y=0;y<12;y++){

                  for(int k=0;k<12;k++){
                      c+=matrix1[x][k]*matrix2[k][y];
                  }

                matrixproduct[x][y]=c;
                c=0;
            }
        }
}

/*
@description:
La methode matrixRot90 prend une matrices 12*12 en parametre et effectue une rotation de la matrice de 90° dans le sens horaire.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode matrixRot90 prend 1 parametre obligatoire: 1 matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre transforme en sa rotation de 90° dans le sens horaire.
*/
void LibMatrix::matrixRot90(int matrix[12][12]) const{
int transposeMatrix[12][12];
matrixCopy(transposeMatrix,matrix);
transpose(transposeMatrix);//transposeMatrix est maintenant la transpose de la matrice matrix. On a donc transposeMatrix=(T)matrix

int identityRot[12][12];
axialSymmetryIdentity(identityRot);//Cree une matrice identityRot qui est le symetrique de la matrice identite par rapport a l'axe vertical.

matrixProduct(matrix,transposeMatrix,identityRot);//matrix=(T)matrix*identityRot
}

/*
@description:
La methode matrixRot180 prend une matrices 12*12 en parametre et effectue une rotation de la matrice de 180° dans le sens horaire.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode matrixRot180 prend 1 parametre obligatoire: 1 matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre transforme en sa rotation de 180° dans le sens horaire.
*/
void LibMatrix::matrixRot180(int matrix[12][12]) const{
matrixRot90(matrix);//On effectue une rotation de la matrice de 90° dans le sens horaire.
matrixRot90(matrix);//On effectue une nouvelle fois une rotation de la matrice de 90° dans le sens horaire. On obtient donc une matrice transforme en sa rotation de 180° dans le sens horaire.
}
