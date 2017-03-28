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
using namespace std;
	
string alignStr (int oriBaseLen, int * mutBase, int * mutType, string oriBase){

	string alignBaseStr="";
	char alignBase[oriBaseLen];
	int j=0;
	

	for(int indctr=0; indctr<oriBaseLen; indctr++){		
			if(indctr==mutBase[j]){	
			
				if (mutType[j]==0){
					alignBase[indctr]=oriBase[indctr];
				}
				
				else{
					alignBase[indctr]='-';
				}
				++j;
			}
			else{						
				alignBase[indctr]=oriBase[indctr];
			}
	}
	
	for (int i=0; i<oriBaseLen; i++){
		alignBaseStr+=alignBase[i];
	}
	return alignBaseStr;
}

void printAlign(string in, string out, double ins, double del, double sub, double mutPercent, int oriBaseLen, string alignBaseStr, string newBaseStr){
		
		string outAlign="";
		ofstream alignOutfile;
		
		for (int i=0; i<out.length(); i++){
		if (out[i]=='.') break;
		outAlign+=out[i];
	}
		outAlign+="Align.txt";
		alignOutfile.open(outAlign.c_str());
	
		alignOutfile<<">alignment file between "<<in<<" and "<<out<<endl;
		alignOutfile<<"query sequence file: "<<in<<"("<<oriBaseLen<<"b.p)\n";
		alignOutfile<<"sample sequence file: "<<out<<"("<<newBaseStr.length()<<"b.p)\n";
	if(mutPercent<60){
		alignOutfile<<"indentity percentage: "<<100-mutPercent<<"% (has evolutionary relationship to query sequence)\n";
		alignOutfile<<"similarity percentage: "<<100-mutPercent<<"% (has evolutionary relationship to query sequence)\n";
	}
	else{
		alignOutfile<<"indentity percentage: "<<100-mutPercent<<"% (no evolutionary relationship to query sequence)\n";
		alignOutfile<<"similarity percentage: "<<100-mutPercent<<"% (no evolutionary relationship to query sequence)\n";		
	}
		alignOutfile<<"mutation percentage: "<<mutPercent<<"%\n";
		alignOutfile<<fixed;
		alignOutfile<<"insertion percentage: "<<setprecision(2)<<(ins/oriBaseLen)*100<<"%\n";
		alignOutfile<<"deletion percentage: "<<setprecision(2)<<(del/oriBaseLen)*100<<"%\n";	
		alignOutfile<<"subtitution percentage: "<<setprecision(2)<<(sub/oriBaseLen)*100<<"%\n\n";
	//	cout<<"alignment sequence: \n";
	//	cout<<alignBaseStr<<endl; 
	alignOutfile.close();
}
