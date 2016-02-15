
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
#include <algorithm>
#include "Book.h"

#ifndef Level_H
#define Level_H

using namespace std;

class Level {
public:
	Level(int i);
	int i;
	int totalOccurance;
	void addBook(Book);
	void printBooks();
	void assignInfo();
	vector <Book> Books;
	void shredLevel();
private:
	bool binarySwitch;
};

#endif
