/*
    Darrius White (Z1900146)
    Assignment 2
    09/20/2021
*/

#include "matrix.h"


//Function tries to open 2 files, if they fail it will print error messages saying so
void open_files(ifstream &is1, ifstream &is2)
{
  //opening of matrix01.dat and matrix02.dat
  is1.open(FILE1);
  is2.open(FILE2);

  //error to display if matrix01.dat doesn't open
  if (!is1)
  {
    cerr << "File " << FILE1 << " failed to open.\n";
    exit(1);
  }

  //error to display if matrix02.dat doesn't open
  if (!is2)
  {
    cerr << "File " << FILE2 << " failed to open.\n";
    exit(1);
  }
}


//Reads and stores input data from all files given
void read_data(ifstream &is, vector<vector<int>> &m)
{
  for (size_t i = 0; i < m.size(); i++)//row
  {
    for (size_t j = 0; j < m[i].size(); j++)//column
    {
      is >> m[i][j];//input data stored in matrix
    }
  }
}


//Function to take matrix in parameter and print it to output line
//aligned and spaced correctly
void print_data(const std::vector<vector<int>> &m)
{
  //header of output
  cout << m.size() << " x " << m[0].size() << endl;
  cout << "----------------------------------------------------------------------" << endl;

  for (size_t i = 0; i < m.size(); i++)//row
  {
    for (size_t j = 0; j < m[i].size(); j++)//column
    {
      cout << setw(ITEM_W) << m[i][j];//matrix printed and aligned
    }

    cout << endl;
  }
}


//Multiply both matrix A & B to get matrix C
void gen_data(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C)
{
  for (size_t i = 0; i < A.size(); i++)
  {
    for (size_t j = 0; j < B[0].size(); j++)
    {
      C[i][j] = 0;

      for (size_t k = 0; k < A[0].size(); k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}
