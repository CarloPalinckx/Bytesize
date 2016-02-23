#include <string>
#include <fstream>
#include <iostream>
#include <bitset>
#include <vector>
#include <sstream>
#include "Book.h"
#include "Level.h"
#include "Library.h"
#include "Translation.h"

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
