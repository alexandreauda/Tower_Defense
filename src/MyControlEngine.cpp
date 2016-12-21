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

    //Si l'attribut m_currentDrawLevel est different du niveau du Joueur
    if(m_currentDrawLevel != m_player->getm_level()){
        Grille grilleInit;
        //Si le niveau du Joueur est different de 0
        if(m_player->getm_level() != 0){
            grilleInit.loadGrille(m_player->getm_level(),m_grilleDeJeu);//Load la matrice m_grilleDeJeu
        }
        else{
            grilleInit.loadGrille(m_player->getm_level(), m_grilleDeJeu,"Level_Player/");//On initialise la variable m_grilleDeJeu avec la grille du level courant
        }
        m_currentDrawLevel=m_player->getm_level();//On set la valeur de l'attribut m_currentDrawLevel a la valeur du niveau du Joueur
    }

    //Si le bouton gauche de la souris est enfoncé alors...
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        float widthWindows=glutGet(GLUT_WINDOW_WIDTH);//on recupere la largeur de la grille
        float heigthWindows=glutGet(GLUT_WINDOW_HEIGHT);//on recupere la hauteur de la grille

        widthWindows/=2.0;//on divise la largeur de la grille par 2.
        heigthWindows/=2.0;//on divise la hauteur de la grille par 2.

        float mousePosx=(x-widthWindows)/widthWindows;//position en abscisse de la souris dans la fenetre GLUT
        float mousePosy=(-(y-heigthWindows)/heigthWindows);//position en ordonne de la souris dans la fenetre GLUT

        //Si le Joueur n'est pas dans le Jeu
        if(m_player->getm_isInGame() == false){
            //On verifie le bouton qui permet de commencer une nouvelle partie
            if(m_buttonNewGame.pointIsInBlock(mousePosx,mousePosy) == 1){

                m_player->setm_isInGame(true);//Le Joueur commence une nouvelle partie.

            }

            //On verifie le bouton qui permet de charger une partie precedemment sauvee
            if(m_buttonLoadGame.pointIsInBlock(mousePosx,mousePosy) == 1){

                m_player->LoadGame();//Le Joueur set ses attributs avec les valeurs sauvegardees precedemment.
                if(m_player->getm_level() != 1){
                   m_player->decreaseLevel();//On decremente l'attribut m_level
                }
                m_player->setm_isInGame(true);//Le Joueur commence une nouvelle partie.

            }
            //On verifie le bouton qui permet de commencer une partie sur un niveau exclusivement dedie au Joueur. C'est donc exclusivement le Joueur qui definit le trace du chemin des Monstres de ce niveau.
            if(m_buttonLevelJoueur.pointIsInBlock(mousePosx,mousePosy) == 1){

                m_player->decreaseLevel();//On decremente l'attribut m_level
                m_player->setm_isInGame(true);//Le Joueur commence une nouvelle partie.

            }
        }
        //Sinon, si le Joueur n'est pas dans le Jeu
        else{

            int const costTowerDefenseYellow(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseYellow.txt"));//Cout d'une tourelle jaune
            int const costTowerDefenseOrange(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseOrange.txt"));//Cout d'une tourelle orange
            int const costTowerDefensePurple(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefensePurple.txt"));//Cout d'une tourelle violette
            int const costTowerDefenseRicochet(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseRicochet.txt"));//Cout d'une tourelle Ricochet
            int const costTowerDefenseYellowLongShot(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseYellowLongShot.txt"));//Cout d'une tourelle TowerDefenseYellowLongShot
            int const costTowerDefenseOrangeLongShot(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseOrangeLongShot.txt"));//Cout d'une tourelle TowerDefenseOrangeLongShot
            int const costTowerDefensePurpleLongShot(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefensePurpleLongShot.txt"));//Cout d'une tourelle TowerDefensePurpleLongShot
            int const costTowerDefenseRicochetMediumLevel(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseRicochetMediumLevel.txt"));//Cout d'une tourelle TowerDefenseRicochetMediumLevel
            int const costTowerDefenseYellowSniper(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseYellowSniper.txt"));//Cout d'une tourelle TowerDefenseYellowSniper
            int const costTowerDefenseOrangeSniper(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseOrangeSniper.txt"));//Cout d'une tourelle costTowerDefenseOrangeSniper
            int const costTowerDefensePurpleSniper(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefensePurpleSniper.txt"));//Cout d'une tourelle TowerDefensePurpleSniper
            int const costTowerDefenseRicochetHighLevel(LibMatrix::loadIntInFile("CostTowerDefense/CostTowerDefenseRicochetHighLevel.txt"));//Cout d'une tourelle TowerDefenseRicochetHighLevel

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
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(1);//on met l'attribut m_colorTowerID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle jaune
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
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(2);//on met l'attribut m_colorTowerID de la case correspondante a 2, ce qui veut dire que cette case est occupee par une tourelle orange
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
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(3);//on met l'attribut m_colorTowerID de la case correspondante a 3, ce qui veut dire que cette case est occupee par une tourelle violette
                                        cout<<"Vous avez deposer une tourelle viollette!"<<endl<<endl;
                                    }
                                    //Si le player n'a pas assez d'argent pour se payer une tourelle violette
                                    else{
                                        cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle violette!"<<endl<<endl;
                                    }
                                    break;

                            case 4: //Si le player a assez d'argent pour se payer une tourelle Ricochet
                                    if(m_player->haveMoneyEnough(costTowerDefenseRicochet) == 1){
                                        m_player->spendMoney(costTowerDefenseRicochet);//Le joueur paye le cout d'une tourelle violette
                                        m_TowerDefenseList->push_back(new TowerDefenseRicochet((m_grilleDeJeu[x][y])));//on rajoute une tourelle violette sur la case correspondante
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(4);//on met l'attribut m_colorTowerID de la case correspondante a 4, ce qui veut dire que cette case est occupee par une tourelle Ricochet
                                        cout<<"Vous avez deposer une tourelle Ricochet!"<<endl<<endl;
                                    }
                                    //Si le player n'a pas assez d'argent pour se payer une tourelle violette
                                    else{
                                        cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle Ricochet!"<<endl<<endl;
                                    }
                                    break;

                            case 5: //Si le player a assez d'argent pour se payer une tourelle TowerDefenseYellowLongShot
                                    if(m_player->haveMoneyEnough(costTowerDefenseYellowLongShot) == 1){
                                        m_player->spendMoney(costTowerDefenseYellowLongShot);//Le joueur paye le cout d'une tourelle TowerDefenseYellowLongShot
                                        m_TowerDefenseList->push_back(new TowerDefenseYellowLongShot((m_grilleDeJeu[x][y])));//on rajoute une tourelle TowerDefenseYellowLongShot sur la case correspondante
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(5);//on met l'attribut m_colorTowerID de la case correspondante a 5, ce qui veut dire que cette case est occupee par une tourelle TowerDefenseYellowLongShot
                                        cout<<"Vous avez deposer une tourelle TowerDefenseYellowLongShot!"<<endl<<endl;
                                    }
                                    //Si le player n'a pas assez d'argent pour se payer une tourelle TowerDefenseYellowLongShot
                                    else{
                                        cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle TowerDefenseYellowLongShot!"<<endl<<endl;
                                    }
                                    break;

                            case 6: //Si le player a assez d'argent pour se payer une tourelle TowerDefenseOrangeLongShot
                                    if(m_player->haveMoneyEnough(costTowerDefenseOrangeLongShot) == 1){
                                        m_player->spendMoney(costTowerDefenseOrangeLongShot);//Le joueur paye le cout d'une tourelle TowerDefenseOrangeLongShot
                                        m_TowerDefenseList->push_back(new TowerDefenseOrangeLongShot((m_grilleDeJeu[x][y])));//on rajoute une tourelle TowerDefenseOrangeLongShot sur la case correspondante
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(6);//on met l'attribut m_colorTowerID de la case correspondante a 6, ce qui veut dire que cette case est occupee par une tourelle TowerDefenseOrangeLongShot
                                        cout<<"Vous avez deposer une tourelle TowerDefenseOrangeLongShot!"<<endl<<endl;
                                    }
                                    //Si le player n'a pas assez d'argent pour se payer une tourelle TowerDefenseOrangeLongShot
                                    else{
                                        cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle TowerDefenseOrangeLongShot!"<<endl<<endl;
                                    }
                                    break;

                            case 7: //Si le player a assez d'argent pour se payer une tourelle TowerDefensePurpleLongShot
                                    if(m_player->haveMoneyEnough(costTowerDefensePurpleLongShot) == 1){
                                        m_player->spendMoney(costTowerDefensePurpleLongShot);//Le joueur paye le cout d'une tourelle TowerDefensePurpleLongShot
                                        m_TowerDefenseList->push_back(new TowerDefensePurpleLongShot((m_grilleDeJeu[x][y])));//on rajoute une tourelle TowerDefensePurpleLongShot sur la case correspondante
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(7);//on met l'attribut m_colorTowerID de la case correspondante a 6, ce qui veut dire que cette case est occupee par une tourelle TowerDefensePurpleLongShot
                                        cout<<"Vous avez deposer une tourelle TowerDefensePurpleLongShot!"<<endl<<endl;
                                    }
                                    //Si le player n'a pas assez d'argent pour se payer une tourelle TowerDefensePurpleLongShot
                                    else{
                                        cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle TowerDefensePurpleLongShot!"<<endl<<endl;
                                    }
                                    break;

                            case 8: //Si le player a assez d'argent pour se payer une tourelle TowerDefenseRicochetMediumLevel
                                    if(m_player->haveMoneyEnough(costTowerDefenseRicochetMediumLevel) == 1){
                                        m_player->spendMoney(costTowerDefenseRicochetMediumLevel);//Le joueur paye le cout d'une tourelle TowerDefenseRicochetMediumLevel
                                        m_TowerDefenseList->push_back(new TowerDefenseRicochetMediumLevel((m_grilleDeJeu[x][y])));//on rajoute une tourelle TowerDefenseRicochetMediumLevel sur la case correspondante
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(8);//on met l'attribut m_colorTowerID de la case correspondante a 6, ce qui veut dire que cette case est occupee par une tourelle TowerDefenseRicochetMediumLevel
                                        cout<<"Vous avez deposer une tourelle TowerDefenseRicochetMediumLevel!"<<endl<<endl;
                                    }
                                    //Si le player n'a pas assez d'argent pour se payer une tourelle TowerDefenseRicochetMediumLevel
                                    else{
                                        cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle TowerDefenseRicochetMediumLevel!"<<endl<<endl;
                                    }
                                    break;

                            case 9: //Si le player a assez d'argent pour se payer une tourelle TowerDefenseYellowSniper
                                    if(m_player->haveMoneyEnough(costTowerDefenseYellowSniper) == 1){
                                        m_player->spendMoney(costTowerDefenseYellowSniper);//Le joueur paye le cout d'une tourelle TowerDefenseYellowSniper
                                        m_TowerDefenseList->push_back(new TowerDefenseYellowSniper((m_grilleDeJeu[x][y])));//on rajoute une tourelle TowerDefenseYellowSniper sur la case correspondante
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(9);//on met l'attribut m_colorTowerID de la case correspondante a 6, ce qui veut dire que cette case est occupee par une tourelle TowerDefenseYellowSniper
                                        cout<<"Vous avez deposer une tourelle TowerDefenseYellowSniper!"<<endl<<endl;
                                    }
                                    //Si le player n'a pas assez d'argent pour se payer une tourelle TowerDefenseYellowSniper
                                    else{
                                        cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle TowerDefenseYellowSniper!"<<endl<<endl;
                                    }
                                    break;

                            case 10: //Si le player a assez d'argent pour se payer une tourelle TowerDefenseOrangeSniper
                                    if(m_player->haveMoneyEnough(costTowerDefenseOrangeSniper) == 1){
                                        m_player->spendMoney(costTowerDefenseOrangeSniper);//Le joueur paye le cout d'une tourelle TowerDefenseOrangeSniper
                                        m_TowerDefenseList->push_back(new TowerDefenseOrangeSniper((m_grilleDeJeu[x][y])));//on rajoute une tourelle TowerDefenseOrangeSniper sur la case correspondante
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(10);//on met l'attribut m_colorTowerID de la case correspondante a 6, ce qui veut dire que cette case est occupee par une tourelle TowerDefenseOrangeSniper
                                        cout<<"Vous avez deposer une tourelle TowerDefenseOrangeSniper!"<<endl<<endl;
                                    }
                                    //Si le player n'a pas assez d'argent pour se payer une tourelle TowerDefenseOrangeSniper
                                    else{
                                        cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle TowerDefenseOrangeSniper!"<<endl<<endl;
                                    }
                                    break;

                            case 11: //Si le player a assez d'argent pour se payer une tourelle TowerDefensePurpleSniper
                                    if(m_player->haveMoneyEnough(costTowerDefensePurpleSniper) == 1){
                                        m_player->spendMoney(costTowerDefensePurpleSniper);//Le joueur paye le cout d'une tourelle TowerDefensePurpleSniper
                                        m_TowerDefenseList->push_back(new TowerDefensePurpleSniper((m_grilleDeJeu[x][y])));//on rajoute une tourelle TowerDefensePurpleSniper sur la case correspondante
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(11);//on met l'attribut m_colorTowerID de la case correspondante a 6, ce qui veut dire que cette case est occupee par une tourelle TowerDefensePurpleSniper
                                        cout<<"Vous avez deposer une tourelle TowerDefensePurpleSniper!"<<endl<<endl;
                                    }
                                    //Si le player n'a pas assez d'argent pour se payer une tourelle TowerDefensePurpleSniper
                                    else{
                                        cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle TowerDefensePurpleSniper!"<<endl<<endl;
                                    }
                                    break;

                            case 12: //Si le player a assez d'argent pour se payer une tourelle TowerDefenseRicochetHighLevel
                                    if(m_player->haveMoneyEnough(costTowerDefenseRicochetHighLevel) == 1){
                                        m_player->spendMoney(costTowerDefenseRicochetHighLevel);//Le joueur paye le cout d'une tourelle TowerDefenseRicochetHighLevel
                                        m_TowerDefenseList->push_back(new TowerDefenseRicochetHighLevel((m_grilleDeJeu[x][y])));//on rajoute une tourelle TowerDefenseRicochetHighLevel sur la case correspondante
                                        (m_grilleDeJeu[x][y]).setm_isFreeID(1);//on met l'attribut m_isFreeID de la case correspondante a 1, ce qui veut dire que cette case est occupee par une tourelle
                                        (m_grilleDeJeu[x][y]).setm_colorTowerID(12);//on met l'attribut m_colorTowerID de la case correspondante a 6, ce qui veut dire que cette case est occupee par une tourelle TowerDefenseRicochetHighLevel
                                        cout<<"Vous avez deposer une tourelle TowerDefenseRicochetHighLevel!"<<endl<<endl;
                                    }
                                    //Si le player n'a pas assez d'argent pour se payer une tourelle TowerDefenseRicochetHighLevel
                                    else{
                                        cout<<"Vous n'avez pas assez d'argent pour deposer une tourelle TowerDefenseRicochetHighLevel!"<<endl<<endl;
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
            for(int i=0; i<13;i++){
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

                            case 4: m_stockColorTower=4;//on met la couleur de la souris a 4 ce qui correspond a la couleur de la tourelle Ricochet
                                    cout<<"Vous avez choisi une tourelle Ricochet dans le Store:"<<endl;
                                    cout<<"-Veuillez la placer sur la grille!"<<endl<<endl;
                                    break;

                            case 5: m_stockColorTower=5;//on met la couleur de la souris a 5 ce qui correspond a la couleur de la tourelle TowerDefenseYellowLongShot
                                    cout<<"Vous avez choisi une tourelle TowerDefenseYellowLongShot dans le Store:"<<endl;
                                    cout<<"-Veuillez la placer sur la grille!"<<endl<<endl;
                                    break;

                            case 6: m_stockColorTower=6;//on met la couleur de la souris a 6 ce qui correspond a la couleur de la tourelle TowerDefenseOrangeLongShot
                                    cout<<"Vous avez choisi une tourelle TowerDefenseOrangeLongShot dans le Store:"<<endl;
                                    cout<<"-Veuillez la placer sur la grille!"<<endl<<endl;
                                    break;

                            case 7: m_stockColorTower=7;//on met la couleur de la souris a 7 ce qui correspond a la couleur de la tourelle TowerDefensePurpleLongShot
                                    cout<<"Vous avez choisi une tourelle TowerDefensePurpleLongShot dans le Store:"<<endl;
                                    cout<<"-Veuillez la placer sur la grille!"<<endl<<endl;
                                    break;

                            case 8: m_stockColorTower=8;//on met la couleur de la souris a 8 ce qui correspond a la couleur de la tourelle TowerDefenseRicochetMediumLevel
                                    cout<<"Vous avez choisi une tourelle TowerDefenseRicochetMediumLevel dans le Store:"<<endl;
                                    cout<<"-Veuillez la placer sur la grille!"<<endl<<endl;
                                    break;

                            case 9: m_stockColorTower=9;//on met la couleur de la souris a 9 ce qui correspond a la couleur de la tourelle TowerDefenseYellowSniper
                                    cout<<"Vous avez choisi une tourelle TowerDefenseYellowSniper dans le Store:"<<endl;
                                    cout<<"-Veuillez la placer sur la grille!"<<endl<<endl;
                                    break;

                            case 10: m_stockColorTower=10;//on met la couleur de la souris a 10 ce qui correspond a la couleur de la tourelle TowerDefenseOrangeSniper
                                    cout<<"Vous avez choisi une tourelle TowerDefenseOrangeSniper dans le Store:"<<endl;
                                    cout<<"-Veuillez la placer sur la grille!"<<endl<<endl;
                                    break;

                            case 11: m_stockColorTower=11;//on met la couleur de la souris a 11 ce qui correspond a la couleur de la tourelle TowerDefensePurpleSniper
                                    cout<<"Vous avez choisi une tourelle TowerDefensePurpleSniper dans le Store:"<<endl;
                                    cout<<"-Veuillez la placer sur la grille!"<<endl<<endl;
                                    break;

                            case 12: m_stockColorTower=12;//on met la couleur de la souris a 12 ce qui correspond a la couleur de la tourelle TowerDefenseRicochetHighLevel
                                    cout<<"Vous avez choisi une tourelle TowerDefenseRicochetHighLevel dans le Store:"<<endl;
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

                m_player->setm_isAttack(true);//Le Joueur est attaque

            }

            //Si le niveau du Joueur est different de 0
            if(m_player->getm_level() != 0){
                //On verifie le bouton qui sauvegarde la partie
                if(m_buttonSaveGame.pointIsInBlock(mousePosx,mousePosy) == 1){

                    m_player->SaveGame();//Le Joueur sauve la partie

                }
            }
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
        m_player->setm_isAttack(true);
    }
}

