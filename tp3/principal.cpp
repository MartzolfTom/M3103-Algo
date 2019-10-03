#include<iostream>
#include "declaration.h"
using namespace std;

int main()

{
 int choix;    // variable pour le menu
 bool continuer; // variable pour la repetition du menu




 continuer = true;

 while (continuer == true)
 {
   cout << "1 : exercice 1";
   cout << endl;
   cout << "2 : exercice 2";
   cout << endl;
   cout << "3 : exercice 3";
   cout << endl;
   cout << "4 : quitter";
   cout << endl;

   cout << "saisir choix :";
   cin >> choix;
   switch (choix)   // structure selon affichant un menu pour le choix de l'exercice a execute
   {                // chaque choix appelle une procedure executant l'exercice en question
            // sauf le dernier choix permettant de quitter la structure selon
   case 1: // exo1()
     break;
   case 2:  exo2();
     break;
   case 3: // exo3()
     break;
   case 4: cout << "au revoir";
     continuer = false;
     break;
   default: cout << "erreur ";
          continuer = false;
   }
   system("cls");

 }
 system("pause");
 return 0;

}
