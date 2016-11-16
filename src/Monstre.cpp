#include "Monstre.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/

/*
@description:
Accesseur de l'attribut m_monstreIA.

@param: null
*/
MonstreIA* Monstre::getm_monstreIA() const{
    return m_monstreIA;
}

/*
@description:
Accesseur de l'attribut m_vie.

@param: null
*/
int Monstre::getm_vie() const{
    return m_vie;
}

/*
@description:
Accesseur de l'attribut m_speed.

@param: null
*/
float Monstre::getm_speed() const{
    return m_speed;
}

/*
@description:
Accesseur de l'attribut m_timer.

@param: null
*/
int Monstre::getm_timer() const{
    return m_timer;
}

/*
@description:
Accesseur de l'attribut m_isArrive.

@param: null
*/
int Monstre::getm_isArrive() const{
    return m_isArrive;
}

/*
@description:
Accesseur de l'attribut m_damageAttack.

@param: null
*/
int Monstre::getm_damageAttack() const{
    return m_damageAttack;
}


/******IMPLEMENTATION DES MUTATEURS******/

/*
@description:
Mutateur de l'attribut m_posx1.

@param: La methode setm_posx1 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posx1
*/
void Monstre::setm_posx1 (float const& posx1){
 m_posx1=posx1;
}

/*
@description:
Mutateur de l'attribut m_posy1.

@param: La methode setm_posy1 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posy1
*/
void Monstre::setm_posy1 (float const& posy1){
 m_posy1=posy1;
}

/*
@description:
Mutateur de l'attribut m_posx2.

@param: La methode setm_posx2 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posx2
*/
void Monstre::setm_posx2 (float const& posx2){
 m_posx2=posx2;
}

/*
@description:
Mutateur de l'attribut m_posy2.

@param: La methode setm_posy2 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posy2
*/
void Monstre::setm_posy2 (float const& posy2){
 m_posy2=posy2;
}

/*
@description:
Mutateur de l'attribut m_posx3.

@param: La methode setm_posx3 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posx3
*/
void Monstre::setm_posx3 (float const& posx3){
 m_posx3=posx3;
}

/*
@description:
Mutateur de l'attribut m_posy3.

@param: La methode setm_posy3 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posy3
*/
void Monstre::setm_posy3 (float const& posy3){
 m_posy3=posy3;
}

/*
@description:
Mutateur de l'attribut m_vie.

@param: La methode setm_vie prend un parametre obligatoire: un int
-param1: le nouveau int pour m_vie
*/
void Monstre::setm_vie (int const& vie){
 m_vie=vie;
}

/*
@description:
Mutateur de l'attribut m_damageAttack.

@param: La methode setm_damageAttack prend un parametre obligatoire: un int
-param1: le nouveau int pour m_damageAttack
*/
void Monstre::setm_damageAttack (int const& damageAttack){
 m_damageAttack=damageAttack;
}


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode monsterCenterx de la classe Monstre renvoi l'abscisse du barycentre du Monstre.

@param: null
*/
float Monstre::monsterCenterx() const{
    float const centerx=(m_posx1+m_posx2+m_posx3)/3;
    return centerx;
}

/*
@description:
La methode monsterCentery de la classe Monstre renvoi l'ordonne du barycentre du Monstre.

@param: null
*/
float Monstre::monsterCentery() const{
    float const centery=(m_posy1+m_posy2+m_posy3)/3;
    return centery;
}

/*
@description:
La methode init de la classe Monstre permet d'initialiser l'IA d'un Monstre en IAOnePath, IASeveralPaths ou en IAClever.

@param: La methode init prend un parametre obligatoire: un string
-param1: Le string qui doit etre soit "IAOnePath", soit "IASeveralPaths", soit "IAClever" et qui permet de specifier quelle IA on souhaite donner au Monstre. Si le parametre ne prend pas les valeurs citees precedemment, l'IA est initialisee en IAOnePath par defaut.
*/
void Monstre::init(string nomIA){
    if(nomIA=="IAOnePath"){
            m_monstreIA = new IAOnePath();
    }
    else{
            if(nomIA=="IASeveralPaths"){
                m_monstreIA = new IASeveralPaths();
            }
            else{
               if(nomIA=="IAClever"){
                m_monstreIA = new IAClever();
                }
                else{
                    m_monstreIA = new IAOnePath();
                }
            }
    }
}

