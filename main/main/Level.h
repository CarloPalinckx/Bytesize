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
		int index;
		int totalOccurance;
		void addBook(Book);
		void printBooks();
		void assignInfo();
		vector <Book> books;
};

#endif
