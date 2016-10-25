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

BlockGrille Monstre::searchInitPath(){
  BlockGrille blockInitPath =  m_monstreIA->searchInitWay();
  return blockInitPath;
}

 BlockGrille Monstre::searchPath(){
    BlockGrille nextBlockPath = m_monstreIA->searchWay();
    return nextBlockPath;
 }

void Monstre::moveSmoothly(){

}

void Monstre::walk(){

}
