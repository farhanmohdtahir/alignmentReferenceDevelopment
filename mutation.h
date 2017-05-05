#ifndef MUTATION_H
#define MUTATION_H
#include<string>
using namespace std;

void assignMut(double mutPercent, int oriBaseLen, int *mutType, int *mutBase);
/*
This function is to assign residues that will be undergo mutation (randomly chosen)
@parameter mutPercent: receive percentage of mutation occur
@parameter oriBaseLen: receive total length of reference sequence
@parameter mutType: return type of percentage occur on each mutated residues
@parameter mutBase: return residues number which will undergo mutation
*/
string insertMut(int oriBaseLen, int * mutType, int *mutBase, string oriBase, double &ins, double &del, double &sub);
/*
This function is to apply the mutation residue that had been assign by assignMut function
@parameter oriBaseLen: receive total length of reference sequence
@parameter mutType: return type of percentage occur on each mutated residues
@parameter mutBase: return residues number which will undergo mutation
@parameter oriBase: receive reference sequence string
@parameter ins: return number of residues that undergo insertion mutation
@parameter del: return number of residues that undergo deletion mutation
@parameter sub: return number of residues that undergo substitution mutation
*/
void mutBaseDisp(string out, string newBaseStr, double mutPercent );
/*
This function is to produce simulated sample sequence file
@parameter out: receive simulated sample sequence filename
@parameter newBaseStr: recieve simulated sample sequence (after undergo mutation) from function insertMut
@parameter mutPercent: receive percentage of mutation occur
*/
#endif
