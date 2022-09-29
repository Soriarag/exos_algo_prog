#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ------------------debut definition du ternary search tree modifie------------------------
typedef struct t_Noeud
{
    char data;
    int count;
    struct t_Noeud *inferieur;
    struct t_Noeud *superieur;
    struct t_Noeud *egale;

} Noeud;

typedef struct TST
{
    Noeud *racine;

} TST;

int ajouter_mot(char *debut_mot, TST *tst);
int ajouter_caractere(char *car_it, Noeud **noeud);
int rechercher_max(Noeud *racine);

// ------------------fin definition du ternary search tree modifie------------------------

int MAX_FREQ = 0;

int main(int argc, char const *argv[])
{

    char nom[500];
    size_t len;
    TST noms_vus;
    noms_vus.racine = NULL;

    FILE *f;
    f = fopen("/matieres/3MM1AP/12_pride_nopunct.txt", "r");

    // on va creer un arbre de noms
    while (fscanf(f, "%s", nom) > -1)
    {

        if (strlen(nom) >= 6)
        {

            ajouter_mot(nom, &noms_vus);
        }
    }

    rechercher_max(noms_vus.racine);

    fclose(f);
}

// ------------------debut implementation du ternary searc* code */

Noeud *nouveau_noeud()
{
    Noeud *new_n = (Noeud *)malloc(sizeof(Noeud));
    new_n->egale = NULL;
    new_n->superieur = NULL;
    new_n->inferieur = NULL;
    new_n->count = 0;
    return new_n;
}

int ajouter_mot(char *debut_mot, TST *tst)
{
    // retourne 1 si on a reussi a ajouter le mot, sinon le mot existe deja
    if (*debut_mot != '\0')
    {
        return ajouter_caractere(debut_mot, &(tst->racine));
    }

    return 1;
}

int rechercher_max(Noeud *racine)
{
    // retourne 1 si c'est le max

    if (racine == NULL)
    {
        return 0;
    }

    else if (rechercher_max(racine->egale))
    {
        printf("%c", racine->data);
        return 1;
    }
    else if (rechercher_max(racine->inferieur) || rechercher_max(racine->superieur))
    {
        return 1;
    }
    else
    {
        if (racine->count >= MAX_FREQ)
        {
            printf("%c", racine->data);
            return 1;
        }
        return 0;
    }
}

int ajouter_caractere(char *car_it, Noeud **noeud)
{
    // retourne 1 si on a reussi a ajouter le mot, sinon le mot existe deja
    char c_mot = *car_it;

    if (*noeud == NULL)
    {
        *noeud = nouveau_noeud();
        (*noeud)->data = c_mot;

        ++car_it;
        if (*car_it == '\0')
        {
            (*noeud)->count++;
            if ((*noeud)->count > MAX_FREQ)
            {
                MAX_FREQ = (*noeud)->count;
            }
            return 1;
        }

        noeud = &((*noeud)->egale);
        ajouter_caractere(car_it, noeud);
        return 1;
    }
    else if (c_mot == (*noeud)->data)
    {
        
        ++car_it;
        if (*car_it == '\0')
        {
            (*noeud)->count++;
            if ((*noeud)->count > MAX_FREQ)
            {
                MAX_FREQ = (*noeud)->count;
            }
            return 1;
        }

        noeud = &((*noeud)->egale);
        return ajouter_caractere(car_it, noeud);
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

// ------------------fin implementation du ternary search tree------------------------
