#include "BlockStore.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/

/*
@description:
Accesseur de l'attribut m_posID.

@param: null
*/
int BlockStore::getm_posID() const{
    return m_posID;
}


/******IMPLEMENTATION DES MUTATEURS******/

/*
@description:
Mutateur de l'attribut m_posID.

@param: La methode setm_posID prend un parametre obligatoire: un int
-param1: le nouvel id pour m_posID
*/
void BlockStore::setm_posID (int const& posID){
 m_posID=posID;
}


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode draw de la classe BlockStore permet de dessiner des blocs de maniere graphique.

@param: null
*/
void BlockStore::draw() const
{
    float const alpha=1.0;

     if (m_colorBlockID == 0){ //si le m_colorBlockID du bloc est egale a 0
         //on met les contantes RGB a vert
        float const r=0.0;
        float const g=1.0;
        float const b=0.0;
        //on dessine les cases du Store en vert
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha); //on affiche le bloc en carre vert

                //Couleur RGB pour la couleur des tourelles qui s'affiche dans le Store
        float tR;
        float tG;
        float tB;

        switch(m_posID){//switch le numero du block

            case 0: //La premiere case qui correspond a la corbeille du Store
                    //on met un carre blanc pour signifier qu'il s'agit de la corbeille
                    tR=1.0;
                    tG=1.0;
                    tB=1.0;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc blanc dans le block du Store pour representer la corbeille
                    break;

            case 1: //La deuxieme case qui correspond au stock de tourelles jaunes dans le Store
                    //on met un carre jaune pour signifier qu'il s'agit du stock de tourelles de couleur jaune
                    tR=1.0;
                    tG=1.0;
                    tB=0.0;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc jaune dans le block du Store pour representer une tourelle jaune
                    break;

            case 2: //La troisieme case qui correspond au stock de tourelles oranges dans le Store
                    //on met un carre orange pour signifier qu'il s'agit du stock de tourelles de couleur orange
                    tR=1.0;
                    tG=0.4;
                    tB=0.0;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc orange dans le block du Store pour representer une tourelle orange
                    break;

            case 3: //La quatrieme case qui correspond au stock de tourelles violette dans le Store
                    //on met un carre violet pour signifier qu'il s'agit du stock de tourelles de couleur violette
                    tR=1.0;
                    tG=0.1;
                    tB=0.9;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc violet dans le block du Store pour representer une tourelle violette
                    break;

            default: break;
        }
     }
    else if(m_colorBlockID == 1){ //si le m_colorBlockID du bloc est egale a 1
        //on met les contantes RGB au rouge
        float const r=1.0;
        float const g=0.0;
        float const b=0.0;
        //on dessine les cases du Store en rouge
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha);//on affiche le bloc en carre rouge

                //Couleur RGB pour la couleur des tourelles qui s'affiche dans le Store
        float tR;
        float tG;
        float tB;

        switch(m_posID){//switch le numero du block

            case 0: //La premiere case qui correspond a la corbeille du Store
                    //on met un carre blanc pour signifier qu'il s'agit de la corbeille
                    tR=1.0;
                    tG=1.0;
                    tB=1.0;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc blanc dans le block du Store pour representer la corbeille
                    break;

            case 1: //La deuxieme case qui correspond au stock de tourelles jaunes dans le Store
                    //on met un carre jaune pour signifier qu'il s'agit du stock de tourelles de couleur jaune
                    tR=1.0;
                    tG=1.0;
                    tB=0.0;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc jaune dans le block du Store pour representer une tourelle jaune
                    break;

            case 2: //La troisieme case qui correspond au stock de tourelles oranges dans le Store
                    //on met un carre orange pour signifier qu'il s'agit du stock de tourelles de couleur orange
                    tR=1.0;
                    tG=0.4;
                    tB=0.0;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc orange dans le block du Store pour representer une tourelle orange
                    break;

            case 3: //La quatrieme case qui correspond au stock de tourelles violette dans le Store
                    //on met un carre violet pour signifier qu'il s'agit du stock de tourelles de couleur violette
                    tR=1.0;
                    tG=0.1;
                    tB=0.9;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc violet dans le block du Store pour representer une tourelle violette
                    break;

            default: break;
        }
         }
    else{ //si le m_colorBlockID possede toutes autres valeurs
        //on met les contantes RGB au bleu
        float const r=0.0;
        float const g=0.0;
        float const b=1.0;
        //on dessine les cases du Store en bleu
        GraphicPrimitives::drawFillRect2D(m_posx, m_posy, m_width, m_height, r, g, b, alpha); //on affiche le bloc en carre bleu

        //Couleur RGB pour la couleur des tourelles qui s'affiche dans le Store
        float tR;
        float tG;
        float tB;

        switch(m_posID){//switch le numero du block

            case 0: //La premiere case qui correspond a la corbeille du Store
                    //on met un carre blanc pour signifier qu'il s'agit de la corbeille
                    tR=1.0;
                    tG=1.0;
                    tB=1.0;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc blanc dans le block du Store pour representer la corbeille
                    break;

            case 1: //La deuxieme case qui correspond au stock de tourelles jaunes dans le Store
                    //on met un carre jaune pour signifier qu'il s'agit du stock de tourelles de couleur jaune
                    tR=1.0;
                    tG=1.0;
                    tB=0.0;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc jaune dans le block du Store pour representer une tourelle jaune
                    break;

            case 2: //La troisieme case qui correspond au stock de tourelles oranges dans le Store
                    //on met un carre orange pour signifier qu'il s'agit du stock de tourelles de couleur orange
                    tR=1.0;
                    tG=0.4;
                    tB=0.0;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc orange dans le block du Store pour representer une tourelle orange
                    break;

            case 3: //La quatrieme case qui correspond au stock de tourelles violette dans le Store
                    //on met un carre violet pour signifier qu'il s'agit du stock de tourelles de couleur violette
                    tR=1.0;
                    tG=0.1;
                    tB=0.9;
                    GraphicPrimitives::drawFillRect2D(m_posx+m_width/6, m_posy+m_height/6, m_width*2/3, m_height*2/3, tR, tG, tB, alpha); //on affiche un bloc violet dans le block du Store pour representer une tourelle violette
                    break;

            default: break;
        }
    }
}
