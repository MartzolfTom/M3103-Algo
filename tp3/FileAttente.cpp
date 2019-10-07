#include <iostream>
#include "FileAttente.hpp"
using namespace std;

FileAttente fileNouv()
{
  FileAttente file;

  file.tete = nullptr;
  file.queue = nullptr;

  return file;
}

void ajouterQueue(FileAttente& file, char personne[20])
{
  //on prepare un nouveau maillon a ajouter a notre file
  int i = 0;
  maillon *nouvMaillon;
  nouvMaillon = new maillon();

  //on rentre la chaine en entree dans le maillon en preparation
  while (personne[i] != '\0') {
    (*nouvMaillon).personne[i] = personne[i];
    i++;
  }
  (*nouvMaillon).personne[i] = '\0';

  //on attribue ce nouveau maillon a notre file
  (*nouvMaillon).suivant = nullptr;
  if (file.tete == nullptr)
  {
    file.tete = nouvMaillon;
    file.queue = nouvMaillon;
  }
  else
  {
    (*file.queue).suivant = nouvMaillon;
  }
  file.queue = nouvMaillon;
}

void retirerTete(FileAttente &file)
{
  if (file.tete == nullptr)
  {
    cout << "Il n'y a rien a supprimmer." << endl;
  }
  else
  {
    maillon *buffer;
    buffer = (*file.tete).suivant;
    delete file.tete;
    file.tete = buffer;
  }

  //si jamais la longueur ed la chaine est de 0 ou 1, alors la queue est la meme que la tete
  if (longueurFile(file) <= 1) {
    file.queue = file.tete;
  }
}

void ConsulterTeteFile(FileAttente file)
{
  if (file.tete == nullptr)
  {
    cout << "La file est vide." << endl;
  }
  else
  {
    cout << "Valeur de la tete de file : " << (*file.tete).personne << endl;
  }
}

int longueurFile(FileAttente file)
{
  maillon *maillon;
  int longueur = 0;
  maillon = file.tete;

  while (maillon != nullptr)
  {
    maillon = (*maillon).suivant;
    longueur++;
  }

  return longueur;
}
