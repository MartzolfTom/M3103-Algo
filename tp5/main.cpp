#include <iostream>
#include "listeCirculaire.hpp"
using namespace std;

int main()
{
   int choix = 1;      // variable pour le menu

   listeCirculaire liste;
   liste = init();
   int valeur;

   cout << "Liste circulaire";
   cout << endl
        << endl;

   while (choix != 0) {
      cout << "0 : Quitter";
      cout << endl;
      cout << "1 : Ajouter un maillon";
      cout << endl;
      cout << "2 : Retirer dernier maillon";
      cout << endl;
      cout << "3 : Consulter la liste circulaire";
      cout << endl;
      cout << "4 : Calculer la longueur de la liste circulaire";
      cout << endl;

      cout << "saisir choix :";
      cin >> choix;
      switch (choix)
      { // structure selon affichant un menu pour le choix de l'exercice a execute
      //chaque choix appelle une procedure executant l'exercice en question
      // sauf le dernier choix permettant de quitter la structure selon
      case 1:{
         cout << "saisir valeur maillon a inserer  : ";
         cin >> valeur;
         insererMaillon(&liste, valeur);
       } break;
      case 2:
         retirerMaillonTete(&liste);
         break;
      case 3:
         consulterChaine(liste);
         break;
      case 4:
         cout <<endl<< "longueur de la liste : " << longueurListe(liste) << endl;
         break;
      default:
         cout << "erreur";
         choix = 0;
         break;
      }
   }
   return 0;
}
