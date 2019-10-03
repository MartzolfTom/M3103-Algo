#ifndef DECLARATION_H
#define DECLARATION_H

struct maillon
{
    int valeur;
    maillon *suivant;
};

struct FileAttente
{
    maillon *tete;
    maillon *queue;
};

FileAttente fileNouv();
void AjouterQueue(FileAttente& file,int valeur);
void retirerTete(FileAttente& file);

#endif