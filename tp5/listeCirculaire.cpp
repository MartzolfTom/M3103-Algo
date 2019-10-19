#include <iostream>
#include "listeCirculaire.hpp"
using namespace std;


listeCirculaire init(){
//initialisation de la liste
  listeCirculaire *liste = new listeCirculaire();
  (*liste).tete = nullptr;

  return *liste;

}

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

void retirerMaillonTete(listeCirculaire *liste){
  if ((*liste).tete == nullptr) {
    cout << "La liste est vide." << endl << endl;
  } else {

    //on se positionne sur le dernier maillon et sur le maillon suivant de la tete
    maillon *suivantTete = (*(*liste).tete).suivant;

    maillon *dernier = (*liste).tete;
    while ((*dernier).suivant != (*liste).tete) {
      dernier = (*dernier).suivant;
    }

    //on fait pointer notre nouveau maillon sur le suivant de la tete
    (*dernier).suivant = suivantTete;

    //on libere la memoire de la tete
    delete (*liste).tete;

    //si il existe un suivant on fait pointer notre tete sur notre nouvelle tete
    if (suivantTete == nullptr) {
      (*liste).tete = suivantTete;
    }
    else {
      (*liste).tete = nullptr;
    }

  }
}

void rotationCirculaire(listeCirculaire *liste){
  //on replace notre tete de file vers le suivant
  (*liste).tete = (*(*liste).tete).suivant;
}

void insererMaillon(listeCirculaire *liste, int valeur){

  if ((*liste).tete == nullptr) {
    maillon *tete = new maillon();
    (*tete).numero = entier;
    (*tete).suivant = tete;
    (*liste).tete = tete;
  }
  else {
    //preparation du nouveau maillon a inserer
    maillon *nouvMaillon = new maillon();
    (*nouvMaillon).numero = entier;
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
