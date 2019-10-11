#include <iostream>
#include "pile.hpp"
#include "FileAttente.hpp"
using namespace std;

Pile pileNouv(){
  Pile pile;
  pile.maillonPile = nullptr;
  return pile;
}

void empiler(Pile *pile, FileAttente file){
  MaillonPile *buffer;
  FileAttente fileTemp;
  fileTemp = copieFile(file);

  buffer = new MaillonPile();
  (*buffer).file = fileTemp;
  (*buffer).suivant = (*pile).maillonPile;

  (*pile).maillonPile = buffer;
}

void depiler(Pile *pile, FileAttente *file){
  MaillonPile *buffer;
  buffer = (*pile).maillonPile;

  (*pile).maillonPile = (*buffer).suivant;
  delete buffer;
}

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

void undo(Pile *pile, FileAttente *file){
  *file = (*(*pile).maillonPile).file;
  cout << "Retour en arriere" << endl << endl;
}
