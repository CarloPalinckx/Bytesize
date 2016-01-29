
/*

----- LEVEL CLASS -----

FUNCTION DESCRIPTIONS:


USED FOR:


REQUIRES:


*/

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "Level.h"

#ifndef Library_H
#define Library_H

using namespace std;

class Library {
public:
	Library(Level);
	vector <char> translation;
	void addLevel(Level);
	void printLibrary();
	vector <Level> library;
	int translateLetter();
private:
	int mergeBooks(Level,int);
	vector <char> buildTranslation();
	void sweepLibrary();
};

#endif
