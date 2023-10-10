#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 9

void isprime(unsigned long long int number, char[][MAX]);

int main()
{
  int quantity, repeat = 0, i;
  unsigned long long int number;

  do
  {
    if (repeat != 0)
    {
      printf("Invalid value for N or K, try again.\n");
    }

    scanf("%d", &quantity);
    repeat = 1;
  } while (quantity < 1 || quantity > 100);

  char responses[quantity][MAX];

  for (i = 0; i < quantity; i++)
  {
    scanf("%llu", &number);
    isprime(number, &responses[i]);
  }

  for (i = 0; i < quantity; i++)
  {
    printf("%s\n", responses[i]);
  }

  return 0;
}

void isprime(unsigned long long int number, char response[][MAX])
{
  int i;

  for (i = 2; i <= sqrt(number); i++)
  {
    if (number % i == 0)
    {
      strcpy(*response, "composto");
      return;
    }
  }

  strcpy(*response, "primo");
}