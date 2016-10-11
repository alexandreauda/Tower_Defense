#include "MyGraphicEngine.h"

/******IMPLEMENTATION DES METHODES******/

void MyGraphicEngine::Draw(){

    Block block[12][12];
    float const r=0.0;
    float const g=1.0;
    float const b=0.0;
    float const alpha=1.0;


		for(int y=0;y<12;y++){
			for(int x=0;x<12;x++){
            Value v;

				block[y][x]= Block(-x*m_blockSize-0.1*x+0.8,-y*m_blockSize+0.2*y-0.8,m_blockSize,m_blockSize,r,g,b,alpha, v.getm_groundGrass());
                    //Creer la classe Save avec la méthode loadSave()

                    //Save save;
                    //save.loadSave("level_1");
                   (block[y][x]).draw();

			}
		}

}

