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
    char * textVie=new char[20]{'V','i','e',':',' '};//Contient le texte immuable concernant l'attribut m_vie
    char valueVie[10];//Contiendra la valeur de la vie du Joueur
    sprintf(valueVie, "%d", m_vie);//Stock la valeur de l'attribut m_vie dans un tableau de char
    strcat(textVie,valueVie);//Concatene les deux chaines de caracteres

    GraphicPrimitives::drawText2D(textVie,-0.96,0.90, r, g, b,alpha);//Draw le texte relatif a la vie du Joueur.

    //Affichage des informations concernant l'attribut m_argent
    char * textArgent=new char[20]{'A','r','g','e','n','t',':'};//Contient le texte immuable concernant l'attribut m_argent
    char valueArgent[10];//Contiendra la valeur de la vie du Joueur
    sprintf(valueArgent, "%d", m_argent);//Stock la valeur de l'attribut m_argent dans un tableau de char
    strcat(textArgent,valueArgent);//Concatene les deux chaines de caracteres

    GraphicPrimitives::drawText2D(textArgent,-0.98,0.80, r, g, b,alpha);//Draw le texte relatif a l'argent du Joueur.

    //Affichage des informations concernant l'attribut m_level
    char * textLevel=new char[20]{'L','e','v','e','l',':',' '};//Contient le texte immuable concernant l'attribut m_level
    char valueLevel[10];//Contiendra la valeur de la vie du Joueur
    sprintf(valueLevel, "%d", m_level);//Stock la valeur de l'attribut m_level dans un tableau de char
    strcat(textLevel,valueLevel);//Concatene les deux chaines de caracteres

    GraphicPrimitives::drawText2D(textLevel,-0.97,0.70, r, g, b,alpha);//Draw le texte relatif au niveau de la grille (Level).

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

    //Affichage des informations concernant l'attribut m_vie
    char * textGameOver=new char[9]{'G','A','M','E',' ','O','V','E','R'};//Contient le texte GAME OVER.

    LibMatrix::drawLargeText2D(textGameOver,-0.1,0.0, 1, r, g, b,alpha);//Draw le texte textGameOver.

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
