#include <iostream>
#include "FileAttente.hpp"
#include "pile.hpp"
using namespace std;

int main()
{
   int choix;      // variable pour le menu
   bool continuer; // variable pour la repetition du menu

   Pile pile;
   pile = pileNouv();
   FileAttente file = fileNouv();
   char personne[20];

   cout << "File d'attente";
   cout << endl
        << endl;

   continuer = true;

   while (continuer == true) {
      cout << "1 : Ajouter une personne en queue";
      cout << endl;
      cout << "2 : Retirer la personne en tete";
      cout << endl;
      cout << "3 : Consulter la personne en tete de file";
      cout << endl;
      cout << "4 : Calculer la longueur de la file d'attente";
      cout << endl;
      cout << "5 : Undo";
      cout << endl;
      cout << "6 : Quitter";
      cout << endl;

      cout << "saisir choix :";
      cin >> choix;
      switch (choix)
      { // structure selon affichant un menu pour le choix de l'exercice a execute
      //chaque choix appelle une procedure executant l'exercice en question
      // sauf le dernier choix permettant de quitter la structure selon
      case 1:
         cout << "saisir une chaine a ajouter en queue : ";
         cin >> personne;
         empiler(&pile, file);
         ajouterQueue(file, personne);
         break;
      case 2:
         empiler(&pile, file);
         retirerTete(file);
         break;
      case 3:
         ConsulterTeteFile(file);
         break;
      case 4:
         cout << "longueur de la chaine : " << longueurFile(file) << endl;
         break;
       case 5:
          undo(&pile, &file);
          depiler(&pile, &file);
          break;
      case 6:
         cout << "Au Revoir" << endl << "Liberation de la memoire..." << endl;
         while (file.tete != nullptr) {
           retirerTete(file);               // on libère la mémoire
         }
         cout << file.queue << " " << file.tete << endl;
         continuer = false;
         break;
      case 7:
         consulterFile(file);
         break;
      default:
         cout << "erreur";
         continuer = false;
         break;
      }
   }
   return 0;
}
