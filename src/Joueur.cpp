#include "Joueur.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/

/*
@description:
Accesseur de l'attribut m_vie.

@param: null
*/
int Joueur::getm_vie() const{
    return m_vie;
}

/*
@description:
Accesseur de l'attribut m_argent.

@param: null
*/
int Joueur::getm_argent() const{
    return m_argent;
}

/*
@description:
Accesseur de l'attribut m_level.

@param: null
*/
int Joueur::getm_level() const{
    return m_level;
}

/*
@description:
Accesseur de l'attribut m_score.

@param: null
*/
int Joueur::getm_score() const{
    return m_score;
}

/*
@description:
Accesseur de l'attribut m_isAttack.

@param: null
*/
int Joueur::getm_isAttack() const{
    return m_isAttack;
}

/*
@description:
Accesseur de l'attribut m_isInGame.

@param: null
*/
bool Joueur::getm_isInGame() const{
    return m_isInGame;
}


/******IMPLEMENTATION DES MUTATEURS******/

/*
@description:
Mutateur de l'attribut m_vie.

@param: La methode setm_vie prend un parametre obligatoire: un int
-param1: le nouveau int pour m_vie
*/
void Joueur::setm_vie(int const& vie){
 m_vie=vie;
}

/*
@description:
Mutateur de l'attribut m_argent.

@param: La methode setm_argent prend un parametre obligatoire: un int
-param1: le nouveau int pour m_argent
*/
void Joueur::setm_argent(int const& argent){
 m_argent=argent;
}

/*
@description:
Mutateur de l'attribut m_level.

@param: La methode setm_level prend un parametre obligatoire: un int
-param1: le nouveau int pour m_level
*/
void Joueur::setm_level(int const& level){
 m_level=level;
}

/*
@description:
Mutateur de l'attribut m_score.

@param: La methode setm_score prend un parametre obligatoire: un int
-param1: le nouveau int pour m_score
*/
void Joueur::setm_score(int const& score){
 m_score=score;
}

/*
@description:
Mutateur de l'attribut m_isAttack.

@param: La methode setm_isAttack prend un parametre obligatoire: un bool
-param1: le nouveau bool pour m_isAttack
*/
void Joueur::setm_isAttack(bool const& attack){
 if(attack){
    m_isAttack=1;
 }
 else{
    m_isAttack=0;
 }
}

/*
@description:
Mutateur de l'attribut m_isInGame.

@param: La methode setm_isInGame prend un parametre obligatoire: un bool
-param1: le nouveau bool pour m_isInGame
*/
void Joueur::setm_isInGame(bool const& newBool){
 m_isInGame=newBool;
}


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode drawAttribut de la classe Joueur permet d'afficher les attributs du Joueur de maniere graphique.