/*
@description:
La methode isEndPath renvoie 1 si le monstre est sur la derniere colonne de la grille et 0 sinon.

@param: null
*/
int Monstre::isEndPath() const{
    //Si le monstre se trouve sur la derniere colonne de grille
    if(((((*this).m_monstreIA)->getm_actualPosition()).getm_posxID()) == 11){
        return 1;//Renvoi 1
    }
    //Sinon
    else{
        return 0;//Renvoi 0
    }
}


/*
@description:
La methode searchInitPath de la classe Monstre permet de trouver l'entree du labyrinthe sur la grille.

@param: La methode searchInitPath prend un parametre obligatoire: une matrice de BlockGrille 12*12.
-param1: La matrice de BlockGrille 12*12 doit etre la grille de jeu.
*/
BlockGrille Monstre::searchInitPath(BlockGrille grilleDeJeu[12][12]) const{
  BlockGrille blockInitPath =  m_monstreIA->searchInitWay(grilleDeJeu);
  return blockInitPath;
}

/*
@description:
La methode searchPath de la classe Monstre permet au Monstre de trouver son chemin dans le labyrinthe sur la grille.

@param: La methode searchPath prend un parametre obligatoire: une matrice de BlockGrille 12*12.
-param1: La matrice de BlockGrille 12*12 doit etre la grille de jeu.
*/
 BlockGrille Monstre::searchPath(BlockGrille grilleDeJeu[12][12]) const{
    BlockGrille nextBlockPath = m_monstreIA->searchWay(grilleDeJeu);
    return nextBlockPath;
 }


/*
@description:
La methode moveSmoothly de la classe Monstre permet au Monstre de se deplacer d'un block a un autre de maniere continue.

@param: La methode moveSmoothly prend un parametre obligatoire: un BlockGrille.
-param1: Le BlockGrille doit etre le prochain block sur lequel le Monstre souhaite se deplacer. Typiquement, le block renvoye par la methode searchPath.
*/
void Monstre::moveSmoothly(BlockGrille nextBlock){

    float const blockWidth=nextBlock.getm_width();
    float const blockHeight=nextBlock.getm_height();

    //Si l'IA du Monstre a un attribut m_direction egal a "RIGHT"
    if(((this->getm_monstreIA())->getm_direction()) == "RIGHT"){
        m_posx1+=blockWidth/(m_speed);
        m_posx2+=blockWidth/(m_speed);
        m_posx3+=blockWidth/(m_speed);
    }
    //Sinon
    else{
        //Si l'IA du Monstre a un attribut m_direction egal a "DOWN"
        if(((this->getm_monstreIA())->getm_direction()) == "DOWN"){
            m_posy1-=blockHeight/(m_speed);
            m_posy2-=blockHeight/(m_speed);
            m_posy3-=blockHeight/(m_speed);
        }
    //Sinon
        else{
            //Si l'IA du Monstre a un attribut m_direction egal a "UP"
            if(((this->getm_monstreIA())->getm_direction()) == "UP"){
                m_posy1+=blockHeight/(m_speed);
                m_posy2+=blockHeight/(m_speed);
                m_posy3+=blockHeight/(m_speed);
            }
        //Sinon
            else{
                //Si l'IA du Monstre a un attribut m_direction egal a "LEFT"
                if(((this->getm_monstreIA())->getm_direction()) == "LEFT"){
                    m_posx1-=blockWidth/(m_speed);
                    m_posx2-=blockWidth/(m_speed);
                    m_posx3-=blockWidth/(m_speed);
                }
            }
        }
    }
}


/*
@description:
La methode receiveDamage de la classe Monstre prend un int en parametre et fait baisser la vie du Monstre d'une valeur egale a la valeur du int pris en parametre.

@param: La methode receiveDamage prend un parametre obligatoire: un int.
-param1: Le int doit representer la valeur du dommage subis par le Monstre.
*/
void Monstre::receiveDamage(int const& damage){
    m_vie-=damage;
}

/*
@description:
La methode slowDown de la classe Monstre prend un int en parametre et fait divise la vitesse du Monstre d'une valeur egale a la valeur du int pris en parametre.

@param: La methode slowDown prend un parametre obligatoire: un int.
-param1: Le int doit representer la valeur du ralentissement subis par le Monstre.
*/
void Monstre::slowDown(int const& rateSlowDown){
    m_speed*=rateSlowDown;
    m_timer*=rateSlowDown;
}


/******METHODE DE CLASSE: OPERATEURS******/
Monstre& Monstre::operator=(Monstre const& monstreAcopier){
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
        m_damageAttack= monstreAcopier.m_damageAttack;

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

