#include <stdio.h>
#include <string.h>

int main()
{
  int N, K, repeat = 0, i;

  do
  {
    if (repeat != 0)
    {
      printf("Invalid value for N or K, try again.\n");
    }

    scanf("%d %d", &N, &K);
    repeat = 1;
  } while (N < 1 || N > 1000 || K < 1 || K > 20);

  int labels[N], typesOfCandy[K], envelopes = N / K;
  memset(typesOfCandy, 0, K * sizeof(typesOfCandy[0]));

  for (i = 0; i < N; i++)
  {
    scanf("%d", &labels[i]);
    typesOfCandy[labels[i] - 1] += 1;
  }

  for (i = 0; i < K; i++)
  {
    if (typesOfCandy[i] < envelopes)
    {
      envelopes = typesOfCandy[i];
    }
  }

  printf("%d", envelopes);

  return 0;
}