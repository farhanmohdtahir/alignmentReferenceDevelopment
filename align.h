#ifndef ALIGN_H
#define ALIGN_H
#include<string>
using namespace std;

string alignStr (int oriBaseLen, int * mutBase, int * mutType, string oriBase);
void printAlign(string in, string out, double ins, double del, double sub, double mutPercent, int oriBaseLen, string alignBaseStr, string newBaseStr);
#endif
