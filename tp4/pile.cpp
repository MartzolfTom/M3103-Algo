#include <iostream>
#include "pile.hpp"
#include "FileAttente.hpp"
using namespace std;

//////////////////////////////////////////////////////////////////
//Description : Fonction qui alloue la memoire d'une pile
//
//Entrees : rien
//
//Sorties : retourne une variable de type Pile vide
//
//Pre-Conditions : aucune
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////

Pile pileNouv(){   // attribution mémoire de la pile
  Pile pile;
  pile.maillonPile = nullptr;
  return pile;
}

//////////////////////////////////////////////////////////////////
//Description : procédure qui ajoute une fille d'attente au sommet d'une pile
//
//Entrees : 2 variables de types : pile et fileAttente
//
//Sorties : rien
//
//Pre-Conditions : aucune
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////

void empiler(Pile *pile, FileAttente file){
  MaillonPile *buffer;   // maillon récupérant l'ancienne valeur de la file
  FileAttente fileTemp;
  fileTemp = copieFile(file); // la file temporaire prend en valeur celle de la pile actuelle

  buffer = new MaillonPile();
  (*buffer).file = fileTemp; // affectation ancienne valeur file
  (*buffer).suivant = (*pile).maillonPile; // le maillon poite sur la nouvelle valeur de la pile

  (*pile).maillonPile = buffer;
}

//////////////////////////////////////////////////////////////////
//Description : procédure qui retire une fille d'attente au sommet d'une pile
//
//Entrees : 2 variables de types : pile et fileAttente
//
//Sorties : rien
//
//Pre-Conditions : aucune
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////

void depiler(Pile *pile, FileAttente *file){
  MaillonPile *buffer;
  buffer = (*pile).maillonPile;

  (*pile).maillonPile = (*buffer).suivant;  // contenu du sommet de la pile affécté au contenu du suivant
  delete buffer;     // libération de la mémoire
}

//////////////////////////////////////////////////////////////////
//Description : fonction qui copie dans une nouvelle file une autre file
//
//Entrees : 1 variable de type : fileAttente
//
//Sorties : 1 variable de type : fileAttente
//
//Pre-Conditions : aucune
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////

FileAttente copieFile(FileAttente file){
  //on va creer une nouvelle file qui contiendra les memes valeurs que celles passees en parametres, mais dont les adresses
  //memoires seront differentes
  FileAttente nouvelleFile;
  nouvelleFile = fileNouv();

  //si la file qu'on passe est vide, on renvoie une file vide
  if (file.tete == nullptr) {
    return nouvelleFile;
  }
  //sinon on copie les valeurs de la file dans la nouvelle
  else{
    //on va utiliser 2 maillon pour chacunes des files
    maillon *maillonFile = file.tete;
    //maillon *maillonNouvelleFile = nouvelleFile.tete;
    char personne[20];

    while((*maillonFile).suivant != nullptr){
      ajouterQueue(nouvelleFile, (*maillonFile).personne);
      maillonFile = (*maillonFile).suivant;
    }
    ajouterQueue(nouvelleFile, (*maillonFile).personne);

    return nouvelleFile;
  }
}

//////////////////////////////////////////////////////////////////
//Description : procédure qui annule la dernière action effectuer sur la file
//
//Entrees :  2 variables de types : pile et fileAttente
//
//Sorties : rien
//
//Pre-Conditions : aucune
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////

void undo(Pile *pile, FileAttente *file){
  *file = (*(*pile).maillonPile).file;
  cout << "Retour en arriere" << endl << endl;
}
