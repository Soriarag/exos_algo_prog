#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct t_Noeud
{
    struct t_Noeud *parent;

} Noeud;


typedef struct
{
    /* data */
} Pile;


int check_parentheses(char **it, char parenthese)
{

    int ret = TRUE;

    while (TRUE)
    {
        if (**it == parenthese)
        {
            (*it)++;
            return ret;
        }

        switch (**it)
        {

        case '(':
            (*it)++;
            ret &= check_parentheses(it, ')');
            break;

        case '[':
            (*it)++;
            ret &= check_parentheses(it, ']');
            break;

        case '<':
            (*it)++;
            ret &= check_parentheses(it, '>');
            break;

        case '{':
            (*it)++;
            ret &= check_parentheses(it, '}');
            break;

        // usually none of them will be amongst the right ones since the ones we where looking for where checked
        case '}':
        case ')':
        case ']':
        case '>':
        case '\n':
        case '\0':
            return FALSE;
            break;

        default:
            (*it)++;
            break;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{

    char *mot;
    size_t len = 0;
    while (getline(&mot, &len, stdin) > -1)
    {

        if (check_parentheses(&mot, '\n') == TRUE){
            printf("bien parenthese\n");
        }
        else{
            printf("pas bien\n");
        }
    }

    return 0;
}
