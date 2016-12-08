#include "Store.h"

using namespace std;


/******IMPLEMENTATION DES ACCESSEURS******/
//null


/******IMPLEMENTATION DES MUTATEURS******/
//null



/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode loadStore permet d'initialiser un vecteur statique pris en parametre avec des blocks de carasteristiques differentes.
Le vecteur statique en parametre est modifiee par la methode car il est passe par reference.

@param: La methode loadStore prend un parametre obligatoire: un vecteur statique de type BlockStore et de dimension 12.
-param1: un vecteur statique de type BlockStore et de dimension 12 qui va etre modifie pour etre initialise avec des blocks de carasteristiques differentes.
*/
void Store::loadStore(BlockStore stockStore[12]) const {

for(int i=0;i<12;i++){

				stockStore[i]= BlockStore(-i*m_shopCellWidth-0.004*i+0.67, -0.85, m_shopCellWidth, m_shopCellHeight);//on initialise le tableau stockStore[] avec des blocs

                (stockStore[i]).setm_posID(11-i);//on numerote les blocks au fur et a mesure

                (stockStore[i]).setm_colorBlockID(2);//on set l'ID

			}
}


/*
@description:
La methode draw de la classe Store permet de dessiner l'inventaire de maniere graphique.

@param: null
*/
void Store::draw() const {

BlockStore stockStore[12];//on definit un tableau vide de longueur 12 de type BlockStore
loadStore(stockStore);//on initialise le vecteur statique stockStore pris en parametre avec des blocks de carasteristiques differentes


char * textCorbeille=new char[5]{'B','I','N','\0'};//Contient le texte pour indiquer la corbeille

char * textCostTowerDefenseYellow=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle jaune
char valueCostTowerDefenseYellow[10];//Contiendra la valeur du cout d'une tourelle jaune
sprintf(valueCostTowerDefenseYellow, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseYellow.txt"));//Stock la valeur du cout d'une tourelle jaune dans un tableau de char
strcat(textCostTowerDefenseYellow,valueCostTowerDefenseYellow);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefenseYellow=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefenseYellow,textFinDeTextCostTowerDefenseYellow);//Concatene les deux chaines de caracteres

char * textCostTowerDefenseOrange=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle orange
char valueCostTowerDefenseOrange[10];//Contiendra la valeur du cout d'une tourelle orange
sprintf(valueCostTowerDefenseOrange, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseOrange.txt"));//Stock la valeur du cout d'une tourelle orange dans un tableau de char
strcat(textCostTowerDefenseOrange,valueCostTowerDefenseOrange);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefenseOrange=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefenseOrange,textFinDeTextCostTowerDefenseOrange);//Concatene les deux chaines de caracteres

char * textCostTowerDefensePurple=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle violette
char valueCostTowerDefensePurple[10];//Contiendra la valeur du cout d'une tourelle violette
sprintf(valueCostTowerDefensePurple, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefensePurple.txt"));//Stock la valeur du cout d'une tourelle violette dans un tableau de char
strcat(textCostTowerDefensePurple,valueCostTowerDefensePurple);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefensePurple=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefensePurple,textFinDeTextCostTowerDefensePurple);//Concatene les deux chaines de caracteres

char * textCostTowerDefenseRicochet=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle rouge
char valueCostTowerDefenseRicochet[10];//Contiendra la valeur du cout d'une tourelle rouge
sprintf(valueCostTowerDefenseRicochet, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseRicochet.txt"));//Stock la valeur du cout d'une tourelle rouge dans un tableau de char
strcat(textCostTowerDefenseRicochet,valueCostTowerDefenseRicochet);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefenseRicochet=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefenseRicochet,textFinDeTextCostTowerDefenseRicochet);//Concatene les deux chaines de caracteres

    //on parcourt le vecteur statique
    for(int i=0;i<12;i++){

        (stockStore[i]).draw();//on dessine le bloc correspondant (dependamment de son m_colorBlockID, il sera dessine dans une couleur specifique)

    }
LibMatrix::drawLargeText2D(textCorbeille,(stockStore[11]).getm_posx()+((stockStore[11]).getm_width()/2.0)-0.03,(stockStore[11]).getm_posy()+(stockStore[11]).getm_height()+0.01, 0, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer la corbeille.
LibMatrix::drawLargeText2D(textCostTowerDefenseYellow,(stockStore[10]).getm_posx()+((stockStore[10]).getm_width()/2.0)-0.03,(stockStore[10]).getm_posy()+(stockStore[10]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle jaune.
LibMatrix::drawLargeText2D(textCostTowerDefenseOrange,(stockStore[9]).getm_posx()+((stockStore[9]).getm_width()/2.0)-0.03,(stockStore[9]).getm_posy()+(stockStore[9]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle orange.
LibMatrix::drawLargeText2D(textCostTowerDefensePurple,(stockStore[8]).getm_posx()+((stockStore[8]).getm_width()/2.0)-0.03,(stockStore[8]).getm_posy()+(stockStore[8]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle violette.
LibMatrix::drawLargeText2D(textCostTowerDefenseRicochet,(stockStore[7]).getm_posx()+((stockStore[7]).getm_width()/2.0)-0.05,(stockStore[7]).getm_posy()+(stockStore[7]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle rouge.
}
