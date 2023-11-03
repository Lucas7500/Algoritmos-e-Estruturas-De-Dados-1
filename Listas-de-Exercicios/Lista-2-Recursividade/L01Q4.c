#include <stdio.h>
#include <math.h>

int reverse(int, int);

int main()
{
  int n;

  scanf("%d", &n);

  printf("%d", reverse(n, 0));

  return 0;
}

int reverse(int n, int revNum) 
{
  if (n == 0)
  {
    return revNum;
  }

  revNum = (revNum * 10) + (n % 10);

  return reverse(n / 10, revNum);
}