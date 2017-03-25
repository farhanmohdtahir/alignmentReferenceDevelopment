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

void help();

int main(int argc, char * argv []){
	int oriBaseLen, opt=0;
	double  mutPercent, insPercent, delPercent, subPercent, ins=0, del=0, sub=0;
	string in="", out="",  oriBase="", newBaseStr="";
	bool option=false;
	
	
    static struct option long_options[] = {
        {"help",                       no_argument,       0,  'h' },
        {"inputFile",              required_argument,     0,  'i' },
        {"outputFile",             required_argument,     0,  'o' },
        {"mutationPercentage",     required_argument,     0,  'm' },                            
        {0,                               0,              0,   0  }
    };
    
        int long_index =0;
    while ((opt = getopt_long_only(argc, argv,"", 
                   long_options, &long_index )) != -1) {
        switch (opt) {
             case 'h' : help();option = true;
                 break;
             case 'i' : in = optarg;option = true;
                 break;
             case 'o' : out = optarg;option = true;
                 break;
             case 'm' : mutPercent = atoi(optarg);option = true;
                 break;                                                    
             default: help(); 
                 exit(EXIT_FAILURE);
        }
    }
	
    if(option == false) help();
    
    if (in!="" && out!="" && mutPercent){
		oriBase=encodebase(in);
		oriBaseLen=oriBase.length();
		int  mutBase[oriBaseLen], mutType[oriBaseLen];
		
		if (mutPercent==0)
		{
			noMutDisp(out, oriBase, mutPercent);
		}
		
		else{
			assignMut(mutPercent, oriBaseLen, mutType, mutBase);
			newBaseStr=insertMut(oriBaseLen, mutType, mutBase, oriBase, ins, del, sub);
			mutBaseDisp( out, newBaseStr, mutPercent);
	}
	
	cout<<"indentity percentage: "<<100-mutPercent<<"%\n";
	cout<<"similarity percentage: "<<100-mutPercent<<"%\n";
	cout<<"mutation percentage: "<<mutPercent<<"%\n";
	cout<<fixed;
	cout<<"insertion percentage: "<<setprecision(2)<<(ins/oriBaseLen)*100<<"%\n";
	cout<<"deletion percentage: "<<setprecision(2)<<(del/oriBaseLen)*100<<"%\n";	
	cout<<"subtitution percentage: "<<setprecision(2)<<(sub/oriBaseLen)*100<<"%\n";
}
else{
	help();
}
return 0;
}

void help(){
	cout<<"alignerReference"<<endl;
	cout<<"Please enter ./ar -i inputFile -o outputFile -m mutationPercentage"<<endl;
	cout<<"-i [required argument] - name of input file (.fasta)\n";
	cout<<"-o [required argument] - name of output file (.fasta)\n";
	cout<<"-m [required argument] - percentage of mutation occur in output file\n";
	cout<<"Thank You\n";
}
