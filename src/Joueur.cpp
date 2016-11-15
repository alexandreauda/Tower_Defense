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

    GraphicPrimitives::drawText2D(textVie,-0.96,0.90, r, g, b,alpha);

    //Affichage des informations concernant l'attribut m_argent
    char * textArgent=new char[20]{'A','r','g','e','n','t',':'};//Contient le texte immuable concernant l'attribut m_argent
    char valueArgent[10];//Contiendra la valeur de la vie du Joueur
    sprintf(valueArgent, "%d", m_argent);//Stock la valeur de l'attribut m_argent dans un tableau de char
    strcat(textArgent,valueArgent);//Concatene les deux chaines de caracteres

    GraphicPrimitives::drawText2D(textArgent,-0.98,0.80, r, g, b,alpha);

    //Affichage des informations concernant l'attribut m_level
    char * textLevel=new char[20]{'L','e','v','e','l',':',' '};//Contient le texte immuable concernant l'attribut m_level
    char valueLevel[10];//Contiendra la valeur de la vie du Joueur
    sprintf(valueLevel, "%d", m_level);//Stock la valeur de l'attribut m_level dans un tableau de char
    strcat(textLevel,valueLevel);//Concatene les deux chaines de caracteres

    GraphicPrimitives::drawText2D(textLevel,-0.97,0.70, r, g, b,alpha);

}
