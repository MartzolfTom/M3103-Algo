#include <iostream>
#include <stdio.h>
using namespace std;

/*int main() {
  int tab[5];
  int *p1, *p2;
  char str[20];
  char *c;

  tab[0] = 5;
  cout << "tab[2] vaut " << tab[2];
  p1 = tab+1;
  *p1 = 10;
  *p2 = 20; // on ne peut pas affecter une valeur au contenu d'un pointeur qui n'est pas initialisé au préalable
  //Attention ! Le compileur autorise cette pratique !!
  p2=p1;
  cout<<"p1 vaut " << *p1 << " et p2 vaut " << *p2;
  tab=p1+1; //on ne peut pas deplacer le debut d'un tableau quel qu'il soit d'une ou plusieurs cases, car sinon l'on perd
  //le debut du tableau
  c = tab+3; //erreurs de types, c est de type char et str de type int et on ne peut travailler sur deux pointeurs differents
  gets(str); //mauvaise fonction opur la saisie de str
  c = str+2;
  c = c+1;
  cout << "caractère " << *(c+1);
  gets(c);  //mauvaise fonction opur la saisie de c
  cout<<"chaine " << str;

  return 0;
}*/

//////////////////////////////////////////////////////////////////
//Description : programme principal montrant le fonctionnement des
//pointeurs (exercice 4 tu TD 2)
//
//Entrees : rien
//
//Sorties : rien
//
//Pre-Conditions : aucune
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////
int main() {
  int tab[5];
  int *p1, *p2;
  char str[20];
  char *c;

  tab[0] = 5;
  cout << "tab[2] vaut " << tab[2] << "\n";
  p1 = tab+1;
  *p1 = 10;
  p2 = new int; //on initialise au prealable le pointeur p2
  *p2 = 20;
  p2=p1;
  cout<<"p1 vaut " << *p1 << " et p2 vaut " << *p2;
  //tab=p1+1; on enlevec cette operation
  //c = tab+3; on enleve cette operation
  cin >> str;
  c = str+2;
  c = c+1;
  cout << "caractère " << *(c+1);
  cin >> c;
  cout<<"chaine " << str;

  return 0;
}
