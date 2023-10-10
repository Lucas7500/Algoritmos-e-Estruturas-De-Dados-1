#include <stdio.h>

int main()
{
  int rows, columns, i, j, k;
  char operator;

  scanf("%d %d", &rows, &columns);

  int mat1[rows][columns], mat2[rows][columns];

  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns; j++)
    {
      scanf("%d", &mat1[i][j]);
    }
  }

  scanf("%*c%c", &operator);

  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns; j++)
    {
      scanf("%d", &mat2[i][j]);
    }
  }

  if (operator== '+')
  {
    int matSum[rows][columns];

    for (i = 0; i < rows; i++)
    {
      for (j = 0; j < columns; j++)
      {
        matSum[i][j] = mat1[i][j] + mat2[i][j];
        printf("%d ", matSum[i][j]);
      }
      printf("\n");
    }
  }
  else if (operator== 'x' && rows == columns)
  {
    int matMult[rows][columns];

    for (i = 0; i < rows; i++)
    {
      for (j = 0; j < columns; j++)
      {
        matMult[i][j] = 0;

        for (k = 0; k < columns; k++)
        {
          matMult[i][j] += mat1[i][k] * mat2[k][j];
        }
      }
    }

    for (i = 0; i < rows; i++)
    {
      for (j = 0; j < columns; j++)
      {
        printf("%d ", matMult[i][j]);
      }

      printf("\n");
    }
  }
  else
  {
    printf("ERROR");
  }

  return 0;
}