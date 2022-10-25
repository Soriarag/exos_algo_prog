#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a, b) (a > b) ? a : b

int brute_force(char *chaine_1, char *chaine_2)
{
    if (*chaine_1 == '\n')
    {
        return 0; // deletions et correction pour le \n
    }
    else if (*chaine_2 == '\n')
    {
        return 0; // insertions et correction pour le \n
    }
    else if (*chaine_1 == *chaine_2)
    {
        return 1 + brute_force(chaine_1 + 1, chaine_2 + 1); // rien a faire
    }
    else
    {
        int chaine_1_advanced = brute_force(chaine_1 + 1, chaine_2);
        int chaine_2_advanced = brute_force(chaine_1, chaine_2 + 1);

        return max(chaine_1_advanced, chaine_2_advanced);
    }
}

int main(int argc, char const *argv[])
{

    char *mot_a = NULL;
    char *mot_b = NULL;
    size_t len = 0;

    getline(&mot_a, &len, stdin);
    getline(&mot_b, &len, stdin);

    printf("max sous seq = %d", brute_force(mot_a, mot_b));
}
