#include "ExplosedFastMonstre.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/
//Les accesseurs de la Class FastMonstre


/******IMPLEMENTATION DES MUTATEURS******/
//Les mutateurs de la Class FastMonstre


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode getClass de la classe ExplosedFastMonstre renvoie le nom de la Class (ici, le string "ExplosedFastMonstre").

@param: null
*/
string ExplosedFastMonstre::getClass() const{
    return "ExplosedFastMonstre";
}

/*
@description:
La methode draw de la classe ExplosedFastMonstre permet de dessiner des Monstres vert de maniere graphique.

@param: null
*/
void ExplosedFastMonstre::draw() const{

    //Met les valeurs RGB dans la couleur verte
    float const r=0.0;
    float const g=1.0;
    float const b=0.0;
    float const alpha = 1.0;


    //Dessine les monstres
    GraphicPrimitives::drawFillTriangle2D(m_posx1, m_posy1, m_posx2, m_posy2, m_posx3, m_posy3, r, g, b, alpha);

}


/*
@description:
La methode drawExplosion de la classe ExplosedFastMonstre permet de dessiner l'explosion des monstres de maniere graphique.

@param: null
*/
//TODO
void ExplosedFastMonstre::drawExplosion() const{

     //Met les valeurs RGB dans la couleur blanche
    float const r=1.0;
    float const g=1.0;
    float const b=1.0;
    float const alpha = 1.0;

//Trace l'explosion
 GraphicPrimitives:: drawLine2D(this->monsterCenterx(), this->monsterCentery(), this->monsterCenterx(), this->monsterCentery()+m_portee*0.13, r, g, b, alpha);//Trace un trait partant du centre du monstre et allant vers le nord.
 GraphicPrimitives:: drawLine2D(this->monsterCenterx(), this->monsterCentery(), this->monsterCenterx(), this->monsterCentery()-m_portee*0.13, r, g, b, alpha);//Trace un trait partant du centre du monstre et allant vers le sud.
 GraphicPrimitives:: drawLine2D(this->monsterCenterx(), this->monsterCentery(), this->monsterCenterx()+m_portee*0.13, this->monsterCentery(), r, g, b, alpha);//Trace un trait partant du centre du monstre et allant vers l'ouest.
 GraphicPrimitives:: drawLine2D(this->monsterCenterx(), this->monsterCentery(), this->monsterCenterx()-m_portee*0.13, this->monsterCentery(), r, g, b, alpha);//Trace un trait partant du centre du monstre et allant vers l'est.
 GraphicPrimitives:: drawLine2D(this->monsterCenterx(), this->monsterCentery(), this->monsterCenterx()+m_portee*0.13*sqrt(2)/2, this->monsterCentery()+m_portee*0.13*sqrt(2)/2, r, g, b, alpha);//Trace un trait partant du centre du monstre et allant vers le nord-est.
 GraphicPrimitives:: drawLine2D(this->monsterCenterx(), this->monsterCentery(), this->monsterCenterx()+m_portee*0.13*sqrt(2)/2, this->monsterCentery()-m_portee*0.13*sqrt(2)/2, r, g, b, alpha);//Trace un trait partant du centre du monstre et allant vers le sud-est.
 GraphicPrimitives:: drawLine2D(this->monsterCenterx(), this->monsterCentery(), this->monsterCenterx()-m_portee*0.13*sqrt(2)/2, this->monsterCentery()+m_portee*0.13*sqrt(2)/2, r, g, b, alpha);//Trace un trait partant du centre du monstre et allant vers le nord-ouest.
 GraphicPrimitives:: drawLine2D(this->monsterCenterx(), this->monsterCentery(), this->monsterCenterx()-m_portee*0.13*sqrt(2)/2, this->monsterCentery()-m_portee*0.13*sqrt(2)/2, r, g, b, alpha);//Trace un trait partant du centre du monstre et allant vers le sud-ouest.

}

