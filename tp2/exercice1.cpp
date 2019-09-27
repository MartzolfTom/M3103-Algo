#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////
//Description : programme principal montrant le fonctionnement des
//pointeurs (exercice 2 tu TD 2)
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
  int i, j;
  int *p1, *p2;

  i=2; j=5;
  p1 = &i;
  cout << "contenu de p1 vaut : " << *p1 << "\n";
  i = i+1;
  cout << "contenu de p1 vaut : " << *p1 << "\n";
  p2=p1;
  *p2 = *p1+j;
  cout << "p1 vaut " << *p1 << " et p2 vaut : " << *p2 << "\ni vaut : " << i << " et j vaut " << j << "\n";
  p1=&j;
  *p1=i+j;
  cout << "p1 vaut " << *p1 << " et p2 vaut : " << *p2 << "\ni vaut : " << i << " et j vaut " << j;

  return 0;
}
