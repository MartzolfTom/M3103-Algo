#include <iostream>
#include "listeCirculaire.hpp"
using namespace std;

//////////////////////////////////////////////////////////////////
//Description : Fonction qui alloue la memoire d'une listeCirculaire
//
//Entrees : rien
//
//Sorties : retourne une variable de type listeCirulaire vide
//
//Pre-Conditions : aucune
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////
listeCirculaire init(){
//initialisation de la liste
  listeCirculaire *liste = new listeCirculaire();
  (*liste).tete = nullptr;

  return *liste;

}

//////////////////////////////////////////////////////////////////
//Description : consulte le contenu d'une listeCirculaire
//
//Entrees : variable de type listeCirculaire
//
//Sorties : rien
//
//Pre-Conditions : la liste ne doit pas être null
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////
void consulterChaine(listeCirculaire liste){
  if ( liste.tete == nullptr) {
    cout << endl<< "La liste est vide" << endl;
  }
  else{
    maillon *parcours = liste.tete;

    //on parcours toute la liste
    while ((*parcours).suivant != liste.tete) {
      cout << (*parcours).numero << " | ";
      parcours = (*parcours).suivant;
    }
    cout << (*parcours).numero << " |" << endl;
  }

}

//////////////////////////////////////////////////////////////////
//Description : Fonction qui supprime le maillon de tete d'une listeCirculaire
//              en libérant la mémoire
//Entrees : pointeur sur une listeCirculaire
//
//Sorties : listeCirculaire avec une longueur - 1 vis-à-vis de celle en entree
//
//Pre-Conditions : la liste ne doit pas être null
//
//Post-Condition : la listeCirculaire doit avoir diminué de 1 maillon
//////////////////////////////////////////////////////////////////
void retirerMaillonTete(listeCirculaire *liste){
  if ((*liste).tete == nullptr) {
    cout << "La liste est vide." << endl << endl;
  } else {
    //si il n'y a qu'un seul maillon dans la liste
    if (longueurListe((*liste), (*liste).tete) == 1) {
      delete (*liste).tete;
      (*liste).tete = nullptr;
    }
    //si il y a plus d'un maillon dans la liste
    else {
      //on se positionne sur le dernier maillon et sur le maillon suivant de la tete
      maillon *suivantTete = (*(*liste).tete).suivant;

      maillon *dernier = (*liste).tete;
      while ((*dernier).suivant != (*liste).tete) {
        dernier = (*dernier).suivant;
      }

      //on fait pointer notre nouveau maillon sur le suivant de la tete et on la redirige
      (*dernier).suivant = suivantTete;

      //on libere la memoire de la tete
      delete (*liste).tete;
      (*liste).tete = suivantTete;
    }
  }
}

//////////////////////////////////////////////////////////////////
//Description : fonction qui deplace la tete d'une listeCirculaire sur le
//              maillon suivant la tete
//Entrees : pointeur d'une listeCirculaire
//
//Sorties : modifie la tete d'une listeCirculaire
//
//Pre-Conditions : la liste ne doit pas être null
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////
void rotationCirculaire(listeCirculaire *liste){
  //lorsque la liste contient 0 ou 1 maillon, iln'y a pas de rotation a faire
  if ( longueurListe((*liste), (*liste).tete) <=1 ) {
    cout << "rotation impossible";
  }
  else {
    //on replace notre tete de file vers le suivant
    (*liste).tete = (*(*liste).tete).suivant;
  }
}

//////////////////////////////////////////////////////////////////
//Description : insere un maillon dans une listeCirculaire
//
//Entrees : pointeur d'une listeCirculaire et un entier a inserer
//
//Sorties : modifie une listeCirculaire en ajoutant un maillon dedans
//          avec une nouvelle valeur
//Pre-Conditions : la liste ne doit pas être null
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////
void insererMaillon(listeCirculaire *liste, int valeur){

  if ((*liste).tete == nullptr) {
    maillon *tete = new maillon();
    (*tete).numero = valeur;
    (*tete).suivant = tete;
    (*liste).tete = tete;
  }
  else {
    //preparation du nouveau maillon a inserer
    maillon *nouvMaillon = new maillon();
    (*nouvMaillon).numero = valeur;
    (*nouvMaillon).suivant = (*liste).tete;

    //on parcours la liste jusqu'à atteindre l'avant dernier de notre listeCirculaire
    maillon *dernier = (*liste).tete;
    while ((*dernier).suivant != (*liste).tete) {
      dernier = (*dernier).suivant;
    }

    //on met en place le nouveau maillon entre l'avant dernier et le premier, et on redirige la tete de file
    //vers ce nouveau maillon
    (*dernier).suivant = nouvMaillon;
    (*liste).tete = nouvMaillon;
  }

}


//////////////////////////////////////////////////////////////////
//Description : calcul la longueur de la liste
//
//Entrees : pointeur d'une listeCirculaire et le pointeur sur la tete de
//          la liste
//Retourne : un entier qui indique la longueur de la liste
//
//Pre-Conditions : la liste ne doit pas être null
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////
int longueurListe(listeCirculaire liste, maillon *maillon)
{
  // parcours de la liste
  if(liste.tete == nullptr){
    return 0;
  }
  else if ( (*maillon).suivant != liste.tete ) {
    return ( 1 + longueurListe(liste,(*maillon).suivant));
  }
  else{ return 1;}
}
