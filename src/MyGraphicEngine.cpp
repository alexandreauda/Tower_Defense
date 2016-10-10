#include "MyGraphicEngine.h"



void MyGraphicEngine::Draw(){

    Block block[12][12];


		for(int y=0;y<12;y++){
			for(int x=0;x<12;x++){

	double nombre_aleatoire = 0;
	srand(time(NULL)); // initialisation de rand
	double tab[3];
	for(int i=0; i<3; i++){
		nombre_aleatoire = rand()%2;
        tab[i]=nombre_aleatoire;
	}
                   int r= tab[0];
                   int g= tab[1];
                   int b= tab[2];

				block[y][x]= Block(-x*m_blockSize-0.1*x+0.8,-y*m_blockSize+0.2*y-0.8,m_blockSize,m_blockSize,1.0,0.0,0,1.0, 0, -1);
                (block[y][x]).draw(r,g,b);
			}
		}


/*
double nombre_aleatoire = 0;
	srand(time(NULL)); // initialisation de rand
	double tab[3];
	for(int i=0; i<3; i++){
		nombre_aleatoire = rand()%2;
        tab[i]=nombre_aleatoire;
	}
int r= tab[0];
                   int g= tab[1];
                   int b= tab[2];

				block[0][0]= Block(0*m_blockSize,-1*m_blockSize,m_blockSize,m_blockSize,1.0,0.0,0,1.0, 0, -1);
                (block[0][0]).draw(r,g,b);*/
}

