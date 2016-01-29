#include "Level.h"
#include "Book.h"

Level::Level(int i = 0) {
	Level::i = i;
	Level::binarySwitch = 0;
	Level::totalOccurance = 0;
}

void Level::addBook(Book BookToAdd){
	if (Books.size() > 0){
		bool higher = true;
	
		// sort book
		for (size_t i = 0; i < Books.size(); i++){
			if (BookToAdd.occurance < Books[i].occurance){
				Books.insert(Books.begin() + i, BookToAdd);
				higher = false;
				break;
			}
		}
		if (higher) Books.insert(Books.end(), BookToAdd);
	} else {
		Books.push_back(BookToAdd);
	}

	totalOccurance += BookToAdd.occurance;
}

void Level::assignInfo(){
	bool toggle = 1;
	
	for (size_t i = 0; i < Books.size(); i++){
		Books[i].occurancePercentage = ((double) Books[i].occurance / ((double) totalOccurance / 100));

		Books[i].binaryMatch = toggle;
		(toggle) ? toggle = 0 : toggle = 1;	
	}
}

void Level::printBooks(){
	for (size_t i = 0; i < Books.size(); i++){
		Books[i].printBook();
	}
}