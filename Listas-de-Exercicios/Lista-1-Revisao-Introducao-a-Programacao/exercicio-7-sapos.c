#include <stdio.h>
#include <string.h>

int main()
{
  int P, S, aux = 0, i;

  scanf("%d %d", &P, &S);

  int stones[P], jumpSizeFrogs[S], initialPositionFrogs[S];
  memset(stones, 0, P * sizeof(stones[0]));

  for (i = 0; i < S; i++)
  {
    scanf("%d %d", &initialPositionFrogs[i], &jumpSizeFrogs[i]);

    aux = initialPositionFrogs[i];

    stones[aux - 1] = 1;

    while (aux < P)
    {
      aux += jumpSizeFrogs[i];

      if (aux > P)
      {
        break;
      }

      stones[aux - 1] = 1;
    }

    aux = initialPositionFrogs[i];

    while (aux >= 0)
    {
      aux -= jumpSizeFrogs[i];

      if (aux <= 0)
      {
        break;
      }

      stones[aux - 1] = 1;
    }
  }

  for (i = 0; i < P; i++)
  {
    printf("%d\n", stones[i]);
  }

  return 0;
}
