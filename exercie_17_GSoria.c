#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a, b) (a < b) ? a : b
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0

typedef struct
{
  int points, valeur;
} Objet;

int solutions_plus_optimale[MAXSIZE][MAXSIZE];

// la 

int solution(Objet *data, int data_index, int data_size, int espace)
{
  if (data_index == data_size)
  {
    return -1;
  }
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
      solutions_plus_optimale[i][j] = -1;
    }
  }

  printf("minimal modifications = %d", memoization(mot_a, mot_b, 0, 0));
}