@param: null
*/
void Joueur::drawAttribut() const{

    //Met les valeurs RGB dans la couleur blanche
    float const r=1.0;
    float const g=1.0;
    float const b=1.0;
    float const alpha = 1.0;


    //Affichage des informations concernant l'attribut m_vie
    char * textVie=new char[20]{'V','i','e',':',' ','\0'};//Contient le texte immuable concernant l'attribut m_vie
    char valueVie[10];//Contiendra la valeur de la vie du Joueur
    sprintf(valueVie, "%d", m_vie);//Stock la valeur de l'attribut m_vie dans un tableau de char
    strcat(textVie,valueVie);//Concatene les deux chaines de caracteres
    char * textFinDeTextVie=new char[1]{'\0'};//Contient un caractere de fin de texte
    strcat(textVie,textFinDeTextVie);//Concatene les deux chaines de caracteres

    GraphicPrimitives::drawText2D(textVie,-0.96,0.90, r, g, b,alpha);//Draw le texte relatif a la vie du Joueur.

    //Affichage des informations concernant l'attribut m_argent
    char * textArgent=new char[20]{'A','r','g','e','n','t',':','\0'};//Contient le texte immuable concernant l'attribut m_argent
    char valueArgent[10];//Contiendra la valeur de la vie du Joueur
    sprintf(valueArgent, "%d", m_argent);//Stock la valeur de l'attribut m_argent dans un tableau de char
    strcat(textArgent,valueArgent);//Concatene les deux chaines de caracteres
    char * textFinDeTextArgent=new char[1]{'\0'};//Contient un caractere de fin de texte
    strcat(textArgent,textFinDeTextArgent);//Concatene les deux chaines de caracteres

    GraphicPrimitives::drawText2D(textArgent,-0.98,0.80, r, g, b,alpha);//Draw le texte relatif a l'argent du Joueur.

    //Affichage des informations concernant l'attribut m_level
    char * textLevel=new char[20]{'L','e','v','e','l',':',' ','\0'};//Contient le texte immuable concernant l'attribut m_level
    char valueLevel[10];//Contiendra la valeur de la vie du Joueur
    sprintf(valueLevel, "%d", m_level);//Stock la valeur de l'attribut m_level dans un tableau de char
    strcat(textLevel,valueLevel);//Concatene les deux chaines de caracteres
    char * textFinDeTextLevel=new char[1]{'\0'};//Contient un caractere de fin de texte
    strcat(textLevel,textFinDeTextLevel);//Concatene les deux chaines de caracteres

    GraphicPrimitives::drawText2D(textLevel,-0.97,0.70, r, g, b,alpha);//Draw le texte relatif au niveau de la grille (Level).

    //Affichage des informations concernant l'attribut m_numberMonstreKilled
    char * textNumberMonstreKilledPart1=new char[20]{'M','O','N','S','T','E','R','\0'};//Contient le texte immuable concernant l'attribut m_numberMonstreKilled
    GraphicPrimitives::drawText2D(textNumberMonstreKilledPart1,-0.98,0.50, r, g, b,alpha);//Draw le texte immuable relatif au nombre de Monstre elimines par le Joueur.
    char * textNumberMonstreKilled=new char[10]{'K','I','L','L','E','D',':','\0'};//Contient le texte immuable concernant l'attribut m_numberMonstreKilled
    char valueNumberMonstreKilled[10];//Contiendra le nombre de Monstre elimines par le Joueur
    sprintf(valueNumberMonstreKilled, "%d", m_numberMonstreKilled);//Stock la valeur de l'attribut m_numberMonstreKilled dans un tableau de char
    strcat(textNumberMonstreKilled,valueNumberMonstreKilled);//Concatene les deux chaines de caracteres
    char * textFinDeTextNumberMonstreKilled=new char[1]{'\0'};//Contient un caractere de fin de texte
    strcat(textNumberMonstreKilled,textFinDeTextNumberMonstreKilled);//Concatene les deux chaines de caracteres

    GraphicPrimitives::drawText2D(textNumberMonstreKilled,-0.97,0.43, r, g, b,alpha);//Draw le texte relatif au nombre de Monstre elimines par le Joueur.

    //Affichage des informations concernant l'attribut m_score
    char * textScore=new char[20]{'S','c','o','r','e',':','\0'};//Contient le texte immuable concernant l'attribut m_score
    char valueScore[10];//Contiendra la valeur du score du Joueur
    sprintf(valueScore, "%d", m_score);//Stock la valeur de l'attribut m_score dans un tableau de char
    strcat(textScore,valueScore);//Concatene les deux chaines de caracteres
    char * textFinDeTextScore=new char[1]{'\0'};//Contient un caractere de fin de texte
    strcat(textScore,textFinDeTextScore);//Concatene les deux chaines de caracteres

    GraphicPrimitives::drawText2D(textScore,-0.97,0.33, r, g, b,alpha);//Draw le texte relatif au score du Joueur.

}

/*
@description:
La methode receiveDamage de la classe Joueur prend un int en parametre et fait baisser la vie du Joueur d'une valeur egale a la valeur du int pris en parametre.

@param: La methode receiveDamage prend un parametre obligatoire: un int.
-param1: Le int doit representer la valeur du dommage subis par le Joueur.
*/
void Joueur::receiveDamage(int const& damage){
    int const vieAfterDamage=m_vie-damage;
    //Si la vie apres les degats recus est superieur ou egale a 0
    if(vieAfterDamage >= 0){
        m_vie-=damage;
    }
    //Sinon
    else{
        m_vie=0;//On met la vie a 0
    }

}

