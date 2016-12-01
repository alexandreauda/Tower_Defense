#include "MyControlEngine.h"

using namespace std;

/******IMPLEMENTATION DES ACCESSEURS******/
//null


/******IMPLEMENTATION DES MUTATEURS******/
//null



/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode MouseCallback de la classe MyControlEngine permet d'effectuer des actions lors d'un clic de la souris.

@param:  La methode MouseCallback prend quatre parametres obligatoires: un int, un int, un int, un int.
-param1: Ce premier parametre designe la touche de la souris.
-param2: Ce deuxieme parametre l'etat de la touche de la souris.
-param3: Ce troisieme parametre designe l'abscisse ou l'on se trouve lors de l'evenement souris.
-param4: Ce quatrieme parametre designe l'ordonne ou l'on se trouve lors de l'evenement souris.
*/
void MyControlEngine::MouseCallback(int button, int state, int x, int y){

    Grille grilleInit;
    grilleInit.loadGrille(m_player->getm_level(),m_grilleDeJeu);//Load la matrice m_grilleDeJeu

    //Si le bouton gauche de la souris est enfoncé alors...
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        float widthWindows=glutGet(GLUT_WINDOW_WIDTH);//on recupere la largeur de la grille
        float heigthWindows=glutGet(GLUT_WINDOW_HEIGHT);//on recupere la hauteur de la grille

        widthWindows/=2.0;//on divise la largeur de la grille par 2.
        heigthWindows/=2.0;//on divise la hauteur de la grille par 2.

        float mousePosx=(x-widthWindows)/widthWindows;//position en abscisse de la souris dans la fenetre GLUT
        float mousePosy=(-(y-heigthWindows)/heigthWindows);//position en ordonne de la souris dans la fenetre GLUT

        char* textNotEnoughMoney=new char[20]{'N','O','T',' ','E','N','O','U','G','T',' ','M','O','N','E','Y','!'};//Contient le texte NOT ENOUGH MONEY.

        int const costTowerDefenseYellow(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseYellow.txt"));//Cout d'une tourelle jaune
        int const costTowerDefenseOrange(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseOrange.txt"));//Cout d'une tourelle orange
        int const costTowerDefensePurple(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefensePurple.txt"));//Cout d'une tourelle violette

        //on parcourt la grille
        for(int x=0;x<12;x++){
            for(int y=0;y<12;y++){
                if(((m_grilleDeJeu[x][y]).pointIsInBlockFree(mousePosx,mousePosy) == 1) && ((m_grilleDeJeu[x][y]).getm_colorBlockID() == 0)){ //Si la souris appuie sur un block libre de la grille
                    switch(m_stockColorTower){ //switch la couleur stockees dans la souris

                        case 0: cout<<"-Vous n'avez plus de tourelles stockees dans votre souris!"<<endl;
                                cout<<"-Pour pouvoir redeposer une tourelle, veuillez choisir une tourelle dans le Store!"<<endl<<endl;
                                break;

                        case 1: //Si le player a assez d'argent pour se payer une tourelle jaune
                                if(m_player->haveMoneyEnough(costTowerDefenseYellow) == 1){
                                    m_player->spendMoney(costTowerDefenseYellow);//Le joueur paye le cout d'une tourelle jaune
                                     m_TowerDefenseList->push_back(new TowerDefenseYellow((m_grilleDeJeu[x][y])));//on rajoute une tourelle jaune sur la case correspondante
                                    (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupeé par une tourelle
                                    (m_grilleDeJeu[x][y]).setm_colorTowerID(1);//on met l'attribut m_colorTowerID de la case correspondante a 1, ce qui veut dire que cette case est occupeé par une tourelle jaune
                                    cout<<"Vous avez depose une tourelle jaune!"<<endl<<endl;
                                }
                                //Si le player n'a pas assez d'argent pour se payer une tourelle jaune
                                else{
                                    cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle jaune!"<<endl<<endl;
                                }
                                break;

                        case 2: //Si le player a assez d'argent pour se payer une tourelle orange
                                if(m_player->haveMoneyEnough(costTowerDefenseOrange) == 1){
                                    m_player->spendMoney(costTowerDefenseOrange);//Le joueur paye le cout d'une tourelle orange
                                    m_TowerDefenseList->push_back(new TowerDefenseOrange((m_grilleDeJeu[x][y])));//on rajoute une tourelle orange sur la case correspondante
                                    (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupeé par une tourelle
                                    (m_grilleDeJeu[x][y]).setm_colorTowerID(2);//on met l'attribut m_colorTowerID de la case correspondante a 2, ce qui veut dire que cette case est occupeé par une tourelle orange
                                    cout<<"Vous avez depose une tourelle orange!"<<endl<<endl;
                                }
                                //Si le player n'a pas assez d'argent pour se payer une tourelle orange
                                else{
                                    cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle orange!"<<endl<<endl;
                                }
                                break;

                        case 3: //Si le player a assez d'argent pour se payer une tourelle violette
                                if(m_player->haveMoneyEnough(costTowerDefensePurple) == 1){
                                    m_player->spendMoney(costTowerDefensePurple);//Le joueur paye le cout d'une tourelle violette
                                    m_TowerDefenseList->push_back(new TowerDefensePurple((m_grilleDeJeu[x][y])));//on rajoute une tourelle violette sur la case correspondante
                                    (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupeé par une tourelle
                                    (m_grilleDeJeu[x][y]).setm_colorTowerID(3);//on met l'attribut m_colorTowerID de la case correspondante a 3, ce qui veut dire que cette case est occupeé par une tourelle violette
                                    cout<<"Vous avez deposer une tourelle viollette!"<<endl<<endl;
                                }
                                //Si le player n'a pas assez d'argent pour se payer une tourelle violette
                                else{
                                    cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle violette!"<<endl<<endl;
                                }
                                break;

                        default: break;
                    }
                }
                else{//Sinon
                        if(((m_grilleDeJeu[x][y]).pointIsInBlock(mousePosx,mousePosy) == 1) && ((m_grilleDeJeu[x][y]).pointIsInBlockFree(mousePosx,mousePosy) == 0) && (m_stockColorTower != 0) && (m_stockColorTower == (m_grilleDeJeu[x][y]).getm_colorTowerID())){//Si la souris appuie sur un block deja occupe par une tourelle de meme couleur que celle stockee dans la souris
                            cout<<"Evolution des tourelles en cours d'implementaion: Vous ne pouvez pas encore faire monter de niveau une tourelle."<<endl<<endl;
                        }
                        else{//Sinon
                            if(((m_grilleDeJeu[x][y]).pointIsInBlockFree(mousePosx,mousePosy) == 1) && ((m_grilleDeJeu[x][y]).getm_colorBlockID() == 1)){//Si la souris appuie sur un block appartenant au chemin emprunte par les Monstres
                                cout<<"Attention: Vous ne pouvez pas depose une tourelle sur le chemin emprunte par les Monstres!"<<endl<<endl;
                            }
                            else{//Sinon
                                if(((m_grilleDeJeu[x][y]).pointIsInBlock(mousePosx,mousePosy) == 1) && ((m_grilleDeJeu[x][y]).pointIsInBlockFree(mousePosx,mousePosy) == 0) && (m_stockColorTower != 0) && (m_stockColorTower != (m_grilleDeJeu[x][y]).getm_colorTowerID())){//Si la souris appuie sur un block deja occupe par une tourelle de couleur differente de celle stockee dans la souris
                                    cout<<"Attention: Vous ne pouvez pas depose une tourelle sur une tourelle existante!"<<endl<<endl;
                                }
                                else{//Sinon
                                    if(((m_grilleDeJeu[x][y]).pointIsInBlock(mousePosx,mousePosy) == 1) && ((m_grilleDeJeu[x][y]).pointIsInBlockFree(mousePosx,mousePosy) == 0) && (m_stockColorTower == 0)){//Si la souris appuie sur un block deja occupe par une tourelle mais qu'elle n'a pas de couleur stockee dans celle-ci
                                        cout<<"-Vous n'avez plus de tourelles stockees dans votre souris!"<<endl;
                                        cout<<"-Pour pouvoir redeposer une tourelle, veuillez choisir une tourelle dans le Store!"<<endl<<endl;
                                    }
                                }
                            }
                        }

                }
            }
        }

        //On parcourt le Store
        for(int i=0; i<12;i++){
            if((m_stockStore[i]).pointIsInBlock(mousePosx,mousePosy) == 1){//Si la souris appuie sur un block du Store
                    switch((m_stockStore[i]).getm_posID()){ //switch en fonction de la case du Store

                        case 0: m_stockColorTower=0;//on vide la couleur de la souris
                                cout<<"Vous avez clique sur la corbeille du Store:"<<endl;
                                cout<<"-Vous n'avez donc plus de tourelles stockees dans votre souris!"<<endl;
                                cout<<"-Pour pouvoir redeposer une tourelle, veuillez choisir une tourelle dans le Store!"<<endl<<endl;
                                break;

                        case 1: m_stockColorTower=1;//on met la couleur de la souris a 1 ce qui correspond a la couleur jaune
                                cout<<"Vous avez choisi une tourelle jaune dans le Store:"<<endl;
                                cout<<"-Veuillez la placer sur la grille!"<<endl<<endl;
                                break;

                        case 2: m_stockColorTower=2;//on met la couleur de la souris a 2 ce qui correspond a la couleur orange
                                cout<<"Vous avez choisi une tourelle orange dans le Store:"<<endl;
                                cout<<"-Veuillez la placer sur la grille!"<<endl<<endl;
                                break;

                        case 3: m_stockColorTower=3;//on met la couleur de la souris a 3 ce qui correspond a la couleur violette
                                cout<<"Vous avez choisi une tourelle violette dans le Store:"<<endl;
                                cout<<"-Veuillez la placer sur la grille!"<<endl<<endl;
                                break;

                        default: cout<<"Vous avez clique sur une case du Store qui n'est pas encore approvisionnee!"<<endl;
                                 cout<<"-Pour pouvoir redeposer une tourelle, veuillez choisir une tourelle dans le Store!"<<endl<<endl;
                                 break;
                    }
            }
        }

        //On verifie le bouton qui lance les Monstres
        if(m_buttonStartMonstre.pointIsInBlock(mousePosx,mousePosy) == 1){

            m_player->setm_isAttack();

        }

    }

    //Si le bouton droit de la souris est enfoncé alors...
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

        m_stockColorTower=0;//on met l'attribut m_stockColorTower a 0. Ainsi, cela permet a l'utilisateur qui a choisit une couleur de tourelle de se retracter pour choisir une autre couleur de tourelle ou simplement pour eviter de mettre une tourelle sur la grille involontairement.
        cout<<"Vous avez clique avec le bouton droit de la souris:"<<endl;
        cout<<"-Vous n'avez donc plus de tourelles stockees dans votre souris!"<<endl;
        cout<<"-Pour pouvoir redeposer une tourelle, veuillez choisir une tourelle dans le Store!"<<endl<<endl;

    }
}


/*
@description:
La methode KeyboardCallback de la classe MyControlEngine permet d'effectuer des actions lors de la pression d'une touche du clavier.

@param:  La methode KeyboardCallback prend trois parametres obligatoires: un unsigned char, un int, un int.
-param1: Ce premier parametre designe la touche du clavier que l'on a pressee.
-param2: Ce deuxieme parametre designe l'abscisse ou l'on se trouve lors de la pression de la touche du clavier.
-param3: Ce troisieme parametre designe l'ordonne ou l'on se trouve lors de la pression de la touche du clavier.
*/
void MyControlEngine::KeyboardCallback(unsigned char key,int x, int y){

    if(key == 'g'){
        m_player->setm_isAttack();
    }
}

