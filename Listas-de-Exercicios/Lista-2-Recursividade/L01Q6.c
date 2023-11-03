#include <stdio.h>

long double fatorial_duplo(int, long double);

int main()
{
  int num;

  scanf("%d", &num);
  printf("%.0Lf", fatorial_duplo(num, 1));

  return 0;
}

long double fatorial_duplo(int num, long double fat)
{
  if (num <= 2)
  {
    return fat;
  }

  if (num % 2 == 1)
  {
    fat *= num;
    return fatorial_duplo(num - 2, fat);
  }
  
  return fatorial_duplo(num - 1, fat);
}