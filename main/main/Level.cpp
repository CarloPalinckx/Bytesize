#include "Level.h"

Level::Level(int i = 0) {
	Level::index = i;
	Level::totalOccurance = 0;
}

void Level::addBook(Book BookToAdd){
	if (books.size() > 0){
		bool higher = true;
	
		// sort book
		for (size_t i = 0; i < books.size(); i++){
			if (BookToAdd.occurance < books[i].occurance){
				books.insert(books.begin() + i, BookToAdd);
				higher = false;
				break;
			}
		}

		if (higher) books.insert(books.end(), BookToAdd);

	} else {
		books.push_back(BookToAdd);
	}

	totalOccurance += BookToAdd.occurance;
}

void Level::assignInfo(){
	bool toggle = 1;
	
	for (size_t i = 0; i < books.size(); i++){
		books[i].occurancePercentage = ((double) books[i].occurance / ((double) totalOccurance / 100));

		books[i].binaryMatch = toggle;
		(toggle) ? toggle = 0 : toggle = 1;	
	}
}

void Level::printBooks(){
	for (size_t i = 0; i < books.size(); i++){
		books[i].printBook();
	}
}