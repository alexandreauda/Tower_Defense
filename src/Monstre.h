#pragma once
#include "MonstreIA.h"
#include "IAOnePath.h"
#include "IASeveralPaths.h"
#include "IAClever.h"


class Monstre{

private:

    /******ATTRIBUT******/
	MonstreIA* m_monstreIA=NULL;//initialisation (objet membre)
	int m_m1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
    Monstre(): m_m1(0) {}

    /******CONSTRUCTEUR A PARAMETRES******/
	Monstre(MonstreIA* monstreIA, int m1=0): m_monstreIA(monstreIA), m_m1(m1) {}

    /******CONSTRUCTEUR DE COPIE******/
    Monstre(Monstre const& monstreAcopier): m_m1(monstreAcopier.m_m1) {
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

    void init(std::string nomIA="IAOnePath");

    int isEndPath() const; //Renvoie 1 si le monstre est sur la derniere colonne de la grille et 0 sinon

    BlockGrille searchInitPath(BlockGrille grilleDeJeu[12][12]) const;

    BlockGrille searchPath(BlockGrille grilleDeJeu[12][12]) const;

    void moveSmoothly(BlockGrille nextPosition);

    void walk();


    /******PROTOTYPE OPERATEURS******/

    Monstre& operator=(Monstre const& monstreAcopier);

};
