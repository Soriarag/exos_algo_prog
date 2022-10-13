#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// input:
/* <sizeOfSystem>
<system value 1> <system value 2> ... <system value n>
<value to compute>
*/

int *solutions[100000] = {NULL};
int solvable[100000] = {0};
int N;
int *values;

int solution(int sum)
{ // returns -1 if impossible else 1 0 means not computed
    if (solvable[sum] == 0)
    {

        if (sum <= 0)
        {
            return -1;
        }

        for (int i = 0; i < N; i++)
        {
            if (solution(sum - values[i]) == 1)
            {

                solvable[sum] = 1;
                solutions[sum] = malloc(N * sizeof(int));
                memcpy(solutions[sum], solutions[sum - values[i]], N * sizeof(int));
                solutions[sum][i]++;

                return 1;
            }
        }

        solvable[sum] = -1;
    }

    return solvable[sum];
}

int cmpfunc (const void * a, const void * b) {
   return (*(int*)b - *(int*)a );
}

int main(int argc, char const *argv[])
{

    scanf("%d", &N);

    values = malloc(N * sizeof(int));

    int nvalue;
    for (int i = 0;  i < N; i++){
        scanf("%d", &nvalue);
        values[i] = nvalue;
        solvable[nvalue] = 1;
        solutions[nvalue] = calloc(N, sizeof(int)); 
    }

    qsort(values, N, sizeof(int), cmpfunc);

    for (int i = 0;  i < N; i++) solutions[values[i]][i] = 1;

    int sum;

    while (scanf("%d", &sum) > -1)
    {
        if (solution(sum) == 1)
        {
            printf("%d = ", sum);
             printf("%d * %d", solutions[sum][0], values[0]);
            for (int i = 1; i < N; i++){
                printf(" + %d * %d", solutions[sum][i], values[i]);
            }
                
                printf("\n");
        }
        else
        {
            printf("NO\n");
        }
    }


    return 0;
}
