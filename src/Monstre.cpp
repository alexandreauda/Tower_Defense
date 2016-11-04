#include "Monstre.h"

using namespace std;


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode draw de la classe Monstre permet de dessiner des Monstres bleus de maniere graphique.

@param: null
*/
void Monstre::draw() const{

    //Met les valeurs RGB dans la couleur bleue
    float const r=0.0;
    float const g=0.0;
    float const b=1.0;
    float const alpha = 1.0;


    //Dessine les monstres
    GraphicPrimitives::drawFillTriangle2D(m_posx1, m_posy1, m_posx2, m_posy2, m_posx3, m_posy3, r, g, b, alpha);

}


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

BlockGrille Monstre::searchInitPath(BlockGrille grilleDeJeu[12][12]) const{
  BlockGrille blockInitPath =  m_monstreIA->searchInitWay(grilleDeJeu);
  return blockInitPath;
}

 BlockGrille Monstre::searchPath(BlockGrille grilleDeJeu[12][12]) const{
    BlockGrille nextBlockPath = m_monstreIA->searchWay(grilleDeJeu);
    return nextBlockPath;
 }

void Monstre::moveSmoothly(BlockGrille nextBlock){

    float const blockWidth=nextBlock.getm_width();
    float const blockHeight=nextBlock.getm_height();

    if(((this->getm_monstreIA())->getm_direction()) == "RIGHT"){
        m_posx1+=blockWidth/(m_speed);
        m_posx2+=blockWidth/(m_speed);
        m_posx3+=blockWidth/(m_speed);
    }
    else{
        if(((this->getm_monstreIA())->getm_direction()) == "DOWN"){
            m_posy1-=blockHeight/(m_speed);
            m_posy2-=blockHeight/(m_speed);
            m_posy3-=blockHeight/(m_speed);
        }
        else{
            if(((this->getm_monstreIA())->getm_direction()) == "UP"){
                m_posy1+=blockHeight/(m_speed);
                m_posy2+=blockHeight/(m_speed);
                m_posy3+=blockHeight/(m_speed);
            }
            else{
                if(((this->getm_monstreIA())->getm_direction()) == "LEFT"){
                    m_posx1-=blockWidth/(m_speed);
                    m_posx2-=blockWidth/(m_speed);
                    m_posx3-=blockWidth/(m_speed);
                }
            }
        }
    }

}

void Monstre::walk(){
    //TEST
    BlockGrille grilleDeJeu[12][12];
    Grille grilleInit;
    grilleInit.loadGrille("Files_Levels/Level_1.txt",grilleDeJeu);//Load la matrice m_grilleDeJeu
    //FIN TEST

    BlockGrille nextBlock;

    if(m_timer%(int)m_speed == 0){
        if(this->isEndPath() == 1){
           m_isArrive=1;
        }
        else{
            nextBlock=this->searchPath(grilleDeJeu);
            (this->getm_monstreIA())->setm_previousPosition((this->getm_monstreIA())->getm_actualPosition());
            (this->getm_monstreIA())->setm_actualPosition(nextBlock);
            this->moveSmoothly(nextBlock);
            m_timer++;
        }
    }
    else{
        this->moveSmoothly(nextBlock);
        m_timer++;
    }
}

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
Accesseur de l'attribut m_speed.

@param: null
*/
float Monstre::getm_speed() const{
    return m_speed;
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
Mutateur de l'attribut m_posx1.

@param: La methode setm_posx1 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posx1
*/
void Monstre::setm_posx1 (float posx1){
 m_posx1=posx1;
}

/*
@description:
Mutateur de l'attribut m_posy1.

@param: La methode setm_posy1 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posy1
*/
void Monstre::setm_posy1 (float posy1){
 m_posy1=posy1;
}

/*
@description:
Mutateur de l'attribut m_posx2.

@param: La methode setm_posx2 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posx2
*/
void Monstre::setm_posx2 (float posx2){
 m_posx2=posx2;
}

/*
@description:
Mutateur de l'attribut m_posy2.

@param: La methode setm_posy2 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posy2
*/
void Monstre::setm_posy2 (float posy2){
 m_posy2=posy2;
}

/*
@description:
Mutateur de l'attribut m_posx3.

@param: La methode setm_posx3 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posx3
*/
void Monstre::setm_posx3 (float posx3){
 m_posx3=posx3;
}

/*
@description:
Mutateur de l'attribut m_posy3.

@param: La methode setm_posy3 prend un parametre obligatoire: un float
-param1: le nouveau float pour m_posy3
*/
void Monstre::setm_posy3 (float posy3){
 m_posy3=posy3;
}


/******METHODE DE CLASSE: OPERATEURS******/
Monstre& Monstre::operator=(Monstre const& monstreAcopier){
    if(this != &monstreAcopier){//on vérifie que l'objet n'est pas le même que l'objetAcopié reçu en argument
        //on copie tous les attributs qui ne sont pas des objets membres
        m_posx1= monstreAcopier.m_posx1;
        m_posy1= monstreAcopier.m_posy1;
        m_posx2= monstreAcopier.m_posx2;
        m_posy2= monstreAcopier.m_posy2;
        m_posx3= monstreAcopier.m_posx3;
        m_posy3= monstreAcopier.m_posy3;
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
            m_monstreIA= new IAClever(); //par défaut, on initialise l'IA du monstre avec l'IA IAClever si l'IA du monstreAcopier n'est pas lisible
        }

    }
    return *this;
}

