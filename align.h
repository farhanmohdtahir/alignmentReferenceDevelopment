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

void alignStr (int oriBaseLen, int * mutBase, int * mutType, string oriBase, string newBaseStr, int & alignLen, align & a, 
align & b, align & symbol);
/*
This function is to do alignment between reference sequence and simulated sequence
@parameter oriBaseLen: receive length number of reference sequence
@parameter mutBase: receive residue that undergo mutation
@parameter mutType: receive type of mutation that occur on each mutated residue
@parameter oriBase: receive reference sequence string
@parameter newBaseStr: receive simulated sequence string
@parameter alignLen: return length number of sequence alignment
@parameter a: return sequence alignment of reference sequence (object a)
@parameter b: return sequence alignment of simulated sequence (object b)
@parameter symbol: return symbol either | for identical residue and . non identical residue (object symbol)
*/

void calcIden (align a, align b, int alignLen, iden & same, iden & dif, iden & gap);
/*
This function is to calculate the percentage of insertion, deletion and substitution mutation. 
Calculate percentage of identity, number of identical residue, non-identical residue and gaps.
@parameter a: receive sequence alignment of reference sequence (object a)
@parameter b: receive sequence alignment of simulated sequence (object b)
@parameter alignLen: receive length number of sequence alignment
@parameter same: return number of identical residue (object same)
@parameter dif: return number of identical residue (object dif)
@parameter gap: return number of gaps (object gap)
*/

void printAlign(string in, string out, double ins, double del, double sub, double mutPercent, int oriBaseLen, string oriBase, 
string newBaseStr, int * mutType, int * mutBase);
/*
This function is to create reference sequence alignment file
@parameter in: Receive reference sequence string from input file
@parameter out: receive simulated sample sequence filename
@parameter ins: receive number of residues that undergo insertion mutation
@parameter del: receive number of residues that undergo deletion mutation
@parameter sub: receive number of residues that undergo substitution mutation
@parameter mutPercent: receive percentage of mutation occur
@parameter oriBaseLen: receive length number of reference sequence
@parameter oriBase: receive reference sequence string
@parameter newBaseStr: receive simulated sequence string
@parameter mutType: receive type of mutation occur on each mutated residues
@parameter mutBase: receive mutated residues
*/

#endif
