#include "MyGameEngine.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/
//null


/******IMPLEMENTATION DES MUTATEURS******/
//null


/******IMPLEMENTATION DES METHODES******/

void MyGameEngine::idle(){

        for(int i=0;i<m_MonstreList->size();i++){
            (*m_MonstreList)[i]->walk();
		}
}
