#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

// You will complete the code below ...
HT::HT(const unsigned &hs) {
hTable.resize(hs);
pTable.resize(hs);
psize = 0;
hsize = TBL_SZ;
for (unsigned int i = 0; i != s; i++)
{
  hTable[i].key = FREE;
}
}

HT::~HT() {}

void HT::insert(const Entry &e) {
int index = hash(e.key);
unsigned int i;
for (i = 0; i < hsize; i++)
{
  if (hTable[(index + i) % hsize].key == FREE)
  {
   // use open addressing: linear probing for collision resolution
   cout << " entry = " << (index + i) % hsize << endl;
   hTable[(index + i) % hsize] = e;
   pTable[psize] = &hTable[(index + i) % hsize];
   psize++;
   break;
  }
  if (hTable[(index + i) % hsize].key == e.key)
  {
   cout << " not inserted - duplicate key!!!" << endl;
   break;
  }
}
if (i == hsize)
  cout << " not inserted - table full!!!" << endl;
}

void HT::search(const string &s) {
int index = hash(s);
unsigned int i;
for (i = 0; i < hsize; i++)
{
  if (hTable[(index + i) % hsize].key == s)
  {
   cout << " ==> number: "
    << setw(4) << hTable[(index + i) % hsize].num
    << " - item: " << hTable[(index + i) % hsize].desc
    << endl;
   break;
  }
}
if (hTable[(index + i) % hsize].key != s)
  cout << " not in table!!" << endl;
}

void HT::hTable_print() {
bool lastEmpty = false;
for (unsigned int i = 0; i < hsize; i++)
{
  if (hTable[i].key != FREE)
  {
   if (lastEmpty) cout << endl;
   cout << setw(4) << i << ": " << hTable[i].key << " - "
    << setw(5) << hTable[i].num << "   - " << hTable[i].desc << endl;
   lastEmpty = false;
  }
  else lastEmpty = true;
}
cout << endl;
}

void HT::pTable_print() {
ptr_sort();
for (unsigned int i = 0; i < hsize; i++)
{
  cout << "   " << pTable[i]->key
   << " - " << right << setw(4) << pTable[i]->num
   << " - " << left << pTable[i]->desc << endl;
}
cout << endl;
}

