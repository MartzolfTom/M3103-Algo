#include <iostream>
using namespace std;

///////////////////////////
///  fonction controleSup qui permet de saisir
///   un entier positif et de le controler
///
///  entrée : rien
///  sortie : un entier positif
/////////////////////////
int controleSup(){
  int n = 0;
  cin>>n;
  while(n<0){
    cout<<"erreur entier negatif re-saisir valeur de n :";
    cin>>n;
  }
  return n;
}

//////////////////////////////////////////////////////////////////
//Description : retourne la somme des premiers entiers pour un certain chiffre
//
//Entrees : le nombre d'entiers premiers a additionner
//
//Sorties : la somme des premiers entiers
//
//Pre-Conditions : l'entier en entree ne doit pas etre negatif
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////
int sommePremiers(int n){
  if (n > 0) {
    return n + sommePremiers(n - 1);
  }
}

//////////////////////////////////////////////////////////////////
//Description : programme principal ou l'utilisateur rentre un entier
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
      int n = 0 ;

      cout << "Rentrer un entier : ";
      n = controleSup();
      cout<< endl << "somme des " << n <<" premiers entiers : " << sommePremiers(n);
return 0;
}

/*
Condition d'arret :
Quand n <= 0
Recursivité :
sommePremiers(n) = n + sommePremiers(n-1) tant que n>0
*/
