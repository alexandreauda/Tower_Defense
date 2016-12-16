#pragma once
#include "Grille.h"
#include "LibMatrix.h"


class Joueur{

private:

    /******ATTRIBUT******/
    int m_vie;
    int m_argent;
    int m_level;
    int m_numberMonstreKilled;
    int m_score;
    int m_isAttack;
    bool m_isInGame;


public:

    /******CONSTRUCTEUR A PARAMETRES******/
    Joueur(int vie=LibMatrix::loadIntInFile("Fichier_Configuration/InitialLifePlayer.txt"), int argent=LibMatrix::loadIntInFile("Fichier_Configuration/InitialMoneyPlayer.txt"), int level=1, int numberMonstreKilled=0, int score=0): m_vie(vie), m_argent(argent), m_level(level), m_numberMonstreKilled(numberMonstreKilled), m_score(score), m_isAttack(0), m_isInGame(false){
    }


    /******ACCESSEURS******/
    int getm_vie() const;//Accesseur de l'attribut m_vie

    int getm_argent() const;//Accesseur de l'attribut m_argent

    int getm_level() const;//Accesseur de l'attribut m_level

    int getm_score() const;//Accesseur de l'attribut m_score

    int getm_isAttack() const;//Accesseur de l'attribut m_isAttack

    bool getm_isInGame() const;//Accesseur de l'attribut m_isInGame

    /******MUTATEURS******/
    void setm_vie(int const& vie);//Setteur de l'attribut m_vie

    void setm_argent(int const& argent);//Setteur de l'attribut m_argent

    void setm_level(int const& level);//Setteur de l'attribut m_level

    void setm_score(int const& score);//Setteur de l'attribut m_score

    void setm_isAttack(bool const& attack);//Setteur de l'attribut m_isAttack

    void setm_isInGame(bool const& newBool);//Setteur de l'attribut m_isInGame


    /******PROTOTYPES DES METHODES******/
    void drawAttribut() const;

    void receiveDamage(int const& damage);

    void spendMoney(int const& cost);

    void earnMoney(int const& gain);

    void oneMoreKilled();//Incremente l'attribut m_numberMonstreKilled

    void increaseLevel();//Incremente l'attribut m_level

    void decreaseLevel();//Decremente l'attribut m_level

    void increaseScore(int const& award);//Augmente l'attribut m_score d'une valeur egale a la valeur du int pris en parametre

    int isDead() const;//Renvoie 1 si la vie du Joueur est egale a 0 et 0 sinon

    void gameOver() const;

    int haveMoneyEnough(int const& cost) const;//Renvoie 1 si le Joueur a assez d'argent pour payer le cout pris en parametre et 0 sinon. Ainsi, si m_money-cost>=0 alors on renvoie 1 et 0 sinon.

    void LoadGame(std::string const& stringNameDirectory="SlotDataBackup/");

    void SaveGame(std::string const& stringNameDirectory="SlotDataBackup/") const;

};
