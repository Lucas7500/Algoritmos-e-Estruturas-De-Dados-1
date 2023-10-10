#include <stdio.h>
#include <math.h>

int main()
{
  int year, syncYear = 1986;
  float period = 76;

  do
  {
    scanf("%d", &year);
  } while (year < 0 || year > 10000);

  int nextYearOfCometHalley, timeSince1986, extraDays, extraYears;

  if (year > syncYear)
  {
    nextYearOfCometHalley = syncYear;

    while (nextYearOfCometHalley <= year)
    {
      nextYearOfCometHalley += period;
    }

    extraDays = (nextYearOfCometHalley - syncYear) / 4;
    extraYears = extraDays / 365;
    nextYearOfCometHalley -= extraYears;
  }
  else
  {
    nextYearOfCometHalley = syncYear;

    while (nextYearOfCometHalley > year)
    {
      nextYearOfCometHalley -= period;
    }
    nextYearOfCometHalley += 76;

    extraDays = (syncYear - nextYearOfCometHalley) / 4;
    extraYears = extraDays / 365;
    nextYearOfCometHalley -= extraYears;
  }

  printf("%d\n", nextYearOfCometHalley);

  return 0;
}