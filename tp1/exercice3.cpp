#include <iostream>
using namespace std;

///////////////////////////
///  fonction SaisieEntierPositif qui permet de saisir
///   un entier positif et de le controler
///
///  entrée : rien
///  sortie : un entier positif
/////////////////////////
int SaisieEntierPositif(){
  int n = 0;
  cin>>n;
  while(n<0){
    cout<<"erreur entier negatif re-saisir valeur de n :";
    cin>>n;
  }
  return n;
}

//////////////////////////////////////////////////////////////////
//Description : retourne le PGCD des deux entiers pris en entrees
//
//Entrees : deux entiers quelconque
//
//Sorties : le PGCD de deux entiers
//
//Pre-Conditions : les entiers en entrees ne sont pas negatif
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////
int PGCD(int a, int b){
  if (a>b) {
    PGCD(a-b, b);
  } else if (a<b){
    PGCD(a, b-a);
  }
  else {
    return a;
  }
}

//////////////////////////////////////////////////////////////////
//Description : programme principal ou l'utilisateur rentre ses deux entiers
//
//Entrees : rien
//
//Sorties : rien
//
//Pre-Conditions : Aucune
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////
int main(){
  int a, b, resultat;
  a = 0;
  b = 0;

  cout << "Rentrer le premier chiffre : ";
  a = SaisieEntierPositif();
  cout << "Rentrer le second chiffre : ";
  b = SaisieEntierPositif();

  resultat = PGCD(a,b);
  cout << "voici le PGCD de " << a << " et " << b << " : " << resultat;
  return 0;
}

/*
condition d'arret :
Si a = b on retourne a ou b
Relation de récurrence :
PGCD(a,b) = PGCD(a-b, b) si a>b sinon si a<b PGCD(a,b) = PGCD(a, b-a)
*/
