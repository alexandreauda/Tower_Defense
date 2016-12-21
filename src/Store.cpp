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

@param: La methode loadStore prend un parametre obligatoire: un vecteur statique de type BlockStore et de dimension 13.
-param1: un vecteur statique de type BlockStore et de dimension 12 qui va etre modifie pour etre initialise avec des blocks de carasteristiques differentes.
*/
void Store::loadStore(BlockStore stockStore[13]) const {

for(int i=0;i<13;i++){

				stockStore[i]= BlockStore(-i*m_shopCellWidth-0.004*i+0.75, -0.85, m_shopCellWidth, m_shopCellHeight);//on initialise le tableau stockStore[] avec des blocs

                (stockStore[i]).setm_posID(12-i);//on numerote les blocks au fur et a mesure

                (stockStore[i]).setm_colorBlockID(2);//on set l'ID

			}
}


/*
@description:
La methode draw de la classe Store permet de dessiner l'inventaire de maniere graphique.

@param: null
*/
void Store::draw() const {

BlockStore stockStore[13];//on definit un tableau vide de longueur 13 de type BlockStore
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

char * textCostTowerDefenseYellowLongShot=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle TowerDefenseYellowLongShot
char valueCostTowerDefenseYellowLongShot[10];//Contiendra la valeur du cout d'une tourelle TowerDefenseYellowLongShot
sprintf(valueCostTowerDefenseYellowLongShot, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseYellowLongShot.txt"));//Stock la valeur du cout d'une tourelle TowerDefenseYellowLongShot dans un tableau de char
strcat(textCostTowerDefenseYellowLongShot,valueCostTowerDefenseYellowLongShot);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefenseYellowLongShot=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefenseYellowLongShot,textFinDeTextCostTowerDefenseYellowLongShot);//Concatene les deux chaines de caracteres

char * textCostTowerDefenseOrangeLongShot=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle TowerDefenseOrangeLongShot
char valueCostTowerDefenseOrangeLongShot[10];//Contiendra la valeur du cout d'une tourelle TowerDefenseOrangeLongShot
sprintf(valueCostTowerDefenseOrangeLongShot, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseOrangeLongShot.txt"));//Stock la valeur du cout d'une tourelle TowerDefenseOrangeLongShot dans un tableau de char
strcat(textCostTowerDefenseOrangeLongShot,valueCostTowerDefenseOrangeLongShot);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefenseOrangeLongShot=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefenseOrangeLongShot,textFinDeTextCostTowerDefenseOrangeLongShot);//Concatene les deux chaines de caracteres

char * textCostTowerDefensePurpleLongShot=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle TowerDefensePurpleLongShot
char valueCostTowerDefensePurpleLongShot[10];//Contiendra la valeur du cout d'une tourelle TowerDefensePurpleLongShot
sprintf(valueCostTowerDefensePurpleLongShot, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefensePurpleLongShot.txt"));//Stock la valeur du cout d'une tourelle TowerDefensePurpleLongShot dans un tableau de char
strcat(textCostTowerDefensePurpleLongShot,valueCostTowerDefensePurpleLongShot);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefensePurpleLongShot=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefensePurpleLongShot,textFinDeTextCostTowerDefensePurpleLongShot);//Concatene les deux chaines de caracteres

char * textCostTowerDefenseRicochetMediumLevel=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle TowerDefenseRicochetMediumLevel
char valueCostTowerDefenseRicochetMediumLevel[10];//Contiendra la valeur du cout d'une tourelle TowerDefenseRicochetMediumLevel
sprintf(valueCostTowerDefenseRicochetMediumLevel, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseRicochetMediumLevel.txt"));//Stock la valeur du cout d'une tourelle TowerDefenseRicochetMediumLevel dans un tableau de char
strcat(textCostTowerDefenseRicochetMediumLevel,valueCostTowerDefenseRicochetMediumLevel);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefenseRicochetMediumLevel=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefenseRicochetMediumLevel,textFinDeTextCostTowerDefenseRicochetMediumLevel);//Concatene les deux chaines de caracteres

char * textCostTowerDefenseYellowSniper=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle TowerDefenseYellowSniper
char valueCostTowerDefenseYellowSniper[10];//Contiendra la valeur du cout d'une tourelle TowerDefenseYellowSniper
sprintf(valueCostTowerDefenseYellowSniper, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseYellowSniper.txt"));//Stock la valeur du cout d'une tourelle TowerDefenseYellowSniper dans un tableau de char
strcat(textCostTowerDefenseYellowSniper,valueCostTowerDefenseYellowSniper);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefenseYellowSniper=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefenseYellowSniper,textFinDeTextCostTowerDefenseYellowSniper);//Concatene les deux chaines de caracteres

char * textCostTowerDefenseOrangeSniper=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle TowerDefenseOrangeSniper
char valueCostTowerDefenseOrangeSniper[10];//Contiendra la valeur du cout d'une tourelle TowerDefenseOrangeSniper
sprintf(valueCostTowerDefenseOrangeSniper, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseOrangeSniper.txt"));//Stock la valeur du cout d'une tourelle TowerDefenseOrangeSniper dans un tableau de char
strcat(textCostTowerDefenseOrangeSniper,valueCostTowerDefenseOrangeSniper);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefenseOrangeSniper=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefenseOrangeSniper,textFinDeTextCostTowerDefenseOrangeSniper);//Concatene les deux chaines de caracteres

char * textCostTowerDefensePurpleSniper=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle TowerDefensePurpleSniper
char valueCostTowerDefensePurpleSniper[10];//Contiendra la valeur du cout d'une tourelle TowerDefensePurpleSniper
sprintf(valueCostTowerDefensePurpleSniper, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefensePurpleSniper.txt"));//Stock la valeur du cout d'une tourelle TowerDefensePurpleSniper dans un tableau de char
strcat(textCostTowerDefensePurpleSniper,valueCostTowerDefensePurpleSniper);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefensePurpleSniper=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefensePurpleSniper,textFinDeTextCostTowerDefensePurpleSniper);//Concatene les deux chaines de caracteres

char * textCostTowerDefenseRicochetHighLevel=new char[3]{' ','\0'};//Contient le texte pour indiquer le cout d'une tourelle TowerDefenseRicochetHighLevel
char valueCostTowerDefenseRicochetHighLevel[10];//Contiendra la valeur du cout d'une tourelle TowerDefenseRicochetHighLevel
sprintf(valueCostTowerDefenseRicochetHighLevel, "%d", LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseRicochetHighLevel.txt"));//Stock la valeur du cout d'une tourelle TowerDefenseRicochetHighLevel dans un tableau de char
strcat(textCostTowerDefenseRicochetHighLevel,valueCostTowerDefenseRicochetHighLevel);//Concatene les deux chaines de caracteres
char * textFinDeTextCostTowerDefenseRicochetHighLevel=new char[1]{'\0'};//Contient un caractere de fin de texte
strcat(textCostTowerDefenseRicochetHighLevel,textFinDeTextCostTowerDefenseRicochetHighLevel);//Concatene les deux chaines de caracteres

    //on parcourt le vecteur statique
    for(int i=0;i<13;i++){

        (stockStore[i]).draw();//on dessine le bloc correspondant (dependamment de son m_colorBlockID, il sera dessine dans une couleur specifique)

    }
LibMatrix::drawLargeText2D(textCorbeille,(stockStore[12]).getm_posx()+((stockStore[12]).getm_width()/2.0)-0.03,(stockStore[12]).getm_posy()+(stockStore[12]).getm_height()+0.01, 0, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer la corbeille.
LibMatrix::drawLargeText2D(textCostTowerDefenseYellow,(stockStore[11]).getm_posx()+((stockStore[11]).getm_width()/2.0)-0.03,(stockStore[11]).getm_posy()+(stockStore[11]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle jaune.
LibMatrix::drawLargeText2D(textCostTowerDefenseOrange,(stockStore[10]).getm_posx()+((stockStore[10]).getm_width()/2.0)-0.03,(stockStore[10]).getm_posy()+(stockStore[10]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle orange.
LibMatrix::drawLargeText2D(textCostTowerDefensePurple,(stockStore[9]).getm_posx()+((stockStore[9]).getm_width()/2.0)-0.03,(stockStore[9]).getm_posy()+(stockStore[9]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle violette.
LibMatrix::drawLargeText2D(textCostTowerDefenseRicochet,(stockStore[8]).getm_posx()+((stockStore[8]).getm_width()/2.0)-0.05,(stockStore[8]).getm_posy()+(stockStore[8]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle rouge.
LibMatrix::drawLargeText2D(textCostTowerDefenseYellowLongShot,(stockStore[7]).getm_posx()+((stockStore[7]).getm_width()/2.0)-0.05,(stockStore[7]).getm_posy()+(stockStore[7]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle TowerDefenseYellowLongShot.
LibMatrix::drawLargeText2D(textCostTowerDefenseOrangeLongShot,(stockStore[6]).getm_posx()+((stockStore[6]).getm_width()/2.0)-0.05,(stockStore[6]).getm_posy()+(stockStore[6]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle TowerDefenseOrangeLongShot.
LibMatrix::drawLargeText2D(textCostTowerDefensePurpleLongShot,(stockStore[5]).getm_posx()+((stockStore[5]).getm_width()/2.0)-0.05,(stockStore[5]).getm_posy()+(stockStore[5]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle TowerDefensePurpleLongShot.
LibMatrix::drawLargeText2D(textCostTowerDefenseRicochetMediumLevel,(stockStore[4]).getm_posx()+((stockStore[4]).getm_width()/2.0)-0.05,(stockStore[4]).getm_posy()+(stockStore[4]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle TowerDefenseRicochetMediumLevel.
LibMatrix::drawLargeText2D(textCostTowerDefenseYellowSniper,(stockStore[3]).getm_posx()+((stockStore[3]).getm_width()/2.0)-0.05,(stockStore[3]).getm_posy()+(stockStore[3]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle TowerDefenseYellowSniper.
LibMatrix::drawLargeText2D(textCostTowerDefenseOrangeSniper,(stockStore[2]).getm_posx()+((stockStore[2]).getm_width()/2.0)-0.05,(stockStore[2]).getm_posy()+(stockStore[2]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle TowerDefenseOrangeSniper.
LibMatrix::drawLargeText2D(textCostTowerDefensePurpleSniper,(stockStore[1]).getm_posx()+((stockStore[1]).getm_width()/2.0)-0.05,(stockStore[1]).getm_posy()+(stockStore[1]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle TowerDefensePurpleSniper.
LibMatrix::drawLargeText2D(textCostTowerDefenseRicochetHighLevel,(stockStore[0]).getm_posx()+((stockStore[0]).getm_width()/2.0)-0.05,(stockStore[0]).getm_posy()+(stockStore[0]).getm_height()+0.01, 1, 1.0, 1.0, 1.0, 1.0);//Draw le texte pour indiquer le cout d'une tourelle TowerDefenseRicochetHighLevel.
}
