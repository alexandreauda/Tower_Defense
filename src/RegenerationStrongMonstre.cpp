#include "RegenerationStrongMonstre.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/
//Les accesseurs de la Class StrongMonstre


/******IMPLEMENTATION DES MUTATEURS******/
//Les mutateurs de la Class StrongMonstre


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode getClass de la classe RegenerationStrongMonstre renvoie le nom de la Class (ici, le string "RegenerationStrongMonstre").

@param: null
*/
string RegenerationStrongMonstre::getClass() const{
    return "RegenerationStrongMonstre";
}

/*
@description:
La methode draw de la classe RegenerationStrongMonstre permet de dessiner des Monstres vert de maniere graphique.

@param: null
*/
void RegenerationStrongMonstre::draw() const{

    //Met les valeurs RGB dans la couleur turquoise
    float const r=1.0;
    float const g=0.4;
    float const b=0.0;
    float const alpha = 1.0;


    //Dessine les monstres
    GraphicPrimitives::drawFillTriangle2D(m_posx1, m_posy1, m_posx2, m_posy2, m_posx3, m_posy3, r, g, b, alpha);

}

/*
@description:
La methode regeneration de la classe RegenerationStrongMonstre permet de regenerer la vie du Monstre d'une valeur egale a celle de l'attribut m_rateRegeneration.

@param: null
*/
void RegenerationStrongMonstre::regeneration(){
    int const vieAfterRegeneration=m_vie+m_rateRegeneration;
    int const vieMax=LibMatrix::loadIntInFileWithDirectory("InitialLifeRegenerationStrongMonstre","InitialLifeMonstre/");

    //Si m_timer%(int)m_speed == 0 (i.e: Le Monstre est sur le centre d'un block)
    if(m_timer%(int)m_speed == 0){
        //Si la vie apres regeneration ne depasse pas la vie initiale fixee a la creation du Monstre
        if(vieAfterRegeneration <= vieMax){
            m_vie=vieAfterRegeneration;//La vie du Monstre se regenere
        }
        //Sinon
        else{
            m_vie=vieMax;//On met la vie a son maximum
        }
    }
}


/******METHODE DE CLASSE: OPERATEURS******/
RegenerationStrongMonstre& RegenerationStrongMonstre::operator=(RegenerationStrongMonstre const& monstreAcopier){
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
        m_rateRegeneration= monstreAcopier.m_rateRegeneration;

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

