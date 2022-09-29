#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TST.h"

int ajouter_mot(char *debut_mot, TST *tst)
{
    // retourne 1 si on a reussi a ajouter le mot, sinon le mot existe deja
    return ajouter_caractere(debut_mot, &(tst->racine));
}

Noeud *nouveau_n()
{
    Noeud *new_n = (Noeud *)malloc(sizeof(Noeud));
    new_n->egale = NULL;
    new_n->superieur = NULL;
    new_n->inferieur = NULL;
    return new_n;
}

int ajouter_caractere(char *car_it, Noeud **noeud)
{
    // retourne 1 si on a reussi a ajouter le mot, sinon le mot existe deja
    char c_mot = *car_it;

    if (c_mot == '\0')
    {
        return 0;
    }
    else if (noeud == NULL)
    {
        *noeud = nouveau_n();
        (*noeud)->data = c_mot;
        noeud = &((*noeud)->egale);
        ajouter_caractere(car_it++, noeud);
        return 1;
    }
    else if (c_mot == (*noeud)->data)
    {
        noeud = &((*noeud)->egale);
        return ajouter_caractere(car_it++, noeud);
    }
    else if (c_mot < (*noeud)->data)
    {
        noeud = &((*noeud)->inferieur);
        return ajouter_caractere(car_it, noeud);
    }
    else
    {
        noeud = &((*noeud)->superieur);
        return ajouter_caractere(car_it, noeud);
    }

    return 0;
}
