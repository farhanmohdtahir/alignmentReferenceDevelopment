#include "randomBase.h"
#include "mutation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <cstring>
using namespace std;

void assignMut(double mutPercent, int oriBaseLen, int *mutType, int *mutBase){
	int mutFreqRnd;
	double mutFreq;
		mutFreq=(mutPercent/100)*oriBaseLen;			//convert percentage to number of residue
		mutFreqRnd=round(mutFreq);
		
		for (int i=0; i<mutFreqRnd; i++){
			if (i==0) {
			mutType[i]=rand() % 3;    					//0-addition 1-deletion 2-substitution 
			mutBase[i]=rand() % oriBaseLen;				//choose random residues to be mutated
			}
			else{
			mutType[i]=rand() % 3;    					//0-addition 1-deletion 2-substitution 
			mutBase[i]=rand() % oriBaseLen;				//choose random residues to be mutated
			while(checkRand(mutBase, i)){				//determine if the mutated residues had been assigned before or not
				mutBase[i]=rand() % oriBaseLen;			//if yes, program choose another residues randomly
			}
			}	
		}
		
		int* end = mutBase + mutFreqRnd;
		sort(mutBase,end);
	
}

string insertMut(int oriBaseLen, int * mutType, int *mutBase, string oriBase,double &ins, double &del, double &sub){
		
		int j=0, indctr=0, newNum=0, mutRef=0, count=0;
		char newBase[300000];
		string newBaseStr="";

		while(indctr<oriBaseLen+15){		//create simulated sample sequence 
			if(indctr==mutBase[j]){	
			
				if (mutType[j]==0){
					newBase[newNum]=randbase();
					++newNum;
					++ins; 
				}
				
				else if (mutType[j]==1){
					newBase[newNum]=oriBase[mutRef+1];
					++newNum;
					mutRef+=2;
					++del;
				}
				
				else{
					newBase[newNum]=randbase();
					while(checkRandSubs(oriBase, newBase, indctr, newNum)){
						newBase[newNum]=randbase();
					}
					++newNum;
					++mutRef;
					++sub;
				}
				++j;
				++indctr;
				++count;
			}
			else{						
				newBase[newNum]=oriBase[mutRef];
				++newNum;
				++mutRef;
				++indctr;
			}
		}
		for(int i=0; i<newNum; i++){
			newBaseStr+=newBase[i];
			
			if(!newBase[i]) break;
		}

		return newBaseStr;
}

void mutBaseDisp(string out, string newBaseStr, double mutPercent ){
	ofstream outfile;
		outfile.open(out.c_str());
		if(mutPercent<60){
			outfile<<">sequence with "<<mutPercent<<"% INDEL mutation and has evolutionary relationship with query\n";
			outfile<<newBaseStr;
		}
		else{
			outfile<<">sequence with "<<mutPercent<<"% INDEL mutation and has no evolutionary relationship with query\n";
			outfile<<newBaseStr;
		}
		outfile.close();	
}


