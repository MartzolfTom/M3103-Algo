#include <iostream>
#include "listeCirculaire.hpp"
using namespace std;

int main()
{
   int choix;      // variable pour le menu
   bool continuer; // variable pour la repetition du menu


   listeCirculaire liste;
   liste = init();
   int valeur;


   cout << "Liste circulaire";
   cout << endl
        << endl;

   continuer = true;

   while (continuer == true) {
      cout << "1 : Ajouter un maillon";
      cout << endl;
      cout << "2 : Retirer dernier maillon";
      cout << endl;
      cout << "3 : Consulter la liste circulaire";
      cout << endl;
      cout << "4 : Calculer la longueur de la liste circulaire";
      cout << endl;
      cout << "5 : Quitter";
      cout << endl;

      cout << "saisir choix :";
      cin >> choix;
      switch (choix)
      { // structure selon affichant un menu pour le choix de l'exercice a execute
      //chaque choix appelle une procedure executant l'exercice en question
      // sauf le dernier choix permettant de quitter la structure selon
      case 1:
         cout << "saisir valeur maillon a inserer  : ";
         cin >> valeur;
         insererMaillon(&liste, valeur);
         break;
      case 2:
      /*
         empiler(&pile, file);
         retirerTete(file);*/
         break;
      case 3:
         consulterChaine(liste);
         break;
      case 4:
         cout << "longueur de la liste : " << longueurListe(liste) << endl;
         break;
      case 5:
        cout << "Au Revoir" << endl << "Liberation de la memoire..." << endl;
      /*  while (liste.tete != nullptr) {
          ret(file);               // on libère la mémoire
        }
        cout << file.queue << " " << file.tete << endl;*/
        continuer = false;
        break;
      default:
         cout << "erreur";
         continuer = false;
         break;
      }
   }
   return 0;
}
