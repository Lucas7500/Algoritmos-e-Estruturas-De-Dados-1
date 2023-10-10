#include <stdio.h>
#include <string.h>
#define MAX 10

void convert_to_letters(int, char[][MAX]);
char *reverse_string(char[]);

int main()
{
  int quantity, i;

  scanf("%d", &quantity);

  int numbers[quantity];
  char numberInLetters[quantity][MAX];

  for (i = 0; i < quantity; i++)
  {
    scanf("%d", &numbers[i]);
    convert_to_letters(numbers[i], &numberInLetters[i]);
  }

  for (i = 0; i < quantity; i++)
  {
    printf("%s\n", numberInLetters[i]);
  }

  return 0;
}

void convert_to_letters(int number, char numberInLetters[][MAX])
{
  int quaternary = 0, position = 1, idx = 0, remainder, i;
  char invertedLetters[MAX];

  while (number > 0)
  {
    remainder = (number % 4);
    quaternary += remainder * position;
    number /= 4;
    position *= 10;

    switch (remainder)
    {
    case 0:
      invertedLetters[idx] = 'A';
      idx++;
      break;
    case 1:
      invertedLetters[idx] = 'C';
      idx++;
      break;
    case 2:
      invertedLetters[idx] = 'G';
      idx++;
      break;
    case 3:
      invertedLetters[idx] = 'T';
      idx++;
      break;
    }
  }

  invertedLetters[idx] = '\0';

  strcpy(*numberInLetters, reverse_string(invertedLetters));
}

char *reverse_string(char string[])
{
  char tmp;
  int idx = 0, i, middle;

  for (i = strlen(string) - 1, middle = (i + 1) / 2; i >= middle; i--)
  {
    tmp = string[idx];
    string[idx] = string[i];
    string[i] = tmp;
    idx++;
  }

  return string;
}