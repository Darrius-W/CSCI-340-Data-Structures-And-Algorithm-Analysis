#include "josephus.h"

//using std::string;
//using std::cout;
//using std::endl;
//using std::list;
//using std::generate;


int main()
{

  unsigned int cnt=0;
  list<string> L;
  args in;


  //filling list
  init_vals(L, in);

  //printing initial list
  print_list(L, cnt);

  //decrementing index so no need to include that step in formula provided by github
  in.M--;


  //initializing index value
  int j = in.M % L.size();

  //main elimination loop
  while(L.size() > 1)
  {
    //starting iterator from beginning of cycle
    auto p = L.begin();

    //increment iterator
    advance(p, j);

    //kill the soldier/delete that element in the list
    L.erase(p);

    //using formula provided in github notes to determine next index
    j = (j + in.M) % L.size();

    //increment number of soldiers killed/ no. passes
    cnt++;


    if (cnt % in.K == 0 || L.size() == 1)
    {
      print_list(L, cnt);
    }
  }

  return 0;
}




/*
Method: init_vals

Arguments: list<string> &L - List to be filled with generated values

     args &in - struct that holds user input regarding indexes for Jospehus problem

Returns: None

Purpose: Stores user input (number of people in circle, index they'll eliminate eachother in,

     index the program will print survivors) then generates values to store in list based on

     provided user input data
*/

void init_vals(list<string> &L, args &in)
{

  //recording user input
  cout << "Number of people? ";

  cin >> in.N;



  cout << endl << "Index for elimination? ";

  cin >> in.M;



  cout << endl << "Index for printing? ";

  cin >> in.K;

  cout << endl;


  //resizing and filling List L with generated values
  L.resize(in.N);

  SEQ n = SEQ(in.N);

  generate(L.begin(), L.end(), n);
}



/*
Method: print_list

Arguments: const list<string> &L - list of remaining elements in circle

     const unsigned &cnt - count of passes completed in circle

Returns: None

Purpose: Prints out remaining elements in list after the index for printing has been reached
*/

void print_list(const list<string> &L, const unsigned &cnt)
{
  //Declarations
  string backtxt = "th person \n-----------------------------\n";

  int indx = 0;


  //printing different headers if initial run or subsequent runs
  if (cnt == 0)
  {
     cout << "Initial group of people \n-----------------------\n";
  }

  else
  {
    cout << "After eliminating " << cnt << backtxt;
  }



  // printing loop
  for(auto i: L)
  {
    cout << i << " ";
    indx++;


    //if 12 items have been printed
    if(indx == NO_ITEMS)
    {
      cout << endl;
      indx = 0;
    }
  }

  cout << endl << endl;
}
