#include<iostream>
#include "declaration.h"
using namespace std;

int main()

{
 int choix;    // variable pour le menu
 bool continuer; // variable pour la repetition du menu
 FileAttente file=fileNouv();
 int x=5;

 cout << "File d'attente";
 cout << endl<<endl<<endl;

 continuer = true;

 while (continuer == true)
 {
   cout << "1 : Ajouter une personne en queue";
   cout << endl;
   cout << "2 : Retirer la personne en tete";
   cout << endl;
   cout << "3 : Consulter la personne en tete de file";
   cout << endl;
   cout << "4 : Calculer la longueur de la file d'attente";
   cout << endl;
   cout << "5 : Quitter";
   cout << endl;

   cout << "saisir choix :";
   cin >> choix;
   switch (choix)   // structure selon affichant un menu pour le choix de l'exercice a execute
   {                // chaque choix appelle une procedure executant l'exercice en question
            // sauf le dernier choix permettant de quitter la structure selon
   case 1: AjouterQueue(file,x);
     break;
   case 2:  //exo2();
     break;
   case 3: // exo3()
     break;
   case 4:
   // bite
     break;
   case 5: cout << "au revoir";
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
