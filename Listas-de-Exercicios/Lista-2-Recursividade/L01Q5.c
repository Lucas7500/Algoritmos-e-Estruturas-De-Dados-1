#include <stdio.h>
#include <math.h>

long double convert_to_bin(long double, long double);

int main()
{
  int repeat, i;

  scanf("%d", &repeat);

  long double nums[repeat];

  for (i = 0; i < repeat; i++)
  {
    scanf("%Lf", &nums[i]);
  }

  for (i = 0; i < repeat; i++)
  {
    printf("%.0Lf\n", convert_to_bin(nums[i], 0));
  }

  return 0;
}

long double convert_to_bin(long double dec, long double bin)
{
  static int i = 0;

  if (dec == 0)
  {
    i = 0;
    return bin;
  }

  bin += (int)dec % 2 == 0 ? 0 : pow(10, i) * 1;
  i++;

  return convert_to_bin(floor(dec / 2), bin);
}