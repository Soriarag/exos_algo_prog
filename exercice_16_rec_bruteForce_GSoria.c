#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a,b) (a < b)?a:b

int brute_force(char *chaine_1, char *chaine_2){
    if (*chaine_1 == '\n')
    {
        return strlen(chaine_2) - 1 ; // deletions et correction pour le \n
    }else if (*chaine_2 == '\n')
    {
        return strlen(chaine_1) - 1; // insertions et correction pour le \n
    }
    else if (*chaine_1 == *chaine_2){
        return brute_force(chaine_1 + 1, chaine_2 + 1); //rien a faire 
    }
    else
    {
        int insertion = 1 + brute_force(chaine_1 + 1, chaine_2);
        int deletion = 1 + brute_force(chaine_1, chaine_2 + 1);
        int modification = 1 + brute_force(chaine_1 + 1, chaine_2 + 1);

        return min(min(insertion,deletion), modification);
    }
    
}

int main(int argc, char const *argv[])
{

    char *mot_a = NULL;
    char *mot_b = NULL;
    size_t len = 0;

    getline(&mot_a, &len, stdin);
    getline(&mot_b, &len, stdin);
    
    printf("minimal modifications = %d", brute_force(mot_a, mot_b));

}
