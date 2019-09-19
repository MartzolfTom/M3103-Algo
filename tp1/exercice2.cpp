#include <iostream>
using namespace std;

///////////////////////////
///  fonction puissanceRecursive qui calcule la puissance a^n
///  de deux nombres entiers a et n de tel sorte que a^n/2
///  ne soit calculé qu'une seule fois
///
///  entrée : 2 entiers
///  sortie : un entier
/////////////////////////

int puissanceRecursive(int a,int n){

if(n==0 || a==1){
  return 0;
}

if ( n == 1){
  return a;
}

if(n%2==0){
  return  puissanceRecursive(a,n/2) * puissanceRecursive(a,n/2);
}
else{
  return a*puissanceRecursive(a,(n-1)/2) * puissanceRecursive(a,(n-1)/2);
}

}


///////////////////////////
///  fonction controleSup qui permet de saisir
///   un entier positif et de le controler
///
///  entrée : rien
///  sortie : un entier positif
/////////////////////////

int controleSup(){
  int n =0;
  cout<<"saisir valeur de n :";
  cin>>n;
  while(n<0){
    cout<<"erreur entier negatif re-saisir valeur de n :";
    cin>>n;
  }
  return n;
}
 
int main(){

  int n = 0 ;
  int a =0;

  cout<< "saisir valeur de a :";
  cin>>a;
  n=controlesup();
  cout<< endl << "Valeur de " << a<<"^" << n<< "  : " << puissanceRecursive(a,n);
return 0;

}
