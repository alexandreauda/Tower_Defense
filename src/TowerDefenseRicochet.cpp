#include "TowerDefenseRicochet.h"

using namespace std;


/******IMPLEMENTATION DES ACCESSEURS******/

/*
@description:
Accesseur de l'attribut m_nbRicochet.

@param: null
*/
int TowerDefenseRicochet::getm_nbRicochet() const{
    return m_nbRicochet;
}

/*
@description:
Accesseur de l'attribut m_attackDamage.

@param: null
*/
int TowerDefenseRicochet::getm_attackDamage() const{
    return m_attackDamage;
}


/******IMPLEMENTATION DES MUTATEURS******/
//null



/******IMPLEMENTATION DES METHODES******/

/*
@description:
Renvoie un string avec le nom de la classe actuelle (à savoir ici: "TowerDefenseRicochet")

@param: null
*/
string TowerDefenseRicochet::getClass() const {
    return "TowerDefenseRicochet";
}

/*
@description:
La methode draw de la classe TowerDefenseRicochet permet de dessiner des tourelles rouges de maniere graphique dans le m_blockBase.

@param: null
*/
void TowerDefenseRicochet::draw() const{

    //Met les valeurs RGB dans la couleur rouge
    float const r=1.0;
    float const g=0.0;
    float const b=0.0;
    float const alpha = 1.0;

    //Recupere les attributs du block pris en parametre
    float const posx = m_blockBase.getm_posx();
    float const posy = m_blockBase.getm_posy();
    float const width = m_blockBase.getm_width();
    float const height = m_blockBase.getm_height();

    //Dessine la tourelle dans le block pris en parametre
    GraphicPrimitives::drawFillRect2D(posx+width/6, posy+height/6, width*2/3, height*2/3, r, g, b, alpha);

}

/*
@description:
La methode drawTir de la classe TowerDefenseRicochet permet de dessiner les tirs des tourelles rouges de maniere graphique.

@param: null
*/
void TowerDefenseRicochet::drawTir() const{

    //Met les valeurs RGB dans la couleur blanche
    float const r=1.0;
    float const g=1.0;
    float const b=1.0;
    float const alpha = 1.0;

 GraphicPrimitives::drawLine2D(m_centerTowerx, m_centerTowery, m_targetx, m_targety, r, g, b, alpha);
}

/*
@description:
La methode drawTirRicochet de la classe TowerDefenseRicochet permet de dessiner les ricochets des tirs des tourelles rouges de maniere graphique.

@param: null
*/
void TowerDefenseRicochet::drawTirRicochet(vector <Monstre *> *MonstreList) const{

    //Met les valeurs RGB dans la couleur blanche
    float const r=1.0;
    float const g=1.0;
    float const b=1.0;
    float const alpha = 1.0;

    float distanceTowerMonstre=10.0;
    float currentDistanceTowerMonstre=0.0;
    int index=0;

    //Si il y a des Monstres sur la grille
    if(MonstreList->size() != 0){

            vector<float> vectProximity;
            vector<float> sortVectProximity;

            //Pour chaque Monstre present sur la grille
            for(int i=0;i<MonstreList->size();i++){
                //Mettre a jour la variable currentDistanceTowerMonstre qui est la distance entre le centre de la tourelle et le centre du Monstre courant
                currentDistanceTowerMonstre=LibMatrix::distanceBetweenPoint(m_centerTowerx,m_centerTowery,(*MonstreList)[i]->monsterCenterx(),(*MonstreList)[i]->monsterCentery());

                //Si la distance entre le centre de la tourelle et le Monstre courant est inferieur strictement avec la plus petite distance entre le centre de la tourelle et un Monstre touvee jusqu'a present, et que cette distance est inferieur a m_portee*(distance entre le centre de deux blocks positionnes en diagonnal).
                if(currentDistanceTowerMonstre<=(m_portee*sqrt(m_blockBase.getm_width()*m_blockBase.getm_width()+m_blockBase.getm_height()*m_blockBase.getm_height()))){
                    vectProximity.push_back(currentDistanceTowerMonstre);//On retient la distance entre la tourelle et le Monstre courant
                    vectProximity.push_back(i);//On retient l'index du Monstre courant
                }//Fin du if
            }//Fin de la boucle for
            int j=0;
            float currentPlusProche=10.0;
            int indexPlusProche;

            //on veut un vecteur sortVectProximity qui est les distances des monstres les plus proches au début du vecteur avec leur index associe.
            while(sortVectProximity.size() < vectProximity.size()){
                while(j < vectProximity.size()){
                    if((vectProximity[j] <= currentPlusProche) && (LibMatrix::isContained(sortVectProximity, vectProximity[j]) == 0)){
                        currentPlusProche=vectProximity[j];
                        indexPlusProche=j;
                    }
                j+=2;
                }
            sortVectProximity.push_back(currentPlusProche);
            sortVectProximity.push_back(indexPlusProche);
            j=0;
            currentPlusProche=10.0;
            }

            int const nbRicochet=m_nbRicochet;
            int nbTouch;
            //Si le nombre de ricochets est inferieur au nombre de Monstre a proximite
            if(nbRicochet < (sortVectProximity.size()/2)){
                nbTouch=nbRicochet;
            }
            //Si le nombre de ricochet est superieur ou egal au nombre de Monstre a proximite
            else{
                nbTouch=(sortVectProximity.size()/2);
            }

            //Si m_timer modulo m_cadence est egale a 0
            if(m_timer%m_cadence == 0 && sortVectProximity.size() >= 4){
                for(int k=1;k<=nbTouch;k++){
                    GraphicPrimitives::drawLine2D((*MonstreList)[sortVectProximity[k]/2]->monsterCenterx(), (*MonstreList)[sortVectProximity[k]/2]->monsterCentery(), (*MonstreList)[sortVectProximity[k+2]/2]->monsterCenterx(), (*MonstreList)[sortVectProximity[k+2]/2]->monsterCentery(), r, g, b, alpha);
                }
            }
    }
}


