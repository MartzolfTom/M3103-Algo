#pragma once

struct FileAttente
{
    maillon *tete;
    maillon *queue;
};

struct maillon
{
    int numero;
    maillon *suivant;
};
