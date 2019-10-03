#include "declaration.h"
#include <iostream>
using namespace std;

FileAttente fileNouv(){

  FileAttente file;

  file.tete=NULL;
  file.queue=NULL;

  return file;
}

void AjouterQueue(FileAttente& file,int valeur){

maillon *nouvMaillon;

nouvMaillon= new maillon();

*nouvMaillon.valeur=valeur;
*nouvMaillon.suivant=NULL;
*file.queue=nouvMaillon;
file.queue=nouvMaillon;
}

void retirerFinQueue(FileAttente& file){
  maillon *buffer;

  buffer = new maillon();

  buffer = (*file.tete).suivant;
  free(file.tete);
  file.tete = buffer;
}

void numeroTeteFile(FileAttente file){
  cout << "valeur de la tete de file : " (*file.tete).valeur;
}
