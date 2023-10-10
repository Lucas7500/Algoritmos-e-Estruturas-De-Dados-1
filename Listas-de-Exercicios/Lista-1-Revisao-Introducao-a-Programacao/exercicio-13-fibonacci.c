#include <stdio.h>

void fill_fibonacci_sequence(long double *fibonacciSequence, int higherIdx);

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
    printf("%.0Lf\n", fibonacciSequence[fibonacciNumsIdx[i]]);
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