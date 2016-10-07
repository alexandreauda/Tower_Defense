#include "MyGraphicEngine.h"



void MyGraphicEngine::Draw(){

    Block block[12][12];

		for(int y=0;y<12;y++){
			for(int x=0;x<12;x++){
				block[y][x]= Block((600/2) - ((worldWidth*blockSize)/2) + (x*blockSize),y*blockSize,blockSize,blockSize,245.0,245.0,220.0,1.0, 0, -1);
				block[y][x].draw();
			}
		}


}

