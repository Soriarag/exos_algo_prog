#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a, b) (a < b) ? b : a
#define POIDS_MAX 100
#define MAX_N 100
#define TRUE 1
#define FALSE 0

// ---------------- debut definition de liste -------------//
typedef char Noeud_data;

typedef struct t_Noeud
{
  struct t_Noeud *next;
  Noeud_data data;

} Noeud;

Noeud *nouveau_noeud(Noeud_data data)
{

  Noeud *ret = malloc(sizeof(Noeud));

  ret->next = NULL;
  ret->data = data;
}

// ---------------- fin definition de liste -------------//

typedef Noeud Result_list;
typedef struct
{
  int poids, valeur;
} Objet;

typedef struct
{

  int n_objets_pris_en_compte, valeur;
  Noeud *result_head;

} Resultat;

Resultat solutions_plus_optimale[POIDS_MAX];

// le raisonnonement est le suivant solutions_plus_optimale[poids][n_valeurs - k] = solutions_plus_optimale[poids][n_valeurs]

int solution(Objet *objets, int data_index, int data_size, int poids_restant)
{

  int n_objets = data_index - data_size;
  if (poids_restant < 0)
  {
    return 0;
  }

  else if (n_objets <= 0)
  {

    return 0;
  }
  else if (solutions_plus_optimale[poids_restant].n_objets_pris_en_compte < n_objets)
  {

    Objet obj = objets[data_index];

    solutions_plus_optimale[poids_restant].n_objets_pris_en_compte = n_objets;

    // si je laisse l'objet
    int pts_objet_laisse = solution(objets, data_index + 1, data_size, poids_restant);

    // si je prends l'objet
    int pts_objet_inclus = obj.valeur + solution(objets, data_index + 1, data_size, poids_restant - obj.poids);

    if (pts_objet_laisse < pts_objet_inclus)
    {
      Noeud *n_noeud = nouveau_noeud(pts_objet_inclus);
      n_noeud->next = solutions_plus_optimale[poids_restant].result_head;
      solutions_plus_optimale[poids_restant].result_head = n_noeud;
    }

    solutions_plus_optimale[poids_restant].valeur = max(pts_objet_laisse, pts_objet_inclus);

    return solutions_plus_optimale[poids_restant].valeur;
  }
  else
  {
    return solutions_plus_optimale[poids_restant].valeur;
  }
}

int main(int argc, char const *argv[])
{

  int n_obj;
  scanf("%d", n_obj);

  Objet objets[n_obj];
  for (int i = 0; i < n_obj; i++)
  {
    int poids, valeur;
    scanf("%d", objets[i].poids);
    scanf("%d", objets[i].valeur);
  }
}