/*
@description:
La methode watchdog de la classe ExplosedFastMonstre etablie la procedure d'attaque des tourelles.

@param: La methode watchdog prend un parametre obligatoire: un pointeur sur un vecteur de pointeur de type Monstre.
-param1: Le pointeur sur un vecteur de pointeur de type Monstre qui contient la liste de tout les Monstres present sur la grille
*/
/*void ExplosedFastMonstre::watchdog(vector <Monstre *> *MonstreList){
    float distanceMonstreMonstre=10.0;
    float currentDistanceTowerMonstre=0.0;
    int index=0;

    //Si il n'y a pas de Monstre sur la grille
    if(MonstreList->size() == 0){
        m_targetx=m_centerTowerx;//On place le target sur le centre de la tourelle
        m_targety=m_centerTowery;//On place le target sur le centre de la tourelle
    }
    //Sinon
    else{
        //Pour chaque Monstre present sur la grille
        for(int i=0;i<MonstreList->size();i++){
            //Mettre a jour la variable currentDistanceTowerMonstre qui est la distance entre le centre de la tourelle et le centre du Monstre courant
            currentDistanceTowerMonstre=LibMatrix::distanceBetweenPoint(m_centerTowerx,m_centerTowery,(*MonstreList)[i]->monsterCenterx(),(*MonstreList)[i]->monsterCentery());

            //Si la distance entre le centre de la tourelle et le Monstre courant est inferieur strictement avec la plus petite distance entre le centre de la tourelle et un Monstre touvee jusqu'a present, et que cette distance est inferieur a m_portee*(distance entre le centre de deux blocks positionnes en diagonnal).
            if((currentDistanceTowerMonstre<distanceTowerMonstre) && (currentDistanceTowerMonstre<=(m_portee*sqrt(m_blockBase.getm_width()*m_blockBase.getm_width()+m_blockBase.getm_height()*m_blockBase.getm_height())))){
                distanceTowerMonstre=currentDistanceTowerMonstre;
                index=i;//On retient l'index ou est situe le Monstre le plus proche de la tourelle
            }
        }//Fin de la boucle for
        //Si m_timer modulo m_cadence est egale a 0 et que la distance entre la tourelle et le monstre est inferieur a m_portee*(distance entre le centre de deux blocks positionnes en diagonnal) -> Formule donnee par l'application du theoreme de Pythagore en fonction de la largeur et de la hauteur des blocks.
        if(m_timer%m_cadence == 0 && currentDistanceTowerMonstre<=(m_portee*sqrt(m_blockBase.getm_width()*m_blockBase.getm_width()+m_blockBase.getm_height()*m_blockBase.getm_height()))){
            if(this->getClass() != "TowerDefensePurple"){
                m_targetx=(*MonstreList)[index]->monsterCenterx();//On met a jour le target de la tourelle qui se place au centre du Monstre
                m_targety=(*MonstreList)[index]->monsterCentery();//On met a jour le target de la tourelle qui se place au centre du Monstre
                this->attaque((*MonstreList)[index]);//La tourelle attaque le Monstre le plus proche d'elle
                m_timer++;//On incremente le compteur
            }
            //Si la tourelle est une tourelle violette
            else{
                //Si le Monstre est au centre d'un block
                if((*MonstreList)[index]->getm_timer()%(int)(*MonstreList)[index]->getm_speed() == 0){
                    m_targetx=(*MonstreList)[index]->monsterCenterx();//On met a jour le target de la tourelle qui se place au centre du Monstre
                    m_targety=(*MonstreList)[index]->monsterCentery();//On met a jour le target de la tourelle qui se place au centre du Monstre
                    this->attaque((*MonstreList)[index]);//La tourelle attaque le Monstre le plus proche d'elle et ralenti donc le Monstre
                    m_timer++;//On incremente le compteur
                }
                //Si le Monstre n'est pas au centre d'un block
                else{
                    //on trace un trait (c'est plus visuelle ainsi) mais on n'attaque pas!
                    m_targetx=(*MonstreList)[index]->monsterCenterx();//On met a jour le target de la tourelle qui se place au centre du Monstre
                    m_targety=(*MonstreList)[index]->monsterCentery();//On met a jour le target de la tourelle qui se place au centre du Monstre
                }
            }
        }
        //Sinon
        else{
            m_targetx=m_centerTowerx;//On place le target sur le centre de la tourelle
            m_targety=m_centerTowery;//On place le target sur le centre de la tourelle
            m_timer++;//On incremente le compteur
        }
    }
}*/

/******METHODE DE CLASSE: OPERATEURS******/
ExplosedFastMonstre& ExplosedFastMonstre::operator=(ExplosedFastMonstre const& monstreAcopier){
    if(this != &monstreAcopier){//on vérifie que l'objet n'est pas le même que l'objetAcopier reçu en argument
        //on copie tous les attributs qui ne sont pas des objets membres
        m_posx1= monstreAcopier.m_posx1;
        m_posy1= monstreAcopier.m_posy1;
        m_posx2= monstreAcopier.m_posx2;
        m_posy2= monstreAcopier.m_posy2;
        m_posx3= monstreAcopier.m_posx3;
        m_posy3= monstreAcopier.m_posy3;
        m_vie= monstreAcopier.m_vie;
        m_speed= monstreAcopier.m_speed;
        m_timer= monstreAcopier.m_timer;
        m_isArrive= monstreAcopier.m_isArrive;

        //traitements des pointeurs objets membres
        delete m_monstreIA;//on detruit l'objet membre pour ensuite le recree avec l'objet membre de l'objet copie

        if((monstreAcopier.m_monstreIA)->getClass() == "IAOnePath"){//si l'IA du monstre a copier est une IA IAOnePath
          m_monstreIA= new IAOnePath(); //on initialise l'IA du monstre avec l'IA IAOnePath puisque c'est celle du monstreAcopier
        }
        else if((monstreAcopier.m_monstreIA)->getClass() == "IASeveralPaths"){//si l'IA du monstre a copier est une IA IASeveralPaths
             m_monstreIA= new IASeveralPaths(); //on initialise l'IA du monstre avec l'IA IASeveralPaths puisque c'est celle du monstreAcopier
        }
        else if((monstreAcopier.m_monstreIA)->getClass() == "IAClever"){//si l'IA du monstre a copier est une IA IAClever
             m_monstreIA= new IAClever(); //on initialise l'IA du monstre avec l'IA IAClever puisque c'est celle du monstreAcopier
        }
        else{
            m_monstreIA= new IAClever(); //par defaut, on initialise l'IA du monstre avec l'IA IAClever si l'IA du monstreAcopier n'est pas lisible
        }

    }
    return *this;
}

