
/* 

----- HUFFMAN CLASS -----

FUNCTION DESCRIPTIONS:
- buildDictionary(): 


USED FOR:


REQUIRES:
- LOCATION OF THE INPUT FILE
- LOCATION TO CREATE OUTPUT FILE

*/

#include <string>
#include <fstream>
#include <iostream>
#include <bitset>
#include <vector>
#include "Level.h"
#include "Translation.h"
#include "Library.h"

#ifndef Huffman_H
#define Huffman_H

using namespace std;

class Huffman {
public:
	Huffman(string inputLocation = "null");

	vector<Translation> translation;
	vector<Translation>buildTranslation();
	void printLibrary();
private:	
	vector<Level> decodingLibrary;
	vector<Level> buildLibrary();
	string inputLocation;
};

#endif
