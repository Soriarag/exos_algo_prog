#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a, b) (a < b) ? a : b
#define MAXSIZE 100

int dp[MAXSIZE][MAXSIZE];

int memoization(char *chaine_1, char *chaine_2, int index_1, int index_2)
{

    if (dp[index_1][index_2] == -1)
    {

        if (chaine_1[index_1] == '\n')
        {
            dp[index_1][index_2] = strlen(chaine_2) - index_2; // deletions
        }
        else if (chaine_2[index_2] == '\n')
        {
            dp[index_1][index_2] = strlen(chaine_1) - index_1; // insertions
        }
        else if (chaine_1[index_1] == chaine_2[index_2])
        {
            dp[index_1][index_2] = memoization(chaine_1, chaine_2, index_1 + 1, index_2 + 1); // rien a faire
        }
        else
        {
            int insertion = 1 + memoization(chaine_1, chaine_2, index_1 + 1, index_2);
            int deletion = 1 + memoization(chaine_1, chaine_2, index_1, index_2 + 1);
            int modification = 1 + memoization(chaine_1, chaine_2, index_1 + 1, index_2 + 1);

            dp[index_1][index_2] = min(min(insertion, deletion), modification);
        }
    }
    return dp[index_1][index_2];
}

int main(int argc, char const *argv[])
{

    char *mot_a = NULL;
    char *mot_b = NULL;
    size_t len = 0;

    getline(&mot_a, &len, stdin);
    getline(&mot_b, &len, stdin);

    for (int i = 0; i < MAXSIZE; i++)
    {
        for (int j = 0; j < MAXSIZE; j++)
        {
            dp[i][j] = -1;
        }
        
    }
    

    printf("minimal modifications = %d", memoization(mot_a, mot_b, 0, 0));
}
