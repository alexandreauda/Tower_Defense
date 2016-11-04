#include "BlockStartMonstre.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/
//null


/******IMPLEMENTATION DES MUTATEURS******/

/*
@description:
Mutateur de l'attribut m_colorPlayID.

@param: La methode setm_colorPlayID prend un parametre obligatoire: un int
-param1: le nouvel id pour m_colorPlayID
*/
void BlockStartMonstre::setm_colorPlayID (int const& colorPlayID){
 m_colorPlayID=colorPlayID;
}


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode draw de la classe BlockStartMonstre permet de dessiner  de maniere graphique le bouton qui lancera les vagues de monstres.

@param: null
*/
void BlockStartMonstre::draw() const
{
    float const alpha=1.0;

     if (m_colorBlockID == 0){ //si le m_colorBlockID du bloc est egale a 0
         //on met les contantes RGB a vert
        float const r=0.0;
        float const g=1.0;
        float const b=0.0;
        //on dessine le bouton en vert
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha); //on affiche le bloc en carre vert

        //Couleur RGB pour la couleur du Play
        float pR;
        float pG;
        float pB;

        switch(m_colorPlayID){//switch le couleur du Play

            case 0: //on met un triangle blanc dans le block
                    pR=1.0;
                    pG=1.0;
                    pB=1.0;
                    //on dessine dans le bouton un triangle blanc pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle blanc dans le block
                    break;

            case 1: //on met un triangle jaune dans le block
                    pR=1.0;
                    pG=1.0;
                    pB=0.0;
                    //on dessine dans le bouton un triangle jaune pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle jaune dans le block
                    break;

            case 2: //on met un triangle orange dans le block
                    pR=1.0;
                    pG=0.4;
                    pB=0.0;
                    //on dessine dans le bouton un triangle orange pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle orange dans le block
                    break;

            case 3: //on met un triangle violet dans le block
                    pR=1.0;
                    pG=0.1;
                    pB=0.9;
                    //on dessine dans le bouton un triangle violet pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle violet dans le block
                    break;

            default: break;
        }

     }
    else if(m_colorBlockID == 1){ //si le m_colorBlockID du bloc est egale a 1
        //on met les contantes RGB au rouge
        float const r=1.0;
        float const g=0.0;
        float const b=0.0;
        //on dessine le bouton en rouge
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha);//on affiche le bloc en carre rouge

        //Couleur RGB pour la couleur du Play
        float pR;
        float pG;
        float pB;

        switch(m_colorPlayID){//switch le couleur du Play

            case 0: //on met un triangle blanc dans le block
                    pR=1.0;
                    pG=1.0;
                    pB=1.0;
                    //on dessine dans le bouton un triangle blanc pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle blanc dans le block
                    break;

            case 1: //on met un triangle jaune dans le block
                    pR=1.0;
                    pG=1.0;
                    pB=0.0;
                    //on dessine dans le bouton un triangle jaune pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle jaune dans le block
                    break;

            case 2: //on met un triangle orange dans le block
                    pR=1.0;
                    pG=0.4;
                    pB=0.0;
                    //on dessine dans le bouton un triangle orange pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle orange dans le block
                    break;

            case 3: //on met un triangle violet dans le block
                    pR=1.0;
                    pG=0.1;
                    pB=0.9;
                    //on dessine dans le bouton un triangle violet pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle violet dans le block
                    break;

            default: break;
        }


         }
    else{ //si le m_colorBlockID possede toutes autres valeurs
        //on met les contantes RGB au bleu
        float const r=0.0;
        float const g=0.0;
        float const b=1.0;
        //on dessine le bouton en bleu
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha); //on affiche le bloc en carre bleu

        //Couleur RGB pour la couleur du Play
        float pR;
        float pG;
        float pB;

        switch(m_colorPlayID){//switch le couleur du Play

            case 0: //on met un triangle blanc dans le block
                    pR=1.0;
                    pG=1.0;
                    pB=1.0;
                    //on dessine dans le bouton un triangle blanc pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle blanc dans le block
                    break;

            case 1: //on met un triangle jaune dans le block
                    pR=1.0;
                    pG=1.0;
                    pB=0.0;
                    //on dessine dans le bouton un triangle jaune pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle jaune dans le block
                    break;

            case 2: //on met un triangle orange dans le block
                    pR=1.0;
                    pG=0.4;
                    pB=0.0;
                    //on dessine dans le bouton un triangle orange pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle orange dans le block
                    break;

            case 3: //on met un triangle violet dans le block
                    pR=1.0;
                    pG=0.1;
                    pB=0.9;
                    //on dessine dans le bouton un triangle violet pour le Play
                    GraphicPrimitives::drawFillTriangle2D(m_posx+m_width/6, m_posy+m_height/6, m_posx+m_width*5/6, m_posy+m_height/2, m_posx+m_width/6, m_posy+m_height*5/6, pR, pG, pB, alpha); //on affiche un triangle violet dans le block
                    break;

            default: break;
        }
    }
}
