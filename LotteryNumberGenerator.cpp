#include <iostream>


/**
 * created by @kevinawalsh (I believe)
 * int randInRange(int lo, int hi)
 * @param lo the low end of the range
 * @param hi the high end of the range
 * @return a random number in between lo and hi, inclusive
 * Purpose: Returns a random number in between lo and hi, inclusive
*/
int randInRange(int lo, int hi)
{
  double v = (double)rand();    // 0 <= v && v <= RAND_MAX
  double f = v / ((double)RAND_MAX+1);  // 0 <= f && f < 1.0
  return lo + (int)(f * (hi - lo + 1));
}  // end randInRange


/**
 * int threeAndThree(int nums[], int min, int max)
 * @param numCount the number of numbers to generate
 * @param min the lowest number that can be generated
 * @param max the highest number that can be generated
 * 
 * Generates a list of randomly chosen numbers with 3 evens, 3 odds, 3 highs, and 3 lows.
 * "High" is defined as between max/2 + 1 and max.
 * 
 * Credit: uses @kevinawalsh's function randInRange() to generate random numbers.
*/
void threeAndThree(int nums[], int min, int max)
{
    int evenCount = 0;
    int oddCount = 0;
    int highCount = 0;
    int lowCount = 0;
    int i = 0;
    while(i < 6)
    {
      bool duplicate = false;
      int num = randInRange(min, max);
      for(int j = 0; j < i && !duplicate; j++)
      {
        if(nums[j] == num)
        {
          duplicate = true;
        }
      }
      if(duplicate)
      {
        continue;
      }
      if(num % 2 == 0) // if it is an even number
      {
        if(evenCount == 3) // if there are already enough even numbers
        {
          continue; // generate another number without incrementing i
        }
        else // if there is room for another even number
        {
          if(num >= max / 2) // if it is a "high" number
          {
            if(highCount == 3) // if there are already enough high numbers
            {
              continue; // generate another number without incrementing i
            }
            else // if there is room for another high number
            {
              nums[i] = num;
              evenCount++;
              highCount++;
              i++;
            }
          }
          else // if it is a "low" number
          {
            if(lowCount == 3) //if there are already enough low numbers
            {
              continue; // generate another number without incrementing i
            }
            else // if there is room for another low number
            {
              nums[i] = num;
              evenCount++;
              lowCount++;
              i++;
            }
          }
        }
      }
      else // if it is an odd number
      {
        if(oddCount == 3) // if there are already enough odd numbers
        {
          continue; // generate another number without incrementing i
        }
        else // if there is room for another odd number
        {
          if(num >= max / 2) // if it is a "high" number
          {
            if(highCount == 3) // if there are already enough high numbers
            {
              continue; // generate another number without incrementing i
            }
            else
            {
              nums[i] = num;
              oddCount++;
              highCount++;
              i++;
            }
          }
          else // if it is a "low" number
          {
            if(lowCount == 3) // if there are already enough low numbers
            {
              continue; // generate another number without incrementing i
            }
            else // if there is room for another low number
            {
              nums[i] = num;
              oddCount++;
              lowCount++;
              i++;
            }
          }
        }
      }
    }
} // end threeAndThree

std::string numArrayString(int array[])
{
  std::string arrString;
  for(int i = 0; i < 6; i++)
  {
    arrString += std::to_string(array[i]) + " ";
  }
  return arrString;
} // end numArrayString

int main()
{
    srand(time(0));

    int combinations;
    int max;
    int min;
    std::cout << "Welcome to the Lottery Number Generator!\n" << std::endl;
    std::cout << "This generator is suited for a six-number game, such as Powerball or Mega Millions." <<
    "According to the research of Edvin Hiltner of Lotterycodex, the combination of six numbers with the" <<
    "highest success-to-failure ratio is as follows: three numbers above half of the maximum (high numbers)," <<
    "three below the maximum / 2, three even, and three odd. This program is designed to generate" <<
    "lists of numbers according to that formula.\n" << std::endl;

    std::cout << "How many combinations of numbers would you like to generate? ";
    std::cin >> combinations;
    while(combinations < 0)
    {
      std::cout << "You must enter a number greater than or equal to 0. Enter 0 if you would like to quit. ";
      std::cin >> combinations;
    }
    if(combinations == 0)
    {
      std::cout << "Thank you for using the Lottery Number Generator!" << std::endl;
      return 0;
    }
    std::cout << "What would you like your maximum number to be? (The number must be greater than 0.) ";
    std::cin >> max;
    while(max <= 0)
    {
      std::cout << "Please enter a number greater than 0: ";
      std::cin >> max;
    }
    std::cout << "What would you like your minimum number to be? (The number must be greater than or " <<
    "equal to 0 and less than the max.) ";
    std::cin >> min;
    while(min <= 0 || min >= max)
    {
      std::cout << "Please enter a number greater than or equal to 0 and less than the max: ";
      std::cin >> min;
    }
    for(int i = 0; i < combinations; i++)
    {
      int array[6];
      threeAndThree(array, min, max);
      std::cout << numArrayString(array) << std::endl;
    }

    return 0;
} // end main