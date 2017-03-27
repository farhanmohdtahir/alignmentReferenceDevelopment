#ifndef MUTATION_H
#define MUTATION_H
#include<string>
using namespace std;

void assignMut(double mutPercent, int oriBaseLen, int *mutType, int *mutBase);
string insertMut(int oriBaseLen, int * mutType, int *mutBase, string oriBase, double &ins, double &del, double &sub);
void mutBaseDisp(string out, string newBaseStr, double mutPercent );
#endif
