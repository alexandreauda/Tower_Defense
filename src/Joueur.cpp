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

