#include <stdio.h>

void natural_numbers_until_n(int);

int main()
{
  int n;

  scanf("%d", &n);

  natural_numbers_until_n(n);

  return 0;
}

void natural_numbers_until_n(int n)
{
  if (n == 0)
  {
    return;
  }
  else
  {
    natural_numbers_until_n(n - 1);
    printf("%d ", n);
  }
}