/*
@description:
La methode spendMoney de la classe Joueur prend un int en parametre et fait baisser l'argent du Joueur d'une valeur egale a la valeur du int pris en parametre.

@param: La methode spendMoney prend un parametre obligatoire: un int.
-param1: Le int doit representer la valeur de l'argent depense par le Joueur.
*/
void Joueur::spendMoney(int const& cost){
    int const argentAfterSpend=m_argent-cost;
    //Si l'argent apres la depense est superieur ou egale a 0
    if(argentAfterSpend >= 0){
       m_argent-=cost;
    }
    else{
        m_argent=0;//On met l'argent a 0
    }
}

/*
@description:
La methode earnMoney de la classe Joueur prend un int en parametre et augmente l'argent du Joueur d'une valeur egale a la valeur du int pris en parametre.

@param: La methode earnMoney prend un parametre obligatoire: un int.
-param1: Le int doit representer la valeur de l'argent gagne par le Joueur.
*/
void Joueur::earnMoney(int const& gain){
    m_argent+=gain;
}

/*
@description:
La methode oneMoreKilled de la classe Joueur augmente de 1 le nombre de Monstre elimines par le Joueur.

@param: null
*/
void Joueur::oneMoreKilled(){
    m_numberMonstreKilled++;
}

/*
@description:
La methode increaseLevel de la classe Joueur augmente de 1 l'attribut m_level.

@param: null
*/
void Joueur::increaseLevel(){
    m_level++;
}

/*
@description:
La methode decreaseLevel de la classe Joueur diminue de 1 l'attribut m_level.

@param: null
*/
void Joueur::decreaseLevel(){
    m_level--;
}

/*
@description:
La methode increaseScore de la classe Joueur prend un int en parametre et augmente le score du Joueur d'une valeur egale a la valeur du int pris en parametre.

@param: La methode increaseScore prend un parametre obligatoire: un int.
-param1: Le int doit representer la valeur du score gagne par le Joueur.
*/
void Joueur::increaseScore(int const& award){
    m_score+=award;
}

/*
@description:
La methode isDead de la classe Joueur renvoie 1 si la vie du Joueur est egale a 0 et 0 sinon.

@param: null
*/
int Joueur::isDead() const{
    if(m_vie <= 0){
        return 1;
    }
    else{
        return 0;
    }
}

/*
@description:
La methode gameOver de la classe Joueur permet d'afficher le message Game-Over de maniere graphique.

@param: null
*/
void Joueur::gameOver() const{

    //Met les valeurs RGB dans la couleur blanche
    float const r=1.0;
    float const g=1.0;
    float const b=1.0;
    float const alpha = 1.0;

    //Affichage du texte Game Over
    char * textGameOver=new char[10]{'G','A','M','E',' ','O','V','E','R','\0'};//Contient le texte GAME OVER.

    LibMatrix::drawLargeText2D(textGameOver,-0.1,0.0, 1, r, g, b,alpha);//Draw le texte textGameOver.

}

/*
@description:
La methode winGame de la Class Joueur permet d'afficher le message de felicitation de maniere graphique.

@param: null
*/
void Joueur::winGame() const{

                //Met les valeurs RGB dans la couleur blanche
                float const r=1.0;
                float const g=1.0;
                float const b=1.0;
                float const alpha = 1.0;

                //Affichage du texte Game Over
                char * textCongratulation1=new char[10]{'Y','O','U',' ','W','I','N','!','\0'};//Contient le texte YOU WIN!.
                char * textCongratulation2=new char[20]{'C','O','N','G','R','A','T','U','L','A','T','I','O','N','!','\0'};//Contient le texte CONGRATULATION!.
                char * textCongratulation3=new char[93]{'T','o',' ','c','h','a','n','g','e',' ','t','h','e',' ','P','a','t','h',' ','o','f',' ','t','h','i','s',' ','L','e','v','e','l',',',' ','l','o','o','k',' ','t','h','e',' ','f','i','l','e',' ','"','L','e','v','e','l','_','0','.','t','x','t','"',' ','i','n',' ','t','h','e',' ','d','i','r','e','c','t','o','r','y',':',' ','L','e','v','e','l','_','P','l','a','y','e','r','\0'};//Contient le texte CONGRATULATION!.

                LibMatrix::drawLargeText2D(textCongratulation1,-0.1,0.0, 1, r, g, b,alpha);//Draw le texte textCongratulation1.
                LibMatrix::drawLargeText2D(textCongratulation2,-0.22,-0.1, 1, r, g, b,alpha);//Draw le texte textCongratulation2.
                LibMatrix::drawLargeText2D(textCongratulation3,-0.88,-0.5, 1, r, g, b,alpha);//Draw le texte textCongratulation3.

}

