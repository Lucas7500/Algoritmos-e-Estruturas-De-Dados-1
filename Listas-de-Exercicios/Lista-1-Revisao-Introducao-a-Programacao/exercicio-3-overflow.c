#include <stdio.h>

int main()
{
  int max, num1, num2;
  char operator;

  scanf("%d", &max);
  scanf("%d %c %d", &num1, &operator, & num2);

  if (operator== '+')
  {
    num1 + num2 > max ? printf("overflow") : printf("no overflow");
  }
  else if (operator== 'x' || operator== 'X')
  {
    num1 *num2 > max ? printf("overflow") : printf("no overflow");
  }

  return 0;
}