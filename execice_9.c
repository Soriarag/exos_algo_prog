#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//Correction exercice (pas de vidage de pile a la fin)

typedef struct t_Noeud
{
    struct t_Noeud *parent;
    char data;

} Noeud;

typedef struct
{
    Noeud* last;

} Pile;

void exit_false(){
    printf("Pas bien parenthese\n");
    exit(0);
}

char pop(Pile* p){

    Noeud *old = p->last;

    if (old == NULL)
    {
        exit_false();
    }
    
    char last_data = old->data;

    p->last = old->parent;

    free(old);

    return last_data;
}

void push(Pile *p, char c){

    Noeud *new_n = (Noeud * )malloc(sizeof(Noeud));
    new_n->data = c;
    new_n->parent = p->last;
    if (p->last == NULL)
    {
        p->last = new_n;
        return;
    }
    p->last = new_n;
}



int main(int argc, char const *argv[])
{

    char c;
    char last_c;
    size_t len = 0;
    FILE *f;
    f = fopen("/matieres/3MM1AP/09_dataset2.txt","r");

    Pile p;
    p.last = NULL;

    while(fscanf(f,"%c",&c) > -1){
        switch (c)
        {

            case '(':
            case '[':
            case '<':
            case '{':
                push(&p,c);
                break;

            case '}':
                last_c = pop(&p);
                if (last_c != '{') exit_false();
                break;

            case ')':
                last_c = pop(&p);
                if (last_c != '(') exit_false();
                break;

            case ']':
                last_c = pop(&p);
                if (last_c != '[') exit_false();
                break;

            case '>':
                last_c = pop(&p);
                if (last_c != '<') exit_false();
                break;

            default:
                break;
        }
    }

    fclose(f);

    if (p.last == NULL)
    {
        printf("bien parenthese");
    } else {
        exit_false();
    }

    return 0;
}
