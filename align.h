#ifndef ALIGN_H
#define ALIGN_H
#include<string>
using namespace std;

struct align{
	char seqChar[300000]; 
	string seqStr;
};

struct iden{
	double num;
	double perc;
};

void alignStr (int oriBaseLen, int * mutBase, int * mutType, string oriBase, string newBaseStr, int & alignLen, align & a, align & b, align & symbol);
void calcIden (align a, align b, int alignLen, iden & same, iden & dif, iden & gap);
void printAlign(string in, string out, double ins, double del, double sub, double mutPercent, int oriBaseLen, string oriBase, string newBaseStr, int * mutType, int * mutBase);
#endif
