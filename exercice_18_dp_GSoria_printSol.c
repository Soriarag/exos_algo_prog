#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a, b) (a > b) ? a : b


typedef struct sol{

    int size;
    char val;
    struct sol *antecedent;

}Solution;

void print_sol(Solution *s){

    if (s->size > 0 )
    {
        print_sol(s->antecedent);
        printf("%c", s->val);
    }
   
}

int dp(char *chaine_1, int len_chaine_1, char *chaine_2, int len_chaine_2)
{
    // dp[A][B] representes la sous chaine la plus large charge qu'on prend A caracteres de
    // chaine 1 et B caracteres de chaine
    Solution dp[len_chaine_1 + 1][len_chaine_2 + 1];
    for (int i = 0; i <= len_chaine_1 ; i++)
    {
        dp[i][0].size = 0;
        dp[i][0].val = '\0';
    }
    
    for (int i = 0; i <= len_chaine_2 ; i++)
    {
        dp[0][i].size = 0;
        dp[0][i].val = '\0';
    }

    for (int n_caracs_c1 = 1; n_caracs_c1 <= len_chaine_1; n_caracs_c1++)
    {
        for (int n_caracs_c2 = 1; n_caracs_c2 <= len_chaine_2; n_caracs_c2++)
        {
            if (chaine_1[n_caracs_c1 - 1] == chaine_2[n_caracs_c2 - 1])
            {
                dp[n_caracs_c1][n_caracs_c2].val = chaine_1[n_caracs_c1 - 1];
                dp[n_caracs_c1][n_caracs_c2].size = 1 + dp[n_caracs_c1 -1][n_caracs_c2 - 1].size;
                dp[n_caracs_c1][n_caracs_c2].antecedent = &(dp[n_caracs_c1 -1][n_caracs_c2 - 1]);
            }else
            {
                dp[n_caracs_c1][n_caracs_c2].val = '\0';
                if (dp[n_caracs_c1][n_caracs_c2 - 1].size >  dp[n_caracs_c1 -1][n_caracs_c2].size)
                {
                    dp[n_caracs_c1][n_caracs_c2].size = dp[n_caracs_c1][n_caracs_c2 - 1].size;
                    dp[n_caracs_c1][n_caracs_c2].antecedent = &(dp[n_caracs_c1][n_caracs_c2 - 1]);
                }else{
                    dp[n_caracs_c1][n_caracs_c2].size = dp[n_caracs_c1 -1][n_caracs_c2].size;
                    dp[n_caracs_c1][n_caracs_c2].antecedent = &(dp[n_caracs_c1 -1][n_caracs_c2]);
                }
                
            }
            
        }
        
    }
    
    print_sol(&(dp[len_chaine_1][len_chaine_2]));
    printf("\n");
    return dp[len_chaine_1][len_chaine_2].size;
}

int main(int argc, char const *argv[])
{

    char *mot_a = NULL;
    char *mot_b = NULL;
    size_t len = 0;

    getline(&mot_a, &len, stdin);
    getline(&mot_b, &len, stdin);

    mot_a = strtok(mot_a, "\n");
    mot_b = strtok(mot_b, "\n");
    printf("max sous seq = %d\n", dp(mot_a, strlen(mot_a), mot_b, strlen(mot_b)));
}
