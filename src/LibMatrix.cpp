#include "LibMatrix.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode readMatrix prend une matrice 12*12 en parametre qui va etre lue et affichee sur la console.
La matrice en parametre est modifiee par la methode car elle est passee par reference.
Note: Cete methode est particulierement utile pour le debogage.

@param: La methode readMatrix prend 1 parametre obligatoire: une matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre lue et affichee sur la console.
*/
void LibMatrix::readMatrix(int matrix[12][12]) {
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
void LibMatrix::identity(int matrix[12][12]) {
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
void LibMatrix::axialSymmetryIdentity(int matrix[12][12]) {
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
void LibMatrix::transpose(int matrix[12][12]) {
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
void LibMatrix::matrixCopy(int matrix[12][12], int matrix1[12][12]) {
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
void LibMatrix::matrixProduct(int matrixproduct[12][12], int matrix1[12][12], int matrix2[12][12]) {
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
void LibMatrix::matrixRot90(int matrix[12][12]) {
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
void LibMatrix::matrixRot180(int matrix[12][12]) {
matrixRot90(matrix);//On effectue une rotation de la matrice de 90° dans le sens horaire.
matrixRot90(matrix);//On effectue une nouvelle fois une rotation de la matrice de 90° dans le sens horaire. On obtient donc une matrice transforme en sa rotation de 180° dans le sens horaire.
}

/*
@description:
La methode puissance prend deux int x et y en parametre et retourne x^y.

@param: La methode puissance prend 2 parametres obligatoires: un int et un int.
-param1: Le int que l'on veut mettre a la puissanse.
-param2: Le int specifiant la puissance a laquelle est mise le param1.
*/
int LibMatrix::puissance(int const& x, int const& y){
    int curentPuissance=1;
    for(int i;i<y;i++){
        curentPuissance*=x;
    }
    return curentPuissance;//Retourne x^y
}

/*
@description:
La methode drawLargeText2D ecrit du texte de differente facon en fonction des parametres.

@param: La methode drawLargeText2D prend 8 parametres obligatoires: 1 pointeur de char, float, float, int, float, float, float, float.
-param1: un pointeur de char parmettant de specifier le texte que l'on veut afficher.
-param2: un float parmettant de specifier l'abscisse l'on veut afficher le texte.
-param3: un float parmettant de specifier l'ordonne l'on veut afficher le texte.
-param4: un int valant 0 ou 1 parmettant de specifier la police et donc la taille du texte que l'on veut afficher. Si ce parametre prend une autre valeur que 0 ou 1 alors cela revient a avoir ecrit 1.
-param5: un float parmettant de specifier la couleur rouge des couleurs RGB.
-param6: un float parmettant de specifier la couleur verte des couleurs RGB.
-param7: un float parmettant de specifier la couleur bleu des couleurs RGB.
-param8: un float parmettant de specifier l'apha qui correspond a la transparence.
*/
void LibMatrix::drawLargeText2D(char * str, float const& x, float const& y, int const& taille, float const& r, float const& g, float const& b, float const& alpha){
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    //on doit definir la couleur avant la fonction RasterPos sinon elle ne sera pas prise en compte ...
    glColor4f(r,g,b,alpha);
    glRasterPos2f(x,y) ;
    // Draw your text
    for (unsigned int i=0;i<strlen(str);i++){
            switch(taille){

                case 0: glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*(str+i));
                        break;

                case 1: glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*(str+i));
                        break;

                default: glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*(str+i));
                         break;
                    }
    }
    glPopAttrib(); // This sets the colour back to its original value
    glPopMatrix();
}

/*
@description:
La methode distanceBetweenPoint prend les coordonnes de deux points en parametre et renvoie la distance qui separe ces deux points sur le plan cartesien.

@param: La methode distanceBetweenPoint prend 4 parametres obligatoires: un float, un float, un float, un float.
-param1: un float qui correspond a l'abscisse du premier point
-param2: un float qui correspond a l'ordonne du premier point
-param3: un float qui correspond a l'abscisse du deuxieme point
-param4: un float qui correspond a l'ordonne du deuxieme point
*/
float LibMatrix::distanceBetweenPoint(float const& pointx1, float const& pointy1, float const& pointx2, float const& pointy2){
float distance;
distance = sqrt((pointx2-pointx1)*(pointx2-pointx1) + (pointy2-pointy1)*(pointy2-pointy1));
return distance;
}


/*
@description:
La methode loadLevelByInt permet d'initialiser une matrice prise en parametre avec la matrice presente dans un fichier.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode loadLevelByInt prend deux parametres obligatoires: un int, et une matrice statique de int 12*12.
-param1: le int permet de specifier le niveau de la grille et donc le chemin du fichier contenant la matrice qui sert a initialiser la matrice passee en second parametre
-param2: une matrice  de int 12*12 qui va etre modifiee pour etre initialisee avec les donnees lues dans le fichier.
*/
void LibMatrix::loadLevelByInt(int const& intLevel,int matLevel[12][12], string const& stringNameDirectory) {

    //On construit petit a petit l'arborescence du chemin pour trouver les fichiers
    string stringLevel=stringNameDirectory;
    stringLevel+="Level_";

    string numberLevel;
    stringstream convertToString;
    convertToString << intLevel;
    numberLevel=convertToString.str();
    stringLevel+=numberLevel;

    stringLevel+=".txt";

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


/*
@description:
La methode loadLevel permet d'initialiser une matrice prise en parametre avec la matrice presente dans un fichier.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode loadLevel prend deux parametres obligatoires: un string, et une matrice statique de int 12*12.
-param1: le string permet de specifier le chemin du fichier contenant la matrice qui sert a initialiser la matrice passee en second parametre
-param2: une matrice  de int 12*12 qui va etre modifiee pour etre initialisee avec les donnees lues dans le fichier.
*/
void LibMatrix::loadLevel(string const& stringLevel,int matLevel[12][12]) {

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


/*
@description:
La methode loadGrille permet d'initialiser une matrice prise en parametre avec la matrice presente dans un fichier.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode loadGrille prend quatre parametres obligatoires: un string, une matrice statique de BlockGrille 12*12, un float, un float.
-param1: le string permet de specifier le chemin du fichier contenant la matrice qui sert a initialiser la matrice passee en second parametre
-param2: une matrice de BlockGrille 12*12 qui va etre modifiee pour etre initialisee avec les donnees lues dans le fichier
-param3: le float blockWidth permet de definir la largeur des blocks de la grille
-param4: le float blockHeight permet de definir la hauteur des blocks de la grille.
*/
void LibMatrix::loadGrille(string const& stringLevel, BlockGrille grilleBlock[12][12], float blockWidth, float blockHeight) {

    int matLevel[12][12]; //on definit une matrice vide 12*12 nommee matLevel
    loadLevel(stringLevel, matLevel); //on initialise la matrice precedente matLevel avec les donnes lues dans le fichier specifie

        //on parcourt la grille
		for(int y=0;y<12;y++){
			for(int x=0;x<12;x++){

				grilleBlock[11-y][11-x]= BlockGrille(-x*blockWidth-0.000*x+0.67, -y*blockHeight+0.26*y-0.638, blockWidth, blockHeight);//on initialise la matrice block[][] avec des blocs

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
La methode loadStore permet d'initialiser un vecteur statique pris en parametre avec des blocks de carasteristiques differentes.
Le vecteur statique en parametre est modifiee par la methode car il est passe par reference.

@param: La methode loadStore prend trois parametres obligatoires: un vecteur statique de type BlockStore et de dimension 12, un float, un float.
-param1: un vecteur statique de type BlockStore et de dimension 12 qui va etre modifie pour etre initialise avec des blocks de carasteristiques differentes
-param2: le float shopCellWidth permet de definir la largeur des blocks du Store
-param3: le float shopCellHeight permet de definir la hauteur des blocks du Store
*/
void LibMatrix::loadStore(BlockStore stockStore[12], float shopCellWidth, float shopCellHeight) {

for(int i=0;i<12;i++){

				stockStore[i]= BlockStore(-i*shopCellWidth-0.004*i+0.67, -0.85, shopCellWidth, shopCellHeight);//on initialise le tableau stockStore[] avec des blocs

                (stockStore[i]).setm_posID(11-i);//on numerote les blocks au fur et a mesure

                (stockStore[i]).setm_colorBlockID(2);//on set l'ID

			}
}

/*
@description:
La methode loadIntInFile permet de retourner un int lu dans dans un fichier.

@param: La methode loadIntInFile prend un parametre obligatoire: un string.
-param1: le string permet de specifier le chemin du fichier contenant le int que l'on veut lire et retourner.
*/
int LibMatrix::loadIntInFile(string const& stringLevel) {

    ifstream flux(stringLevel.c_str(),ios::app);//ouverture du flux de lecture
    int valueInt;

    if(flux)//si l'ouverture du fichier reussi
    {
        while(flux>>valueInt){//on lit le fichier mot par mot jusqu'a la fin de celui-ci
            return valueInt;
        }

    }
    else// En cas de probleme lors de l'ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;// on affiche un message d'erreur
    }
}

