#ifndef RANDOMBASE_H
#define RANDOMBASE_H
#include <string>
using namespace std;

char randbase();
/*
This function is to create new residue to replace original residue 
which had been assign to undergo mutation
*/
bool checkRand (int *mutBase, int itr);
/*
This function is to identified whether the residue already assigned as 
undergo mutation or not
@parameter mutBase: Receive the mutated residue
@parameter itr: Receive number of current residue number
*/
bool checkRandSubs(string oriBase, string newBase, int indctr, int newNum);
/*
This function is to avoid for substituted residue does not subtitute 
with the same residue as before
@parameter oriBase: receive reference sequence string
@parameter newBase: receive simulated sample sequence string
@parameter indctr: receive number of original residue
@parameter newNum: receive number of simulated residue that undergo substitution mutation
*/

#endif
