#include "rgi.h"

// Add needed constants
const int LOW = 1, HIGH = 10000, VEC_SIZE = 200, NO_ITEMS = 12, ITEM_W = 5;

// Add code for genRndNums
void genRndNums(std::vector<int> &v, int num)
{
  srand(1);

  //generating num random integers and storing them in vector v
  for (int i = 0; i < num; ++i)
  {
    int random_num = rand() % HIGH + LOW;
    v.push_back(random_num);
  }
}

// Add code for printVec
void printVec(std::vector<int> &v)
{
  for (int i = 0; i < VEC_SIZE; ++i)
  {
    if (i % NO_ITEMS == 0)
    {
      std::cout << v.at(i) << std::endl;
    }
    else
    {
      std::cout << std::right << v.at(i) << std::setw(ITEM_W);
    }
  }

  /*for (int i = 1; i < VEC_SIZE; i++)
  {
    if (i % 12 == 0)
    {
      std::cout << '\n' << v.at(i) << "     ";
    }else{
      std::cout << v.at(i) << "     ";
    }
  }*/
}

int main()
{
  // Declare vector v
  std::vector<int> v;
  // Generate random numbers to fill vector v
  genRndNums(v, VEC_SIZE);
  // Using STL sort sort v
  sort(v.begin(), v.end());
  // Print vector of sorted random numbers
  printVec(v);

  return 1;
}
