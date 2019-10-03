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

nouvMaillon= new maillon();

(*nouvMaillon).valeur=valeur;
(*nouvMaillon).suivant=nullptr;
(file).queue=nouvMaillon;
}

void retirerFinQueue(FileAttente& file){
  maillon *buffer;

  buffer = new maillon();

  buffer = (*file.tete).suivant;
  free(file.tete);
  file.tete = buffer;
}
/*
void numeroTeteFile(FileAttente file){
  cout << "valeur de la tete de file : " (*file.tete).valeur;
}*/
