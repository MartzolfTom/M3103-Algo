#include <iostream>
using namespace std;



//////////////////////////////////////////////////////////////////
//Description : procédure de tri rapide récursive, triant un tableau d'entier
//
//Entrees : tableau d'entiers non trié, deux entier a et b correspondant
//            à la position du premier entier (low) et à celle du dernier (hight)
//
//Sorties : tableau d'entier trié
//
//Pre-Conditions : a et b < 0, a et b < taille du tableau, b>=a
//
//Post-Condition : aucune
//////////////////////////////////////////////////////////////////


void TriRapide( int tableau[], int a, int b ){
  int pivot;  // élément qui va servir de référence pour palcer avant ou après lui les différets éléments
  int i,j ; // pour parcourir le tableau
  int ip, jp; // pour l'écgande de valeurs
  int temp; // variable tampon pour l'échange

  if(a<b){
    i=a;
    j=b;
    pivot=tableau[((a+b)/2)];   // assignation du pivot
    while(i<=j){
      ip=i;
      while(tableau[ip]<pivot){   // boucle pour choisir l'élément situé avant le pivot
        ip=ip+1;
      }
      jp=j;
      while(tableau[jp]> pivot){  // boucle pour choisir l'élément situé après le pivot
        jp=jp-1;
      }
      if(ip<=jp){            // échange des éléments
        temp=tableau[ip];
        tableau[ip]=tableau[jp];
        tableau[jp]=temp;
        i=ip+1;
        j=jp-1;
      }
      else{
        i=ip;
        j=jp;
      }
    }
	TriRapide(tableau, a, j);
	TriRapide(tableau, i, b);
  }
}


int main(){

	int tableau[] = { 5,8,46,95,28,3,4,75,9,10 };
  cout<<"tableau sans tri : ";
  for(int i=0;i<10;i++){
    cout<<tableau[i]<<" ";
  }
  cout<<'\n';
TriRapide(tableau,0,9);

  cout<<"tableau avec tri : ";
for(int i=0;i<10;i++){
  cout<<tableau[i]<<" ";
}

}
