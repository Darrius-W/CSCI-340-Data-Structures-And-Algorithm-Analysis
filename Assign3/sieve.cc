/*
    Darrius White (Z1900146)
    Assignment 3
    09/27/2021
*/

#include <iostream>
#include <set>
#include <iomanip>

#define NO_ITEMS 16
#define ITEM_W 5

using std::set;

void sieve(set<int>& s, int n)
{
  //initializing set container up to limit set by user
  for(int i = 2; i < n; i++)
    s.insert(i);

  //loop that iterates through key values for m <= sqrt(n) up to limit
  for(int m = 2; m * m <= n; m++)
  {
    //loop erases all non-prime numbers
    for(int k = 2; m * k < n; k++)
      s.erase(m * k);
  }
}

void print_primes(const set<int>& s)
{
  set<int>::iterator it;
  int counter = 0;

  //iterates through container and prints non-prime numbers
  for(it = s.begin(); it != s.end(); it++)
  {
    if(counter == NO_ITEMS)//end line after 16 printed values
    {
      std::cout << std::endl;
      counter = 0;
    }

    std::cout << std::right << std::setw(ITEM_W) << *it;//prints values with correct alignment

    counter++;
  }

  std::cout << std::endl;
}

int
main()
{
  int n;
  set<int> s;

  std::cout << "Upper limit for the set of primes: ";

  std::cin >> n;
  std::cout << std::endl;

  sieve(s, n);
  print_primes(s);

  return 0;
}
