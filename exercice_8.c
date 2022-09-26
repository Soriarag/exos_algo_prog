#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char *mot;
    size_t len;
    getline(&mot, &len, stdin);
    for (int i = 0, j = len - 1; i > j; i++, j--)
    {
        if (mot[i] != mot[j])
        {
            printf("non");
        }
        
    }

    printf("oui");
    
}
