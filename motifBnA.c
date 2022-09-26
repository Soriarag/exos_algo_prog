#include <stdio.h>

int main(int argc, char const *argv[])
{
    char mystring[200000];

    int count = 0;
    char c = '*';
    while (c != '\n')
    {
        c = getchar();
        if (c == 'A')
        {
            count ++;
        }
        
         
    }
    
    printf("%d\n",count);

    return 0;
}
