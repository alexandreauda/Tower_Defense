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

void Monstre::moveSmoothly(BlockGrille nextPosition){

}

void Monstre::walk(){

}

/******METHODE DE CLASSE: OPERATEURS******/
Monstre& Monstre::operator=(Monstre const& monstreAcopier){
    if(this != &monstreAcopier){//on vérifie que l'objet n'est pas le même que l'objetAcopié reçu en argument
        //on copie tous les attributs qui ne sont pas des objets membres
        m_m1= monstreAcopier.m_m1;
        //traitements des pointeurs objets membres
        delete m_monstreIA;//on détruit l'objet membre pour ensuite le recréé avec l'objet membre de l'objet copié

        if((monstreAcopier.m_monstreIA)->getClass() == "IAOnePath"){//si l'IA du monstre à copier est une IA IAOnePath
          m_monstreIA= new IAOnePath(); //on initialise l'IA du monstre avec l'IA IAOnePath puisque c'est celle du monstreAcopier
        }
        else if((monstreAcopier.m_monstreIA)->getClass() == "IASeveralPaths"){//si l'IA du monstre à copier est une IA IASeveralPaths
             m_monstreIA= new IASeveralPaths(); //on initialise l'IA du monstre avec l'IA IASeveralPaths puisque c'est celle du monstreAcopier
        }
        else if((monstreAcopier.m_monstreIA)->getClass() == "IAClever"){//si l'IA du monstre à copier est une IA IAClever
             m_monstreIA= new IAClever(); //on initialise l'IA du monstre avec l'IA IAClever puisque c'est celle du monstreAcopier
        }
        else{
            m_monstreIA= new IAClever(); //par défaut, on initialise l'IA du monstre avec l'IA IAClever si l'IA du monstreAcopier n'est pas lisible
        }

    }
    return *this;
}

