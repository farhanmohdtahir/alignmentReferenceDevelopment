#include "randomBase.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

static const char base[4]={'A', 'T', 'G', 'C'};//, 'N'};

char randbase(){
	int randNum;
	randNum=rand() % 4;
	return base[randNum];
}

bool checkRand(int * mutBase, int itr){
	bool test;
	for(int i=itr-1; i>=0; i--){
		if (mutBase[itr]==mutBase[i]){
			test=true;
			break;
		}
		test=false;
	}
return test; 
}

bool checkRandSubs (string oriBase, string newBase, int indctr, int newNum){
	bool test;
	if (newBase[newNum]==oriBase[indctr]){
		test=true;
	}
	else test=false;
	return test;
}
