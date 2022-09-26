#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char *line = NULL;
    int max = -1, max_i = -1;
    size_t len = 0;
    int freq[256] = {};
    getline(&line, &len, stdin);
    for (size_t i = 0; i < len; i++)
    {
        freq[line[i]]++;
    }
    
    for (size_t i = 0; i < len; i++)
    {
        if (freq[i] > max)
        {
            max_i = i;
            max = freq[i];
        }
        
    }
    
}
