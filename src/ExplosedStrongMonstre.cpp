#include "ExplosedStrongMonstre.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/
//Les accesseurs de la Class StrongMonstre


/******IMPLEMENTATION DES MUTATEURS******/
//Les mutateurs de la Class StrongMonstre


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode getClass de la classe ExplosedStrongMonstre renvoie le nom de la Class (ici, le string "ExplosedStrongMonstre").

@param: null
*/
string ExplosedStrongMonstre::getClass() const{
    return "ExplosedStrongMonstre";
}

/*
@description:
La methode draw de la classe ExplosedStrongMonstre permet de dessiner des Monstres vert de maniere graphique.

@param: null
*/
void ExplosedStrongMonstre::draw() const{

    //Met les valeurs RGB dans la couleur verte
    float const r=1.0;
    float const g=0.1;
    float const b=0.9;
    float const alpha = 1.0;


    //Dessine les monstres
    GraphicPrimitives::drawFillTriangle2D(m_posx1, m_posy1, m_posx2, m_posy2, m_posx3, m_posy3, r, g, b, alpha);

}


/*
@description:
La methode drawExplosion de la classe ExplosedStrongMonstre permet de dessiner l'explosion des monstres de maniere graphique.

@param: null
*/
void ExplosedStrongMonstre::drawExplosion() const{

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
La methode watchdog de la classe ExplosedStrongMonstre etablie la procedure d'attaque des Monstres lorsque l'ExplosedStrongMonstre explose.

@param: La methode watchdog prend un parametre obligatoire: un pointeur sur un vecteur de pointeur de type Monstre.
-param1: Le pointeur sur un vecteur de pointeur de type Monstre qui contient la liste de tout les Monstres present sur la grille
*/
void ExplosedStrongMonstre::watchdog(vector <Monstre *> *MonstreList){
    float currentDistanceMonstreMonstre=0.0;
    vector<int> vectIndex;

        //Pour chaque Monstre present sur la grille
        for(int i=0;i<MonstreList->size();i++){
            //Mettre a jour la variable currentDistanceMonstreMonstre qui est la distance entre le centre du Monstre explosif et le centre du Monstre courant
            currentDistanceMonstreMonstre=LibMatrix::distanceBetweenPoint(this->monsterCenterx(),this->monsterCentery(),(*MonstreList)[i]->monsterCenterx(),(*MonstreList)[i]->monsterCentery());

            //Si la distance entre le centre du Monstre explosif est inferieur a m_portee*(distance entre le centre de deux blocks positionnes en diagonnal).
            if(currentDistanceMonstreMonstre<=(m_portee*sqrt(0.13*0.13+0.13*0.13))){
                vectIndex.push_back(i);//On retient l'index ou est situe le Monstre qui se trouve dans l'aire d'effet de l'explosion du Monstre explosif
            }
        }//Fin de la boucle for

        //Pour chaque Monstre present dans l'aire d'effet de l'explosion du Monstre explosif
        for(int i=0;i<vectIndex.size();i++){
                int const index=vectIndex[i];
                this->injuredWhenExplosed((*MonstreList)[index]);//Le Monstre explosif blesse les Monstres les plus proche d'eux
        }
}

/*
@description:
La methode injuredWhenExplosed de la classe ExplosedStrongMonstre prend un pointeur de Monstre en parametre et fait baisser la vie du monstre pointe par le pointeur.

@param: La methode injuredWhenExplosed prend un parametre obligatoire: un pointeur de Monstre.
-param1: un pointeur pointant sur le Monstre que le Monstre explosif blesse
*/
void ExplosedStrongMonstre::injuredWhenExplosed(Monstre* monstreEnnemi){
    monstreEnnemi->receiveDamage(m_damageExplosed);//Le monstre recoit des dommages
}

/*
@description:
La methode explosed de la classe ExplosedStrongMonstre effectue la procedure d'explosion de l'ExplosedStrongMonstre. Ainsi, si l'ExplosedStrongMonstre n'a plus de vie alors il explose en blessant les Monstres a proximite.

@param: La methode explosed prend un parametre obligatoire: un pointeur sur un vecteur de pointeur de type Monstre.
-param1: Le pointeur sur un vecteur de pointeur de type Monstre qui contient la liste de tout les Monstres present sur la grille
*/
void ExplosedStrongMonstre::explosed(vector <Monstre *> *MonstreList){
    //Si l'ExplosedFastMonstre n'a plus de vie
    if(m_vie <= 0){
        watchdog(MonstreList);//Il blesse tout les monstres dans l'aire de l'explosion
    }
}


/******METHODE DE CLASSE: OPERATEURS******/
ExplosedStrongMonstre& ExplosedStrongMonstre::operator=(ExplosedStrongMonstre const& monstreAcopier){
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
        m_portee= monstreAcopier.m_portee;
        m_damageExplosed= monstreAcopier.m_damageExplosed;

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

