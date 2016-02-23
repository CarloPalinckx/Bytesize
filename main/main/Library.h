#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "Level.h"
#include "Book.h"

#ifndef Library_H
#define Library_H

using namespace std;

class Library {
public:
	Library(Level);
	void addLevel(Level);
	void printLevels();
	vector <Level> levels;
private:
	int mergeBooks(Level,int);
};

#endif
