#include "WindowsBeforeGame.h"

using namespace std;


/******IMPLEMENTATION DES ACCESSEURS******/
//null


/******IMPLEMENTATION DES MUTATEURS******/
//null



/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode draw de la Class WindowsBeforeGame permet de dessiner le menu qui s'affiche avant de commencer le Jeu.

@param: null
*/
void WindowsBeforeGame::draw() const {

    BlockNewGame buttonNewGame;
    buttonNewGame.draw();//Dessine le bouton qui sert a commencer une nouvelle partie.

    BlockLoadGame buttonLoadGame;
    buttonLoadGame.draw();//Dessine le bouton qui sert a loader une partie prealablement sauvee.

    BlockLevelJoueur buttonLevelJoueur;
    buttonLevelJoueur.draw();//Dessine le bouton qui sert a commencer une nouvelle partie sur un niveau exclusivement dedie et construit par le Joueur.

}
