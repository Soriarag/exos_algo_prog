#include <stdio.h>

int main(int argc, char const *argv[])
{

    int count = 0;

    char first, second, third;

    first =getchar();
    second = getchar();
    if (first == '\n' || second == '\n')
    {
       return 0;
    }
    
    third = getchar();
    while (third != '\n')
    {
        
        if (first == 'B' && third == 'A')
        {
            count ++;
        }
        
        first = second;
        second = third;
        third = getchar();
         
    }
    
    printf("%d\n",count);

    return 0;
}
