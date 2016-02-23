#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#ifndef Book_H
#define Book_H

using namespace std;

class Book {
public:
	Book(string letter = "", int occurance = 0);
	string letter;
	int occurance;
	bool skip;
	double occurancePercentage;
	bool binaryMatch;
	void printBook();
	void shredBook();
	void overwriteBook(Book);
private:

};

#endif
