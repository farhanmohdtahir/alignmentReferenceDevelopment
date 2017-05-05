#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <getopt.h>
#include <iomanip>
#include "randomBase.h"
#include "input.h"
#include "mutation.h"
#include "align.h"
using namespace std;

void alignStr (int oriBaseLen, int * mutBase, int * mutType, string oriBase, string newBaseStr, int & alignLen, align & a, align & b, align & symbol){
	int j=0, k=0, l=0;

	for (int i=0; k<newBaseStr.length(); i++){ //create alignment sequence
		if (k==mutBase[l]){
			
			if (mutType[l]==0){			
					a.seqChar[i]='-';
					b.seqChar[i]=newBaseStr[k];
					++k;
			}
			
			else if (mutType[l]==1){
					a.seqChar[i]=oriBase[j];
					b.seqChar[i]='-';
					++j;
			}
			
			else{						
					a.seqChar[i]=oriBase[j];
					b.seqChar[i]=newBaseStr[k];
					++j; ++k;
			}
			++l;
		}

		else{			
		if (!oriBase[j]||!newBaseStr[k]) break;
				a.seqChar[i]=oriBase[j];
				b.seqChar[i]=newBaseStr[k];
				++j; ++k;
	}
	++alignLen;
	}
	
	for(int i=0; i<alignLen; i++){			//create identical or non identical symbol
		if(a.seqChar[i]==b.seqChar[i]){
			symbol.seqChar[i]='|';
		}
		else{
			symbol.seqChar[i]='.';
		}
	}
	a.seqStr=""; b.seqStr=""; symbol.seqStr="";
	for(int i=0; i<alignLen; i++){
		a.seqStr+=a.seqChar[i];
		b.seqStr+=b.seqChar[i];
		symbol.seqStr+=symbol.seqChar[i];
	}
}

void calcIden (align a, align b, int alignLen, iden & same, iden & dif, iden & gap){
	for(int i=0; i<alignLen; i++){
		if(a.seqChar[i]==b.seqChar[i]){
			++same.num;
		}
		else{
			if (a.seqChar[i]=='-'||b.seqChar[i]=='-'){
			++dif.num;
			++gap.num;				
			}
			else{
				++dif.num;
			}
		}
	}
	same.perc=(same.num/alignLen)*100;
	dif.perc=(dif.num/alignLen)*100;
}

void printAlign(string in, string out, double ins, double del, double sub, double mutPercent, int oriBaseLen, string oriBase, string newBaseStr, int * mutType,  int * mutBase){
		
		iden same, dif, gap;
		align a, b, symbol;
		int alignLen;
		string outAlign="";
		ofstream alignOutfile;
		
		same.num=0;
		dif.num=0;
		gap.num=0;
		for (int i=0; i<out.length(); i++){
		if (out[i]=='.') break;
		outAlign+=out[i];
	}
	alignStr (oriBaseLen, mutBase, mutType, oriBase, newBaseStr, alignLen, a, b, symbol);
	calcIden (a, b, alignLen, same, dif, gap);
	
		outAlign+="Align.txt";
		alignOutfile.open(outAlign.c_str());
	
		alignOutfile<<">alignment file between "<<in<<" and "<<out<<endl;
		alignOutfile<<"query sequence file: "<<in<<"("<<oriBaseLen<<"b.p)\n";
		alignOutfile<<"sample sequence file: "<<out<<"("<<newBaseStr.length()<<"b.p)\n";
		alignOutfile<<"mutation percentage: "<<mutPercent<<"%\n";
		alignOutfile<<fixed;
		alignOutfile<<"insertion percentage: "<<setprecision(2)<<(ins/oriBaseLen)*100<<"%\n";
		alignOutfile<<"deletion percentage: "<<setprecision(2)<<(del/oriBaseLen)*100<<"%\n";	
		alignOutfile<<"subtitution percentage: "<<setprecision(2)<<(sub/oriBaseLen)*100<<"%\n\n";
		
		alignOutfile<<"number of identical residue: "<<setprecision(0)<<same.num<<endl;
		alignOutfile<<"number of non-identical residue: "<<setprecision(0)<<dif.num<<endl;
		alignOutfile<<"number of gap: "<<setprecision(0)<<gap.num<<endl<<endl;

		if(mutPercent<60){
			alignOutfile<<"percentage of identical residues: "<<same.perc<<"% \n(has evolutionary relationship to query sequence)\n";			
		}
		else{
			alignOutfile<<"percentage of identical residues: : "<<same.perc<<"% \n(no evolutionary relationship to query sequence)\n";
		}		
		alignOutfile<<"percentage of non-identical residues: "<<dif.perc<<"%"<<endl<<endl;
	
	int k=0, j=60;
	while(k<alignLen){	
	for(int i=k; i<j; i++){
		alignOutfile<<a.seqStr[i];
		if (i>=alignLen-1) break;
	}
	alignOutfile<<endl;
	for(int i=k; i<j; i++){
		alignOutfile<<symbol.seqStr[i];
		if (i>=alignLen-1) break;
	}	
	alignOutfile<<endl;	
	for(int i=k; i<j; i++){
		alignOutfile<<b.seqStr[i];
		if (i>=alignLen-1) break;
	}
	alignOutfile<<endl;
	alignOutfile<<endl;
	alignOutfile<<endl;
	j+=60;						//ensure each line contain up to 60 residues only
	k+=60;						//ensure each line contain up to 60 residues only
}
	alignOutfile.close();
}
