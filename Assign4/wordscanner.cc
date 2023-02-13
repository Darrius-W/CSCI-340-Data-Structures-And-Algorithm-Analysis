/*
    Darrius White (Z1900146)
    Assignment 4
    10/4/2021
*/

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

typedef map<string, int>::const_iterator it_Dtype;


const int NO_ITEMS = 4;
const int ITEM_WORD_WIDTH = 14;
const int ITEM_COUNT_WIDTH = 3;


//convert character to lowercase
void lowercase(char& c)
{
  c = tolower(c);
}

//Prints contents of listed words and frequencies
//as well ad the number of distinct and non-empty words
void print_words(const map<string, int>& m)
{
  int count = 0, input_word_count = 0;

  //going through and adjusting/aligning each word
  for(it_Dtype it = m.begin(); it != m.end(); ++it)
  {
    if(count == NO_ITEMS)
    {
      count = 0;
      cout << endl;
    }

    //adding each word to the count
    input_word_count += (*it).second;

    cout << setw(ITEM_WORD_WIDTH) << left << (*it).first << " : "
         << setw(ITEM_COUNT_WIDTH) << (*it).second << " ";

    count++;
  }

  cout << endl << endl;
  cout << "no of words in input stream   :" << input_word_count << endl;
  cout << "no of words in output stream  :" << (int)m.size();
}


//function cleans words of punctuation and sets them to lowercase
void clean_entry(const string& s1, string& s2)
{
  int pos = 0, len = 0;
  bool hasPunc = false, s_first = false, s_end = false;

  //loop testing all the characters
  for(int count = 0; count < (int)s1.length(); count++)
  {
    if(!isalnum(s1[count]))//test for punctuation
    {
      hasPunc = true;
    }

    //if alnum says there is a character then the
    //first character of the word will be registered
    if(isalnum(s1[count]) && s_first == false)
    {
      s_first = true;
      pos = count;
    }

    //if statements to count the precise length of
    //each word as well as end when the word has ended
    if(s_first == true)
    {
      if(!isalnum(s1[count]))
      {
        s_end = true;
        len = count;
      }
    }

    if(s_end == true)
      break;
  }

  s2 = s1.substr(pos, len - pos);//the size of the word
  for_each(s2.begin(), s2.end(), lowercase);//convert words to lowercase

  //if there is no punctuation then s2 is simply set to s1
  if(hasPunc == false)
  {
    s2 = s1;
    for_each(s2.begin(), s2.end(), lowercase);//convert to lowercase
  }
}


//function collects words from infile and sends them through
//clean_entry to be clean and then stores them into the map
void get_words(map<string, int>& m, ifstream& infile)
{
  string dirtyWord, s;

  //retrieve each word from file
  while(infile >> dirtyWord)
  {
    clean_entry(dirtyWord, s);//clean current dirtyWord

    if(s.length() > 0)
      m[s]++;//places word into map
  }

  //when end of file is reached
  if(infile.eof())
    return;
}


int main()
{
  map<string, int> m;

  ifstream infile("wordscanner.in");
  if(!infile)
  {
    cerr << "File failed to open\n";
    exit(1);
  }

  get_words(m, infile);//send file through get_words
  infile.close();

  print_words(m);//printed output
  cout << endl;

  return 0;

}
