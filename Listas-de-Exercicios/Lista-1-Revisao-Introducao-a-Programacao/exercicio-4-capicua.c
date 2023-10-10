#include <stdio.h>
#include <string.h>

int reverse_number(int);

int main(void)
{
  int quantity, number, aux, i;

  scanf("%d", &quantity);

  char responses[quantity][4];

  for (i = 0; i < quantity; i++)
  {
    scanf("%d", &number);
    aux = reverse_number(number);

    if (number == aux)
    {
      strcpy(responses[i], "yes");
    }
    else
    {
      strcpy(responses[i], "no");
    }
  }

  for (i = 0; i < quantity; i++)
  {
    printf("%s ", responses[i]);
  }

  return 0;
}

int reverse_number(int number)
{
  int hundred = 0, ten = 0, unit = 0, thousands = 0;

  if (number > 999)
  {
    unit = number / 1000;
    ten = ((number % 1000) / 100) * 10;
    hundred = ((number % 100) / 10) * 100;
    thousands = (number % 10) * 1000;
  }
  else if (number > 99)
  {
    unit = number / 100;
    ten = ((number % 100) / 10) * 10;
    hundred = (number % 10) * 100;
  }
  else if (number > 9)
  {
    unit = number / 10;
    ten = (number % 10) * 10;
  }
  else
  {
    return number;
  }

  return thousands + hundred + ten + unit;
}