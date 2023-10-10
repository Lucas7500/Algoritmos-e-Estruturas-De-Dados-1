#include <stdio.h>
#include <stdlib.h>

int reverse_number(int);

int main(int argc, char *argv[])
{
  int A, B;

  scanf("%d %d", &A, &B);

  A = reverse_number(A);
  B = reverse_number(B);

  printf("%d", A > B ? A : B);

  return 0;
}

int reverse_number(int num)
{
  int hundred, ten, unit;

  unit = num / 100;
  ten = ((num % 100) / 10) * 10;
  hundred = (num % 10) * 100;

  return hundred + ten + unit;
}