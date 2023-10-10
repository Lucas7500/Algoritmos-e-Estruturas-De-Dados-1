#include <stdio.h>
#include <math.h>

void fill_fibonacci_sequence(long double *fibonacciSequence, int higherIdx);
void print_prime_factors(long double num);

int main()
{
  int quantity, higherIdx = 0, i;

  scanf("%d", &quantity);

  int fibonacciNumsIdx[quantity];

  for (i = 0; i < quantity; i++)
  {
    scanf("%d", &fibonacciNumsIdx[i]);

    if (fibonacciNumsIdx[i] > higherIdx)
    {
      higherIdx = fibonacciNumsIdx[i];
    }
  }

  long double fibonacciSequence[higherIdx + 1];

  fill_fibonacci_sequence(&fibonacciSequence[0], higherIdx);

  for (i = 0; i < quantity; i++)
  {
    print_prime_factors(fibonacciSequence[fibonacciNumsIdx[i]]);
    printf("\n");
  }

  return 0;
}

void fill_fibonacci_sequence(long double *fibonacciSequence, int higherIdx)
{
  int i;

  for (i = 0; i <= higherIdx; i++)
  {
    if (i == 0)
    {
      fibonacciSequence[i] = 0;
    }
    else if (i == 1)
    {
      fibonacciSequence[i] = 1;
    }
    else
    {
      fibonacciSequence[i] = fibonacciSequence[i - 1] + fibonacciSequence[i - 2];
    }
  }
}

void print_prime_factors(long double num)
{
  long double i;

  while (remainder(num, 2.0) == 0.0)
  {
    printf("%d ", 2);
    num /= 2;
  }

  for (i = 3; i * i <= num; i = i + 2)
  {
    while (remainder(num, i) == 0.0)
    {
      printf("%.0Lf ", i);
      num /= i;
    }
  }

  if (num > 2)
  {
    printf("%.0Lf", num);
  }
}