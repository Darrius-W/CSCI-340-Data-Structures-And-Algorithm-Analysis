#ifndef H_RGI // should not be defined any place else
#define H_RGI // same const value as for ifndef directive

// Add minimal needed header files here ..
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

// You need to declare these two functions ...
void genRndNums(std::vector<int> &v, int num);
void printVec(const std::vector<int> &v);

#endif
