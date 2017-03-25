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
		mutFreq=(mutPercent/100)*oriBaseLen;
		mutFreqRnd=round(mutFreq);
		
		for (int i=0; i<mutFreqRnd; i++){
			if (i==0) {
			mutType[i]=rand() % 4;    					//0-addition 1-deletion 2-substitution 
			mutBase[i]=rand() % oriBaseLen;
			}
			else{
			mutType[i]=rand() % 4;    					//0-addition 1-deletion 2-substitution 
			mutBase[i]=rand() % oriBaseLen;
			while(checkRand(mutBase, i)){
				mutBase[i]=rand() % oriBaseLen;
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

		while(indctr<oriBaseLen){		
			if(indctr==mutBase[j]){	
			
				if (mutType[j]==0){
					newBase[newNum]=randbase();
					newNum+=1;
					ins+=1; 
				}
				
				else if (mutType[j]==1){
					newBase[newNum]=oriBase[mutRef+1];
					newNum+=1;
					mutRef+=2;
					del+=1;
				}
				
				else{
					newBase[newNum]=randbase();
					while(checkRandSubs(oriBase, newBase, indctr, newNum)){
						newBase[newNum]=randbase();
					}
					newNum+=1;
					mutRef+=1;
					sub+=1;
				}
				j+=1;
				indctr+=1;
				count+=1;
			}
			else{						
				newBase[newNum]=oriBase[mutRef];
				newNum+=1;
				mutRef+=1;
				indctr+=1;
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
			outfile<<">sequence with "<<mutPercent<<"% INDEL mutation and has close evolutionary distance with query\n";
			outfile<<newBaseStr;
		outfile.close();	
}

void noMutDisp (string out, string oriBase, double mutPercent){
	ofstream outfile;	
		outfile.open(out.c_str());
		outfile<<">sequence with "<<mutPercent<<"% INDEL mutation and has close evolutionary distance with query\n";
		outfile<<oriBase;
		outfile.close();
}

