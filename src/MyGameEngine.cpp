
#include "MyGameEngine.h"


void MyGameEngine::idle(){

            //NEW
        for(int i=0;i<m_MonstreList->size();i++){
            (*m_MonstreList)[i]->walk();
		}
}
