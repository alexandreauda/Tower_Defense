#include "Monstre.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

void Monstre::init(string nomIA){
    if(nomIA=="IAOnePath"){
            m_monstreIA = new IAOnePath();
    }
    else{
            if(nomIA=="IASeveralPaths"){
                m_monstreIA = new IASeveralPaths();
            }
            else{
               if(nomIA=="IAClever"){
                m_monstreIA = new IAClever();
                }
                else{
                    m_monstreIA = new IAOnePath();
                }
            }
    }
}

/*
@description:
La methode isEndPath renvoie 1 si le monstre est sur la derniere colonne de la grille et 0 sinon.

@param: null
*/
int Monstre::isEndPath() const{
int endPathBool = m_monstreIA->isEndWay();
return endPathBool;
}

BlockGrille Monstre::searchInitPath(BlockGrille grilleDeJeu[12][12]) const{
  BlockGrille blockInitPath =  m_monstreIA->searchInitWay(grilleDeJeu);
  return blockInitPath;
}

 BlockGrille Monstre::searchPath(BlockGrille grilleDeJeu[12][12]) const{
    BlockGrille nextBlockPath = m_monstreIA->searchWay(grilleDeJeu);
    return nextBlockPath;
 }

void Monstre::moveSmoothly(){

}

void Monstre::walk(){

}
