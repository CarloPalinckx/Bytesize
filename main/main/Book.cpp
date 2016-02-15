#include "Book.h"

Book::Book(string letter, int occurance) {
	Book::letter = letter;
	Book::occurance = occurance;
	Book::skip = false;
}

void Book::printBook(){
	cout << "--------------------------------------------" << endl;
	cout << " " << letter;
	cout << " | " << occurance;
	cout << " | " << occurancePercentage << "%";
	cout << " | skip: " << skip;
	cout << " | bin: " << binaryMatch << endl;
}

void Book::shredBook(){
	letter = "";
	occurance = 0;
	skip = true;
	occurancePercentage = 0;
	binaryMatch = 0;
};

void Book::overwriteBook(Book book){
	letter = book.letter;
	occurance = book.occurance;
	skip = book.skip;
	occurancePercentage = book.occurancePercentage;
	binaryMatch = book.binaryMatch;
}