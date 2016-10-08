#include "MyGraphicEngine.h"



void MyGraphicEngine::Draw(){

    Block block[12][12];

		for(int y=0;y<12;y++){
			for(int x=0;x<12;x++){
				block[y][x]= Block((600/2) - ((m_worldWidth*m_blockSize)/2) + (x*m_blockSize),y*m_blockSize,m_blockSize,m_blockSize,1,0,0,1.0, 0, -1);
				block[y][x].draw();
			}
		}


}