/*
@description:
Renvoie 1 si le Joueur a assez d'argent pour payer le cout pris en parametre et 0 sinon. Ainsi, si m_money-cost>=0 alors on renvoie 1 et 0 sinon.

@param: La methode haveMoneyEnough prend un parametre obligatoire: un int.
-param1: Le int doit representer la cout de la tourelle que le Joueur veut s'acheter.
*/
int Joueur::haveMoneyEnough(int const& cost) const{
    int const argentAfterSpend= m_argent-cost;
    if(argentAfterSpend >= 0){
        return 1;
    }
    else{
        return 0;
    }
}

/*
@description:
La methode LoadGame de la Class Joueur met les attributs du Joueur avec les valeurs lues dans des fichiers.

@param: La methode LoadGame prend un parametre facultatif: un string facultatif.
-param1: Le string facultatif permet de specifier le nom du repertoire ou des multiples repertoires ou est stocke le fichier dont on souhaite ecrire les attributs du Joueur. Par defaut, le repertoire se nomme SlotDataBackup.
*/
void Joueur::LoadGame(string const& stringNameDirectory){

    m_vie=LibMatrix::loadIntInFileWithDirectory("BackupVie",stringNameDirectory);//On set l'attribut m_vie par la valeur lu dans le fichier BackupVie
    m_argent=LibMatrix::loadIntInFileWithDirectory("BackupArgent",stringNameDirectory);//On set l'attribut m_argent par la valeur lu dans le fichier BackupArgent
    m_level=LibMatrix::loadIntInFileWithDirectory("BackupLevel",stringNameDirectory);//On set l'attribut m_level par la valeur lu dans le fichier BackupLevel
    m_numberMonstreKilled=LibMatrix::loadIntInFileWithDirectory("BackupNumberMonstreKilled",stringNameDirectory);//On set l'attribut m_numberMonstreKilled par la valeur lu dans le fichier BackupNumberMonstreKilled
    m_score=LibMatrix::loadIntInFileWithDirectory("BackupScore",stringNameDirectory);//On set l'attribut m_score par la valeur lu dans le fichier BackupScore
}

/*
@description:
La methode SaveGame de la Class Joueur ecrit dans des fichiers (ecriture par ecrasement des donnees) les attributs du Joueur.

@param: La methode SaveGame prend un parametre facultatif: un string facultatif.
-param1: Le string facultatif permet de specifier le nom du repertoire ou des multiples repertoires ou est stocke le fichier dont on souhaite ecrire les attributs du Joueur. Par defaut, le repertoire se nomme SlotDataBackup.
*/
void Joueur::SaveGame(string const& stringNameDirectory) const{

    LibMatrix::writeIntInFileWithEraseData("BackupVie",m_vie,stringNameDirectory);//Ecriture par ecrasement des donnees de l'attribut m_vie dans le fichier BackupVie
    LibMatrix::writeIntInFileWithEraseData("BackupArgent",m_argent,stringNameDirectory);//Ecriture par ecrasement des donnees de l'attribut m_argent dans le fichier BackupArgent
    LibMatrix::writeIntInFileWithEraseData("BackupLevel",m_level,stringNameDirectory);//Ecriture par ecrasement des donnees de l'attribut m_level dans le fichier BackupLevel
    LibMatrix::writeIntInFileWithEraseData("BackupNumberMonstreKilled",m_numberMonstreKilled,stringNameDirectory);//Ecriture par ecrasement des donnees de l'attribut m_numberMonstreKilled dans le fichier BackupNumberMonstreKilled
    LibMatrix::writeIntInFileWithEraseData("BackupScore",m_score,stringNameDirectory);//Ecriture par ecrasement des donnees de l'attribut m_score dans le fichier BackupScore
}
