#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main()
{
  int quantity;
  int R, r, a, b, c, B, H, i;
  float p;

  scanf("%d", &quantity);

  char figure[quantity];
  int areas[quantity];

  for (i = 0; i < quantity; i++)
  {
    scanf(" %c", &figure[i]);

    switch (figure[i])
    {
    case 'C':
      scanf("%d", &R);
      areas[i] = round(PI * pow(R, 2));
      break;
    case 'E':
      scanf("%d %d", &R, &r);
      areas[i] = round(PI * R * r);
      break;
    case 'T':
      scanf("%d %d %d", &a, &b, &c);
      p = (a + b + c) / 2.0;
      areas[i] = round(sqrt(p * (p - a) * (p - b) * (p - c)));
      break;
    case 'Z':
      scanf("%d %d %d", &B, &b, &H);
      areas[i] = round(((B + b) * H) / 2.0);
      break;
    }
  }

  for (i = 0; i < quantity; i++)
  {
    printf("%d\n", areas[i]);
  }

  return 0;
}