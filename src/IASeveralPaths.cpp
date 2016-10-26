#include "IASeveralPaths.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode isEndWay renvoie 1 si le monstre est sur la derniere colonne de la grille et 0 sinon.

@param: null
*/
int IASeveralPaths::isEndWay() const{
    //Si le monstre se trouve sur la derniere colonne de grille
    if(m_actualPosition.getm_posyID() == 11){
        return 1;//Renvoi 1
    }
    //Sinon
    else{
        return 0;//Renvoi 0
    }
}



BlockGrille IASeveralPaths::searchInitWay(){
  //TODO
  //return
}

 BlockGrille IASeveralPaths::searchWay(BlockGrille grilleDeJeu[12][12]) const{
    //TODO
    //return
 }
