#include <stdio.h>
#include <stdlib.h>

int reste(int a, int b);

int main(int argc, char const *argv[])
{

    if (argc < 3)
    {
        printf("usage ./try <a> <b>");
    }
    

    int a = atoi(argv[1]);
    int b = atoi(argv[2]),r;

    r = reste(a,b);
    printf("reste %d/%d = %d\n",a,b,r);
    return 0;
}

int reste(int a, int b){
    int r = a;
    while(r>= b){
        r = r-b;
    }
}