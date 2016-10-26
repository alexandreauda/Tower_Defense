#include "IAClever.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode isEndWay renvoie 1 si le monstre est sur la derniere colonne de la grille et 0 sinon.

@param: null
*/
int IAClever::isEndWay() const{
    //Si le monstre se trouve sur la derniere colonne de grille
    if(m_actualPosition.getm_posyID() == 11){
        return 1;//Renvoi 1
    }
    //Sinon
    else{
        return 0;//Renvoi 0
    }
}


BlockGrille IAClever::searchInitWay(){
  //TODO
  //return
}

 BlockGrille IAClever::searchWay(BlockGrille grilleDeJeu[12][12]) const{
    //TODO
    //return
 }
