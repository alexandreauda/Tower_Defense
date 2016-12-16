#include "ThiefRegenerationFastMonstre.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/
//Les accesseurs de la Class RegenerationFastMonstre


/******IMPLEMENTATION DES MUTATEURS******/
//Les mutateurs de la Class RegenerationFastMonstre


/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode getClass de la classe ThiefRegenerationFastMonstre renvoie le nom de la Class (ici, le string "ThiefRegenerationFastMonstre").

@param: null
*/
string ThiefRegenerationFastMonstre::getClass() const{
    return "ThiefRegenerationFastMonstre";
}

/*
@description:
La methode draw de la classe ThiefRegenerationFastMonstre permet de dessiner des Monstres beige de maniere graphique.

@param: La methode walk prend un parametre obligatoire: un pointeur de type Joueur.
-param1: un pointeur de type Joueur qui correspond au player
*/
void ThiefRegenerationFastMonstre::draw(Joueur* player) const{

    //Met les valeurs RGB dans la couleur beige
    float r=0.7;
    float g=0.3;
    float b=0.3;
    float const alpha = 1.0;

    float const subdivise=100.0;

    //Gestion de la couleur des Monstres en fonction du niveau
    if(r-player->getm_level()/subdivise < 0.0){
        r=0.0;
    }
    else{
        r-=player->getm_level()/subdivise;
    }

    if(g-player->getm_level()/subdivise < 0.0){
        g=0.0;
    }
    else{
        g-=player->getm_level()/subdivise;
    }

    if(b-player->getm_level()/subdivise < 0.0){
        b=0.0;
    }
    else{
        b-=player->getm_level()/subdivise;
    }


    //Dessine les monstres
    GraphicPrimitives::drawFillTriangle2D(m_posx1, m_posy1, m_posx2, m_posy2, m_posx3, m_posy3, r, g, b, alpha);

}

/*
@description:
La methode walk de la classe ThiefRegenerationFastMonstre permet au ThiefRegenerationFastMonstre de trouver son chemin dans le labyrinthe et de se deplacer en consequence, du block ou se trouve le FastMonstre initialement au prochain block, le tout de maniere continue.

@param: La methode walk prend un parametre obligatoire et un parametre facultatif: un pointeur de type Joueur et un string facultatif.
-param1: un pointeur de type Joueur qui correspond au player
-param2: un string facultatif qui specifie le repertoire ou se trouve la grille ou s'effectue le deplacement.
*/
void ThiefRegenerationFastMonstre::walk(Joueur* player, string const& stringNameDirectory){

    BlockGrille grilleDeJeu[12][12];
    Grille grilleInit;
    grilleInit.loadGrille(player->getm_level(),grilleDeJeu,stringNameDirectory);//Load la matrice m_grilleDeJeu

    //Variable qui contiendra le prochain BlockGrille ou ira le Monstre
    BlockGrille nextBlock;

    //Si m_timer%(int)m_speed == 0 (i.e: Le Monstre est sur le centre d'un block)
    if(m_timer%(int)m_speed == 0){
        //Si le Monstre est arrive au bout du labyrinthe
        if(this->isEndPath() == 1){
           m_isArrive=1;//Mettre l'attribut m_isArrive a 1
           player->receiveDamage(m_damageAttack);//On baisse la vie du Joueur
           player->spendMoney(m_moneyStolen);//On baisse l'argent du Joueur a hauteur de la valeur de l'attribut m_moneyStolen
        }
        //Si le Monstre n'est pas arrive au bout du labyrinthe
        else{
            //Si le Monstre n'est pas dans une impasse
            if(this->searchIfPath(grilleDeJeu) == 1){
                nextBlock=this->searchPath(grilleDeJeu);//Le Monstre trouve son chemin dans le labyrinthe et connait donc le prochain block ou il doit se rendre. On stock donc ce block dans la variable nextBlock.
                (this->getm_monstreIA())->setm_previousPosition((this->getm_monstreIA())->getm_actualPosition());//on met l'attribut m_previousPosition egal a m_actualPosition.
                (this->getm_monstreIA())->setm_actualPosition(nextBlock);//on met l'attribut m_actualPosition egal a nextBlock qui contient la prochaine destination du Monstre.
                this->moveSmoothly(nextBlock);//on deplace lentement le Monstre.
                m_timer++;//on incremente l'attribut m_timer.
            }
            //Si le Monstre est dans une impasse
            else{
                m_isLock=1;
            }
        }
    }
    //Si m_timer%(int)m_speed != 0
    else{
        this->moveSmoothly(nextBlock);//on deplace lentement le Monstre.
        m_timer++;//on incremente l'attribut m_timer.
    }
}

