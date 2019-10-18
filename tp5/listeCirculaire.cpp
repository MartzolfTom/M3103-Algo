#include <iostream>
#include "listeCirculaire.hpp"
using namespace std;


listeCirculaire init(){

  listeCirculaire liste;
  liste.tete = nullptr;

  return liste;

}

void consulterChaine(listeCirculaire liste){
  maillon *parcours = liste.tete;

  //on parcours toute la liste
  while ((*parcours).suivant != liste.tete) {
    cout << (*parcours).numero << " | ";
    parcours = (*parcours).suivant;
  }
  cout << (*parcours).numero << " |" << endl;
}

void rotationCirculaire(listeCirculaire *liste){
  //on replace notre tete de file vers le suivant
  (*liste).tete = (*(*liste).tete).suivant;
}

void insererMaillon(listeCirculaire *liste, int entier){
  //preparation du nouveau maillon a inserer
  maillon *nouvMaillon;
  (*nouvMaillon).numero = entier;
  (*nouvMaillon).suivant = (*liste).tete;

  //on parcours la liste jusqu'à atteindre l'avant dernier de notre listeCirculaire
  maillon *avantDernier;
  while ((*avantDernier).suivant != (*liste).tete) {
    avantDernier = (*avantDernier).suivant;
  }

  //on met en place le nouveau maillon entre l'avant dernier et le premier, et on redirige la tete de file
  //vers ce nouveau maillon
  (*avantDernier).suivant = nouvMaillon;
  (*liste).tete = nouvMaillon;

}

int longueurListe(listeCirculaire liste)
{
  maillon *maillon;
  int longueur = 0;
  maillon = liste.tete;

  while ((*maillon).suivant != liste.tete) {
    maillon = (*maillon).suivant;
    longueur++;
  }

  return longueur;
}
