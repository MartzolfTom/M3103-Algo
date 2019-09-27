#include <iostream>
using namespace std;

void TriRapide( int tableau[], int a, int b ){
  int pivot;
  int i,j ; // pour parcourir le tableau
  int ip, jp; // pour l'écgande de valeurs
  int temp; // variable tampon pour l'échange

  if(a<b){
    i=a;
    j=b;
    pivot=tableau[((a+b)/2)];
    while(i<=j){
      ip=i;
      while(tableau[ip]<pivot){
        ip=ip+1;
      }
      jp=j;
      while(tableau[jp]> pivot){
        jp=jp-1;
      }
      if(ip<=jp){
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