/*
@description:
La methode increaseMoneyStolen de la Class ThiefRegenerationFastMonstre prend un int en parametre et fait augmenter la valeur de l'argent derobe par le ThiefRegenerationFastMonstre d'une valeur egale a la valeur du int pris en parametre.

@param: La methode increaseMoneyStolen prend un parametre facultatif: un int facultatif.
-param1: Le int facultatif doit representer la valeur de l'augmentation de l'argent derobe par le ThiefRegenerationFastMonstre. Par defaut, ce parametre vaut 1.
*/
void ThiefRegenerationFastMonstre::increaseMoneyStolen(int const& rateMoneyStolen){
    m_moneyStolen+=rateMoneyStolen;
}

/*
@description:
La methode increaseRateRegeneration de la classe ThiefRegenerationFastMonstre prend un int en parametre et fait augmenter l'attribut m_rateRegeneration du RegenerationExplosedStrongMonstre d'une valeur egale a la valeur du int pris en parametre.

@param: La methode increaseRateRegeneration prend un parametre facultatif: un int facultatif.
-param1: Le int facultatif doit representer la valeur de l'augmentation de l'attribut m_rateRegeneration du ThiefRegenerationFastMonstre. Par defaut, ce parametre vaut 1.
*/
void ThiefRegenerationFastMonstre::increaseRateRegeneration(int const& rateRegenerationWin){
    m_rateRegeneration+=rateRegenerationWin;
}


/*
@description:
La methode increaseLevelMonstre de la Class ThiefRegenerationFastMonstre permet de gerer le niveau des Monstres en fonction du niveau du level. Ainsi, un Joueur de niveau 1 par exemple, combattra des Monsres de niveau 1 et ainsi de suite.

@param: La methode increaseLevelMonstre prend un parametre obligatoire et deux parametres facultatifs: un Joueur, un string facultatif, un int unsigned facultatif.
-param1: Le parametre de type Joueur doit etre le Joueur qui effectue la partie.
-param1: Le string facultatif doit representer le nom de l'attribut du ThiefRegenerationFastMonstre que l'on veut augmenter. Par defaut, ce parametre vaut "random" ce qui signifie que l'augmentation de niveau augmente un des attributs du Monstre determine aleatoirement.
-param3: Le int unsigned facultatif doit representer la valeur du facteur de l'augmentation d'un attribut du ThiefRegenerationFastMonstre. Par defaut, ce parametre vaut 1.
*/
void ThiefRegenerationFastMonstre::increaseLevelMonstre(Joueur* player, string const& nameAttribut, int unsigned const& stepIncrease){

    int const niveau=stepIncrease*(player->getm_level()-1);

    for(int i=0;i<niveau;i++){
        if(nameAttribut == "m_vie"){
            increaseVie(1);
        }
        else if(nameAttribut == "m_damageAttack"){
            increaseDamageAttack(1);
        }
        else if(nameAttribut == "m_moneyStolen"){
            increaseMoneyStolen(1);
        }
        else if (nameAttribut == "random"){
            int varHazard=LibMatrix::varAleatoire(4);

            switch(varHazard){

                case 1: increaseVie(1);
                        break;

                case 2: increaseDamageAttack(1);
                        break;

                case 3: increaseMoneyStolen(1);
                        break;

                case 4: increaseRateRegeneration(1);
                        break;

                default: increaseVie(1);
                         break;

            }
        }
        else{
            increaseVie(1);
        }
    }
}

/*
@description:
La methode regeneration de la classe ThiefRegenerationFastMonstre permet de regenerer la vie du Monstre d'une valeur egale a celle de l'attribut m_rateRegeneration.

@param: null
*/
void ThiefRegenerationFastMonstre::regeneration(){
    int const vieAfterRegeneration=m_vie+m_rateRegeneration;
    int const vieMax=LibMatrix::loadIntInFileWithDirectory("InitialLifeThiefRegenerationFastMonstre","InitialLifeMonstre/");

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
ThiefRegenerationFastMonstre& ThiefRegenerationFastMonstre::operator=(ThiefRegenerationFastMonstre const& monstreAcopier){
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
        m_moneyStolen= monstreAcopier.m_moneyStolen;

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

