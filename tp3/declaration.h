#pragma once

struct FileAttente
{
    maillon *tete;
    maillon *queue;
};

struct maillon
{
    int valeur;
    maillon *suivant;
};
