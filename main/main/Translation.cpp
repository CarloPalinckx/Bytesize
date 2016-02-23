#include "Translation.h"

Translation::Translation(string letter,vector<Level> levels) {
	Translation::letter = letter;
	Translation::bitset;
	bool breakLoop = false;

	for (int i = (levels.size() - 1); i >= 0; i--){
		if (breakLoop == false){
			for (size_t i2 = 0; i2 < levels[i].books.size(); i2++){
				if (levels[i].books[i2].letter.find(letter) != string::npos /*&& !levels[i].Books[i2].skip*/ && breakLoop == false){
					stringstream bitToString;
					bitToString << levels[i].books[i2].binaryMatch;
					Translation::bitset += bitToString.str();

					if (levels[i].books[i2].letter.length() == 1) {
						breakLoop = true;
					}
				}
			}
		}
	}
}

