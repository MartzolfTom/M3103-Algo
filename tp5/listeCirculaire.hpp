#ifndef LISTECIRCULAIRE_HPP
#define LISTECIRCULAIRE_HPP

struct maillon{
  int numero;
  maillon *suivant;
};

struct listeCirculaire{
  maillon *tete;
};

listeCirculaire init();
void consulterChaine(listeCirculaire liste);
void rotationCirculaire(listeCirculaire *liste);
void insererMaillon(listeCirculaire *liste, int valeur);
void retirerMaillonTete(listeCirculaire *liste);
int longueurListe(listeCirculaire liste, maillon *maillon);

#endif
