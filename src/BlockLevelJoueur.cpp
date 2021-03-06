#include "BlockLevelJoueur.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/
//null


/******IMPLEMENTATION DES MUTATEURS******/
//null


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode draw de la Class BlockLevelJoueur permet de dessiner de maniere graphique le bouton qui permet de commencer une partie sur un niveau exclusivement dedie au Joueur. C'est donc exclusivement le Joueur qui definit le trace du chemin des Monstres de ce niveau.

@param: null
*/
void BlockLevelJoueur::draw() const
{
    float const alpha=1.0;
    char* textSaveGame=new char[20]{'L','E','V','E','L',' ','P','L','A','Y','E','R','\0'};//Contient le texte LEVEL PLAYER.

     if (m_colorBlockID == 0){ //si le m_colorBlockID du bloc est egale a 0
         //on met les contantes RGB a vert
        float const r=0.0;
        float const g=1.0;
        float const b=0.0;
        //on dessine le bouton en vert
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha); //on affiche le bloc en carre vert

        LibMatrix::drawLargeText2D(textSaveGame, m_posx+m_width*1/7,m_posy+m_height*1/3+0.007, 1, 1.0, 1.0, 1.0, 1.0);
     }

    else if(m_colorBlockID == 1){ //si le m_colorBlockID du bloc est egale a 1
        //on met les contantes RGB au rouge
        float const r=1.0;
        float const g=0.0;
        float const b=0.0;
        //on dessine le bouton en rouge
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha);//on affiche le bloc en carre rouge

        LibMatrix::drawLargeText2D(textSaveGame, m_posx+m_width*1/7,m_posy+m_height*1/3+0.007, 1, 1.0, 1.0, 1.0, 1.0);
        }

    else{ //si le m_colorBlockID possede toutes autres valeurs
        //on met les contantes RGB au bleu
        float const r=0.0;
        float const g=0.0;
        float const b=1.0;
        //on dessine le bouton en bleu
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha); //on affiche le bloc en carre bleu

        LibMatrix::drawLargeText2D(textSaveGame, m_posx+m_width*1/15,m_posy+m_height*1/3+0.007, 1, 1.0, 1.0, 1.0, 1.0);
    }
}
