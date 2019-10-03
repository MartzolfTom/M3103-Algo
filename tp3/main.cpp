#include "declaration.h"
#include <iostream>
using namespace std;

FileAttente fileNouv(){

  FileAttente file;

  (file).tete=nullptr;
  (file).queue=nullptr;

  return file;
}

void AjouterQueue(FileAttente& file,int valeur){

  maillon *nouvMaillon;

  nouvMaillon = new maillon();

  (*nouvMaillon).valeur=valeur;
  (*nouvMaillon).suivant=nullptr;
  if (file.tete == nullptr) {
    file.tete = nouvMaillon;
  }
  else {
    (*file.queue).suivant = nouvMaillon;
  }
  file.queue = nouvMaillon;
}

void retirerTete(FileAttente& file){
  if (file.tete == nullptr) {
    cout << "Il n'y a rien a supprimmer." << endl;
  }
  else {
    maillon *buffer;
    buffer = (*file.tete).suivant;
    delete file.tete;
    file.tete = buffer;
  }
}

void ConsulterTeteFile(FileAttente file){
  if (file.tete == nullptr) {
    cout << "La file est vide." << endl;
  }
  else{
    cout << "valeur de la tete de file : " << (*file.tete).valeur << endl;
  }
}

int longueurChaine(FileAttente file){
  maillon *maillon;
  int longueur = 0;
  maillon = file.tete;

  while (maillon != nullptr) {
    maillon = (*maillon).suivant;
    longueur++;
  }

  return longueur;
}
