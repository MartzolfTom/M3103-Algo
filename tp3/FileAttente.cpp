#include <iostream>
#include "FileAttente.hpp"
using namespace std;

//////////////////////////////////////////////////////////////////
//Description : Fonction qui alloue la memoire d'une file d'attente
//
//Entrees : rien
//
//Sorties : retourne une variable de type FileAttente vide
//
//Pre-Conditions : aucune
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////

FileAttente fileNouv()
{
  FileAttente file;

  file.tete = nullptr;    // la file ne contient aucuns maillons, on initialise donc à 'null'
  file.queue = nullptr;

  return file;
}

//////////////////////////////////////////////////////////////////
//Description : procédure ajoutant un maillon contenant un tableau de caractère
//              à la fille d'attente en queue
//
//Entrees : variable de type FileAttente et tableau de caractère
//
//Sorties : variable de type FileAttente
//
//Pre-Conditions : le taleau de caractère ne doit pas excéder
//                 caractères
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////

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
  }
  else
  {
    (*file.queue).suivant = nouvMaillon;
  }
  file.queue = nouvMaillon;
}


//////////////////////////////////////////////////////////////////
//Description : procédure retirant le maillon en tête d'une fille d'attente
//
//Entrees : variable de type FileAttente
//
//Sorties : variable de type FileAttente
//
//Pre-Conditions :
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////

void retirerTete(FileAttente &file)
{
  if (file.tete == nullptr)    // cas où la file ne contient aucun maillons
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

  //si jamais la longueur ed la chaine est de 0 ou 1, alors la queue est la même que la tete
  if (longueurFile(file) <= 1) {
    file.queue = file.tete;
  }
}

//////////////////////////////////////////////////////////////////
//Description : procédure permettant de consulter le contenu
//              du maillon en tête de la file d'attente
//
//Entrees : variable de type FileAttente et tableau de caractère
//
//Sorties : variable de type FileAttente
//
//Pre-Conditions : le taleau de caractère ne doit pas excéder
//                 caractères
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////

void ConsulterTeteFile(FileAttente file)
{
  if (file.tete == nullptr)     // cas où la file ne contient aucun maillons
  {
    cout << "La file est vide." << endl;
  }
  else
  {         // affichage du contenu du maillon en tête de la file
    cout << "Valeur de la tete de file : " << (*file.tete).personne << endl;
  }
}

//////////////////////////////////////////////////////////////////
//Description : fonction retournant la nombre de maillon dans la file d'attente
//
//Entrees : variable de type FileAttente
//
//Sorties : entier ( nombre de maillon de la file)
//
//Pre-Conditions :
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////

int longueurFile(FileAttente file)
{
  maillon *maillon;
  int longueur = 0;
  maillon = file.tete;

  while (maillon != nullptr)   // boucle pour incrémenter le compteur du nombre de maillon
  {
    maillon = (*maillon).suivant;
    longueur++;
  }

  return longueur;
}
