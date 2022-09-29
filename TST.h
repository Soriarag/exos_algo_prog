#ifndef TST_H
#define TST_H

// implementation de ternary search tree
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

#endif