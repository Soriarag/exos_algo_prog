#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char *line = NULL, prenom[50], nom[50];
    int anniv;
    size_t len = 0;
    char annivs[366][256] = {};
    while (getline(&line, &len, stdin) > 0)
    {
        sscanf(line, "%[^,],%[^,],%d", prenom, nom, &anniv);
        if (annivs[anniv][0] != 0)
        {
            printf("%s, %s\n", prenom, nom);
            printf("%s\n", annivs[anniv]);
        }
        else
        {
            sprintf(annivs[anniv], "%s, %s\n", prenom, nom);
        }
    }
}
