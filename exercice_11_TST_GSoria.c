#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ------------------debut definition du ternary search tree------------------------
typedef struct t_Noeud
{
    char data;
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

// ------------------fin definition du ternary search tree------------------------

int main(int argc, char const *argv[])
{

    char *nom = NULL;
    size_t len;
    TST noms_vus;
    noms_vus.racine = NULL;

    FILE *f;
    f = fopen("/matieres/3MM1AP/11_names_big.txt","r");

    // on va creer un arbre de noms
    while (getline(&nom, &len, f) > 0)
    {
        int nouveau_mot = ajouter_mot(nom, &noms_vus);

        if (!nouveau_mot)
        {
            printf("%s", nom);
        }
    }

    fclose(f);
}

// ------------------debut implementation du ternary search tree------------------------

int ajouter_mot(char *debut_mot, TST *tst)
{
    // retourne 1 si on a reussi a ajouter le mot, sinon le mot existe deja
    return ajouter_caractere(debut_mot, &(tst->racine));
}

void detruire_TST(Noeud *racine){
    if (racine != NULL)
    {
        free(racine->superieur);
        free(racine->egale);
        free(racine->inferieur);
        free(racine);
    }
    
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
    else if (*noeud == NULL)
    {
        *noeud = nouveau_n();
        (*noeud)->data = c_mot;
        noeud = &((*noeud)->egale);
        ajouter_caractere(++car_it, noeud);
        return 1;
    }
    else if (c_mot == (*noeud)->data)
    {
        noeud = &((*noeud)->egale);
        return ajouter_caractere(++car_it, noeud);
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
