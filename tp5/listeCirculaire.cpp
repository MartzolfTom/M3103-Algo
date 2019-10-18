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
    cout << (*parcours).numero << " |"<<endl;
  }

}

void rotationCirculaire(listeCirculaire *liste){
  //on replace notre tete de file vers le suivant
  (*liste).tete = (*(*liste).tete).suivant;
}

void insererMaillon(listeCirculaire *liste, int entier){

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

int longueurListe(listeCirculaire liste)
{
  maillon *maillon;
  int longueur = 0;
  maillon = liste.tete;
 // parcours de la liste
  if (liste.tete != nullptr) {
    while ((*maillon).suivant != liste.tete) {
      maillon = (*maillon).suivant;
      longueur++;
    }
    longueur++;
  }

  return longueur;
}
