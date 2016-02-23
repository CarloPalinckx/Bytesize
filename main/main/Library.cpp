#include "Library.h"

Library::Library(Level level){
	levels.push_back(level);
	int factor = 1;

	for (size_t i = 0; i < levels.size(); i++) levels[i].assignInfo();
	for (size_t i = 0; i < levels.size(); i++) factor = mergeBooks(levels[i], factor);
}

void Library::addLevel(Level level){
	levels.push_back(level);
}

int Library::mergeBooks(Level level, int factor){
	Level newLevel(0);
	bool toggle = false;
	Book merged("", 0);

	for (size_t i = 0; i < level.books.size(); i++){
		if (i < level.books.size() - 1){
			if ((level.books[i + 1].occurancePercentage - level.books[i].occurancePercentage) <= factor){
				merged.overwriteBook(level.books[i]);
				merged.letter += level.books[i + 1].letter;
				merged.occurance += level.books[i + 1].occurance;
				merged.occurancePercentage += level.books[i + 1].occurancePercentage;
				merged.skip = false;
				newLevel.addBook(merged);

				i++;
			} else {
				if (!toggle){
					factor = (level.books[i + 1].occurancePercentage - level.books[i].occurancePercentage) + 1;
					toggle = true;
				}

				merged.overwriteBook(level.books[i]);
				merged.skip = true;

				newLevel.addBook(merged);
			}
		} else {
			if (level.books.size() > 1){
				merged.overwriteBook(level.books[i]);
				merged.skip = true;
				newLevel.addBook(merged);
			}
		}
	}

	newLevel.assignInfo();
	if (newLevel.books.size() > 1) levels.push_back(newLevel);

	return factor;
}

void Library::printLevels(){
	for (size_t i = 0; i < levels.size(); i++){
		levels[i].printBooks();
		cout << "\n -------------------------------------------------------- \n" << endl;
	}
}