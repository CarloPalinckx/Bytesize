#include <sstream>
#include "Translation.h"

Translation::Translation(string letter,vector<Level> library) {
	Translation::letter = letter;
	Translation::bitset;
	bool breakLoop = false;

	for (int i = (library.size() - 1); i >= 0; i--){
		if (breakLoop == false){
			for (size_t i2 = 0; i2 < library[i].Books.size(); i2++){
				if (library[i].Books[i2].letter.find(letter) != string::npos /*&& !library[i].Books[i2].skip*/ && breakLoop == false){
					stringstream bitToString;
					bitToString << library[i].Books[i2].binaryMatch;
					Translation::bitset += bitToString.str();

					if (library[i].Books[i2].letter.length() == 1) {
						breakLoop = true;
					}
				}
			}
		}
	}
}

