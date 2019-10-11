#ifndef PILE_HPP
#define PILE_HPP
#include <iostream>
#include "FileAttente.hpp"

struct MaillonPile{
  FileAttente file;
  MaillonPile *suivant;
};

struct Pile{
  MaillonPile *maillonPile;
};

Pile pileNouv();
void depiler(Pile *pile, FileAttente *file);
void empiler(Pile *pile, FileAttente file);
void undo(Pile *pile, FileAttente *file);
FileAttente copieFile(FileAttente file);

#endif
