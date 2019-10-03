#include "declaration.h"

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
