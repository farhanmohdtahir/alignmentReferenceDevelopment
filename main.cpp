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

void help();

int main(int argc, char * argv []){
	int oriBaseLen, opt=0;
	double  mutPercent=-1, insPercent, delPercent, subPercent, ins=0, del=0, sub=0;
	string in="sequence.fasta", out="takTahu0.fasta", outAlign="",  oriBase="", newBaseStr="", alignBaseStr;
	bool option=false;

//getopt function	
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
    
    if (in!="" && out!="" && mutPercent>=0){
		oriBase=encodebase(in);
		oriBaseLen=oriBase.length();
		
		int  mutBase[oriBaseLen], mutType[oriBaseLen];
		
		if (mutPercent==0)				//if there is percentage of mutation 
		{
			newBaseStr=oriBase; 							
		}
		
		else{							//if there is percentage of mutation 
			assignMut(mutPercent, oriBaseLen, mutType, mutBase);					   //Assign mutation to random residue
			newBaseStr=insertMut(oriBaseLen, mutType, mutBase, oriBase, ins, del, sub);//Apply mutation to the residue
	}
	
	mutBaseDisp( out, newBaseStr, mutPercent);	//producing Simulated Sample Sequence file (.fasta)

	//producing reference alignment file (.txt)
	printAlign(in, out, ins, del, sub, mutPercent, oriBaseLen, oriBase, newBaseStr, mutType, mutBase); 
}
else{
	help(); //display help function on how to use the alignerProgram
}
return 0;
}

void help(){
	cout<<"alignerReference"<<endl;
	cout<<"Usage: ./ar -i inputFile -o outputFile -m mutationPercentage"<<endl;
	cout<<"-i [required argument] - name of input file (.fasta)\n";
	cout<<"-o [required argument] - name of output file (.fasta)\n";
	cout<<"-m [required argument] - percentage of mutation occur in output file (>=0)\n";
	cout<<"Thank You\n";
}
