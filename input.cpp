#include "input.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string encodebase (string in1){
	int i=0;
	ifstream infile1, infile2;
	string line, totalLine="";
	infile1.open(in1.c_str());
	while(getline(infile1, line)){	
		if(line[i]!='>'){
		totalLine=totalLine+line;
	}	
	}	
	return totalLine;
	infile1.close();
}