/*
@description:
La methode attaque de la classe TowerDefenseRicochet prend un pointeur de Monstre en parametre et fait baisser la vie du monstre pointe par le pointeur.

@param: La methode attaque prend un parametre obligatoire: un pointeur de Monstre.
-param1: un pointeur pointant sur le Monstre que la tourelle attaque
*/
void TowerDefenseRicochet::attaque(Monstre* monstreEnnemi){
monstreEnnemi->receiveDamage(m_attackDamage);//Le monstre recoit des dommages
}

/*
@description:
La methode attaque de la classe TowerDefenseRicochet prend un pointeur de Monstre en parametre et fait baisser la vie du monstre pointe par le pointeur.

@param: La methode attaque prend un parametre obligatoire: un pointeur de Monstre.
-param1: un pointeur pointant sur le Monstre que la tourelle attaque
*/
void TowerDefenseRicochet::attaquer(Monstre* monstreEnnemi, int const& g){
monstreEnnemi->receiveDamage(m_attackDamage/LibMatrix::puissance(2,g));//Le monstre recoit des dommages
}

/*
@description:
La methode watchdog de la classe TowerDefenseRicochet etablie la procedure d'attaque des tourelles.

@param: La methode watchdog prend un parametre obligatoire: un pointeur sur un vecteur de pointeur de type Monstre.
-param1: Le pointeur sur un vecteur de pointeur de type Monstre qui contient la liste de tout les Monstres present sur la grille
*/
void TowerDefenseRicochet::watchdog(vector <Monstre *> *MonstreList){
    float distanceTowerMonstre=10.0;
    float currentDistanceTowerMonstre=0.0;
    int index=0;

    //Si il n'y a pas de Monstre sur la grille
    if(MonstreList->size() == 0){
        m_targetx=m_centerTowerx;//On place le target sur le centre de la tourelle
        m_targety=m_centerTowery;//On place le target sur le centre de la tourelle
    }
    //Sinon si il y a des Monstres sur la grille
    else{

            vector<float> vectProximity;
            vector<float> sortVectProximity;

            //Pour chaque Monstre present sur la grille
            for(int i=0;i<MonstreList->size();i++){
                //Mettre a jour la variable currentDistanceTowerMonstre qui est la distance entre le centre de la tourelle et le centre du Monstre courant
                currentDistanceTowerMonstre=LibMatrix::distanceBetweenPoint(m_centerTowerx,m_centerTowery,(*MonstreList)[i]->monsterCenterx(),(*MonstreList)[i]->monsterCentery());

                //Si la distance entre le centre de la tourelle et le Monstre courant est inferieur strictement avec la plus petite distance entre le centre de la tourelle et un Monstre touvee jusqu'a present, et que cette distance est inferieur a m_portee*(distance entre le centre de deux blocks positionnes en diagonnal).
                if(currentDistanceTowerMonstre<=(m_portee*sqrt(m_blockBase.getm_width()*m_blockBase.getm_width()+m_blockBase.getm_height()*m_blockBase.getm_height()))){
                    vectProximity.push_back(currentDistanceTowerMonstre);//On retient la distance entre la tourelle et le Monstre courant
                    vectProximity.push_back(i);//On retient l'index du Monstre courant
                }//Fin du if
            }//Fin de la boucle for
            int j=0;
            float currentPlusProche=10.0;
            int indexPlusProche;

            //on veut un vecteur sortVectProximity qui est les distances des monstres les plus proches au début du vecteur avec leur index associe.
            while(sortVectProximity.size() < vectProximity.size()){
                while(j < vectProximity.size()){
                    if((vectProximity[j] <= currentPlusProche) && (LibMatrix::isContained(sortVectProximity, vectProximity[j]) == 0)){
                        currentPlusProche=vectProximity[j];
                        indexPlusProche=j;
                    }
                j+=2;
                }
            sortVectProximity.push_back(currentPlusProche);
            sortVectProximity.push_back(indexPlusProche);
            j=0;
            currentPlusProche=10.0;
            }

            int g=0;
            int const nbRicochet=m_nbRicochet;
            int nbTouch;
            //Si le nombre de ricochets est inferieur au nombre de Monstre a proximite
            if(nbRicochet < (sortVectProximity.size()/2)){
                nbTouch=nbRicochet;
            }
            //Si le nombre de ricochet est superieur ou egal au nombre de Monstre a proximite
            else{
                nbTouch=(sortVectProximity.size()/2);
            }

            //Si m_timer modulo m_cadence est egale a 0
            if(m_timer%m_cadence == 0 && sortVectProximity.size() != 0){
                m_targetx=(*MonstreList)[sortVectProximity[1]/2]->monsterCenterx();//On met a jour le target de la tourelle qui se place au centre du Monstre le plus proche
                m_targety=(*MonstreList)[sortVectProximity[1]/2]->monsterCentery();//On met a jour le target de la tourelle qui se place au centre du Monstre le plus proche
                for(int k=1;k<=nbTouch;k++){
                    this->attaquer((*MonstreList)[sortVectProximity[k]/2],g);
                    g++; //On incremente le g
                }
                m_timer++;//On incremente le compteur
            }
            //Sinon
            else{
                m_targetx=m_centerTowerx;//On place le target sur le centre de la tourelle
                m_targety=m_centerTowery;//On place le target sur le centre de la tourelle
                m_timer++;//On incremente le compteur
            }
    }

}
