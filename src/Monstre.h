#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"


class Monstre{

private:

    /******ATTRIBUTS******/
	MonstreIA* m_monstreIA=NULL;//initialisation (objet membre)
	float m_posx1;
	float m_posy1;
	float m_posx2;
	float m_posy2;
	float m_posx3;
	float m_posy3;
	float m_speed;
	int m_timer;
	int m_isArrive;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    Monstre(): m_monstreIA(new IAOnePath()), m_posx1(0), m_posy1(0), m_posx2(0), m_posy2(0), m_posx3(0), m_posy3(0), m_speed(100.0), m_timer(0), m_isArrive(0){}

    /******CONSTRUCTEUR A PARAMETRES******/
	Monstre(MonstreIA* monstreIA, float posx1=0, float posy1=0, float posx2=0, float posy2=0, float posx3=0, float posy3=0, float speed=100.0, int timer=0, int isArrive=0): m_monstreIA(monstreIA), m_posx1(posx1), m_posy1(posy1), m_posx2(posx2), m_posy2(posy2), m_posx3(posx3), m_posy3(posy3), m_speed(speed), m_timer(timer), m_isArrive(isArrive) {}

    /******CONSTRUCTEUR DE COPIE******/
    Monstre(Monstre const& monstreAcopier): m_posx1(monstreAcopier.m_posx1), m_posy1(monstreAcopier.m_posy1), m_posx2(monstreAcopier.m_posx2), m_posy2(monstreAcopier.m_posy2), m_posx3(monstreAcopier.m_posx3), m_posy3(monstreAcopier.m_posy3), m_speed(monstreAcopier.m_speed), m_timer(monstreAcopier.m_timer), m_isArrive(monstreAcopier.m_isArrive) {
        if((monstreAcopier.m_monstreIA)->getClass() == "IAOnePath"){//si l'IA du monstre à copier est une IA IAOnePath
          m_monstreIA= new IAOnePath(); //on initialise l'IA du monstre avec l'IA IAOnePath puisque c'est celle du monstreAcopier
        }
        else if((monstreAcopier.m_monstreIA)->getClass() == "IASeveralPaths"){//si l'IA du monstre à copier est une IA IASeveralPaths
             m_monstreIA= new IASeveralPaths(); //on initialise l'IA du monstre avec l'IA IASeveralPaths puisque c'est celle du monstreAcopier
        }
        else if((monstreAcopier.m_monstreIA)->getClass() == "IAClever"){//si l'IA du monstre à copier est une IA IAClever
             m_monstreIA= new IAClever(); //on initialise l'IA du monstre avec l'IA IAClever puisque c'est celle du monstreAcopier
        }
        else{
            m_monstreIA= new IAClever(); //par défaut, on initialise l'IA du monstre avec l'IA IAClever si l'IA du monstreAcopier n'est pas lisible
        }

    }

    /******DESTRUCTEUR******/
    virtual ~Monstre() {
        delete m_monstreIA;
    }


    /******PROTOTYPES DES METHODES******/

    void draw() const;

    void init(std::string nomIA="IAOnePath");

    int isEndPath() const; //Renvoie 1 si le monstre est sur la derniere colonne de la grille et 0 sinon

    BlockGrille searchInitPath(BlockGrille grilleDeJeu[12][12]) const;

    BlockGrille searchPath(BlockGrille grilleDeJeu[12][12]) const;

    void moveSmoothly(BlockGrille nextBlock);

    void walk();

    MonstreIA* getm_monstreIA() const;//Accesseur de l'attribut m_monstreIA

    float getm_speed() const;//Accesseur de l'attribut m_speed

    int getm_isArrive() const;//Accesseur de l'attribut m_isArrive

    void setm_posx1(float posx1);//Setteur de l'attribut m_posx1

    void setm_posy1(float posy1);//Setteur de l'attribut m_posy1

    void setm_posx2(float posx2);//Setteur de l'attribut m_posx2

    void setm_posy2(float posy2);//Setteur de l'attribut m_posy2

    void setm_posx3(float posx3);//Setteur de l'attribut m_posx3

    void setm_posy3(float posy3);//Setteur de l'attribut m_posy3


    /******PROTOTYPE OPERATEURS******/

    Monstre& operator=(Monstre const& monstreAcopier);

};
