#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char *mot;
    char maxMot[20];
    int anniv;
    size_t len = 0;
    int maxLen = 0;
    int out = 1, l;
    while (out > -1)
    {
        out = getline(&mot, &len, stdin);

        if (out == -1) l = strlen(mot);
        else l = out;

        if (l > maxLen)
        {
            maxLen = l;
            strcpy(maxMot, mot);
        }

        
    }

    printf("%s\n", maxMot);

    return 0;

}

