#ifndef FILEATTENTE_HPP
#define FILEATTENTE_HPP

// structures

struct maillon
{
    char personne[20];
    maillon *suivant;
};

struct FileAttente
{
    maillon *tete;
    maillon *queue;
};

// fonctions et procédures

FileAttente fileNouv();
void ajouterQueue(FileAttente& file, char personne[20]);
void retirerTete(FileAttente& file);
void ConsulterTeteFile(FileAttente file);
int longueurFile(FileAttente file);

#endif
