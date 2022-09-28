#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct t_Noeud
{
    struct t_Noeud *next;
    char data;

} Noeud;

typedef struct
{
    Noeud* head;
    Noeud* last;

} List;

void initialize_list(List *l){
    l->head = NULL;
    l->last = NULL;
}


void push(List *l, int i){

    Noeud *new_n = (Noeud * )malloc(sizeof(Noeud));
    new_n->data = i;

    if (l->last == NULL)
    {
        l->head = new_n;
        l->last = new_n;
    }else
    {
        l->last->next = new_n;
        l->last = new_n;
    }   
}
    

    
void viruz(Noeud n, int counter, int k){
    if (counter == 1){
        // make n disappear

    }
}


int main(int argc, char const *argv[])
{

    List joueurs;

    initialize_list(&joueurs);

    int n = 10;
    for (int i = 0; i < 100; i++)
    {
        push(&joueurs, i);
        joueurs.last->next = joueurs.head;
    }

    int counter = n;

    Noeud *last = joueurs.head;
    Noeud *new_n = joueurs.head;
    while (new_n->next != new_n)
    {
        
        
        if (counter == 1){
            printf("%d\n",new_n->data);
            last->next = new_n->next;
            free(new_n);
            counter = n;
        }

        counter --;
        last = new_n;
        new_n = new_n->next;
        
    }
    
    if (n != 0)
    {
         printf("%d\n",new_n->data);
    }
   

    return 0;
}
