#include "Library.h"
#include "Level.h"
#include "Book.h"

Library::Library(Level level){
	library.push_back(level);
	int factor = 1;

	for (size_t i = 0; i < library.size(); i++) library[i].assignInfo();
	for (size_t i = 0; i < library.size(); i++) factor = mergeBooks(library[i], factor);
}

void Library::addLevel(Level level){
	library.push_back(level);
}

int Library::mergeBooks(Level level, int factor){
	Level newLevel(0);
	bool toggle = false;
	Book merged("", 0);

	for (size_t i = 0; i < level.Books.size(); i++){
		if (i < level.Books.size() - 1){
			if ((level.Books[i + 1].occurancePercentage - level.Books[i].occurancePercentage) <= factor){
				merged.overwriteBook(level.Books[i]);
				merged.letter += level.Books[i + 1].letter;
				merged.occurance += level.Books[i + 1].occurance;
				merged.occurancePercentage += level.Books[i + 1].occurancePercentage;
				merged.skip = false;
				newLevel.addBook(merged);

				i++;
			} else {
				if (!toggle){
					factor = (level.Books[i + 1].occurancePercentage - level.Books[i].occurancePercentage) + 1;
					toggle = true;
				}

				merged.overwriteBook(level.Books[i]);
				merged.skip = true;

				newLevel.addBook(merged);
			}
		} else {
			if (level.Books.size() > 1){
				merged.overwriteBook(level.Books[i]);
				merged.skip = true;
				newLevel.addBook(merged);
			}
		}
	}

	newLevel.assignInfo();
	if (newLevel.Books.size() > 1) library.push_back(newLevel);

	return factor;
}

void Library::printLibrary(){
	for (size_t i = 0; i < library.size(); i++){
		library[i].printBooks();
		cout << "\n -------------------------------------------------------- \n" << endl;
	}
}