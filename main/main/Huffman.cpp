#include "Huffman.h"
#include "Book.h"
#include "Level.h"
#include "Library.h"
#include "Translation.h"
#include <sstream>

Huffman::Huffman(string inputLocation) {
	Huffman::inputLocation = inputLocation;
	Huffman::decodingLibrary = buildLibrary();
	Huffman::translation = buildTranslation();
}

vector<Level> Huffman::buildLibrary(){
	ifstream inputFile;
	string inputData, inputLine, dictionaryItem;
	char letter;
	vector<char> lettersFound;
	vector<int> letterOccurance;

	Level level(0);

	inputFile.open(inputLocation);

	if (inputFile.fail()){
		cerr << "Error opening text file" << endl;
		exit(1);
	}

	while (!inputFile.eof()){
		getline(inputFile, inputLine);
		inputData += inputLine;
	}

	for (size_t i = 0; i < inputData.size(); i++){
		letter = inputData[i];
		bool foundLetter = false;
		for (size_t i = 0; i < lettersFound.size(); i++){
			if (lettersFound[i] == letter){ 
				foundLetter = true;
				letterOccurance[i]++;
			} else if (!foundLetter){ 
				foundLetter = false; 
			}
		}

		if (!foundLetter){ 
			lettersFound.push_back(letter);
			letterOccurance.push_back(1);
		}
	}
		
	for (size_t i = 0; i < lettersFound.size(); i++){
		string found(1, lettersFound[i]);
		int occurance = letterOccurance[i];

		Book book(found, occurance);
		level.addBook(book);
	}

	Library library(level);

	return library.library;
}

vector<Translation> Huffman::buildTranslation(){
	vector<Translation> translated;

	for (size_t i = 0; i < decodingLibrary[0].Books.size(); i++){
		Translation translation(decodingLibrary[0].Books[i].letter, decodingLibrary);
		translated.push_back(translation);
	}

	return translated;
}

void Huffman::printLibrary(){
	for (size_t i = 0; i < decodingLibrary.size(); i++){
		decodingLibrary[i].printBooks();
		cout << endl << endl;
	}
}