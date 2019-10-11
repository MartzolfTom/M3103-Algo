#include <iostream>
#include "FileAttente.hpp"
using namespace std;

int main() {
  FileAttente file1;
  FileAttente file2;
  char personne[] = "coucou";
  char personne2[] = "coucou 2";
  file1 = fileNouv();
  ajouterQueue(file1, personne);
  file2 = file1;
  ajouterQueue(file2, personne2);

  consulterFile(file1);
  consulterFile(file2);

  char a[] = "aba";
  char b[6] = a;
  b = "abobi";
  cout << a;
  return 0;
}
