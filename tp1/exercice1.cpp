#include <iostream>
using namespace std;

int sommePremiers(int n){
  int somme=0;
  for(int i =0; i<n ;i++){
    somme=somme+i;
  }
  return somme;
}

int main(){

      int n = 0 ;

      cout<< "saisir valeur de n :";
      cin>>n;
      cout<< endl << "somme des " << n <<" premiers entiers : " << sommePremiers(n);
return 0;
}
