#include "Convertor.h"
#include "Decoder.h"
#include "Huffman.h"
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <sstream>

Convertor::Convertor(string inputLocation) {
	Convertor::inputLocation = inputLocation;
}


int Convertor::getFileSize(string location){
	if (location == "") location = inputLocation;

	ifstream file(location.c_str(), ifstream::in | ifstream::binary);
	if (!file.is_open()) return -1;

	file.seekg(0, ios::end);
	int fileSize = file.tellg();
	file.close();

	cout << endl << " read file: " << location << ", Filesize: " << fileSize << endl << endl;
	return fileSize;
}

void Convertor::FileToBinary(string outputLocation){
	char letter;
	int fileCount = 0;
	vector<bitset<8>> binaryList;
	string inputData, outputData, inputLine;
	ifstream inputFile;
	ofstream outputFile;

	outputFile.open(outputLocation, ofstream::out | ofstream::trunc);
	inputFile.open(inputLocation);

	if (inputFile.fail()){
		cerr << "Error opening text file" << endl;
		exit(1);
	}

	while (!inputFile.eof()){
		getline(inputFile, inputLine);
		inputData += inputLine;
	}

	for (int i = 0; i < inputData.size(); i++){
		letter = inputData[i];
		bitset <8> binary = letter;
		binaryList.push_back(binary);

		fileCount += 8;
	}

	for (int i = 0; i < binaryList.size(); i++) { outputData += binaryList[i].to_string<char, string::traits_type, string::allocator_type>(); }

	outputFile << outputData;
	outputFile.close();

	cout << " " << inputLocation << "successfully converted to Binary. File contains " << fileCount << " bits" << endl;
}

void Convertor::FileToHuffman(string outputLocation){
	Huffman huffman(inputLocation);
	
	string letter;
	int fileCount = 0, partsAmount = 8;
	string inputData, outputData, inputLine, outputToChars, outputMap;
	ifstream inputFile;
	ofstream outputFile;

	outputFile.open(outputLocation, ofstream::out | ofstream::trunc | ofstream::binary);
	inputFile.open(inputLocation);

	if (inputFile.fail()){
		cerr << "Error opening text file" << endl;
		exit(1);
	}

	while (!inputFile.eof()){
		getline(inputFile, inputLine);
		inputData += inputLine;
	}

	// start overhead

	for (int i = 0; i < inputData.size(); i++){
		letter = inputData[i];

		for (size_t i = 0; i < huffman.translation.size(); i++){
			if (huffman.translation[i].letter == letter){
				outputData += huffman.translation[i].bitset;
			}
		}
	}

	int modulo = outputData.size() % partsAmount;
	
	outputFile << "s" << huffman.translation.size();
	outputFile << ",m" << modulo << "::";

	for (int i = 0; i < huffman.translation.size(); i++){
		string outputString = huffman.translation[i].bitset;
		outputFile << huffman.translation[i].letter << outputString << "|*|";
	}

	outputFile << "::ends";
	
	// end overhead

	string outputToParts = outputData.substr(0, (outputData.size() - modulo));
	int counter = 0;
	
	for (size_t i = 0; i < outputToParts.size(); i = i + partsAmount){
		string part = outputToParts.substr(i, partsAmount);
		bitset <8> binary;

		binary.set();

		for (size_t i2 = 0; i2 < part.size(); i2++){
			int index = ((partsAmount - 1) - i2);
			if (part[i2] == '1') binary.set(index, 0);
		}
		
		binary.flip();
		unsigned char letter = binary.to_ulong();
		outputFile << letter;
	}

	outputFile << outputData.substr((outputData.size() - modulo),outputData.size());
	outputFile.close();

	cout << " " << "successfully compressed: " << inputLocation << endl;
}

bool Convertor::in_vector(vector <string> haystack,string needle){
	for (size_t i = 0; i < haystack.size(); i++) if (haystack[i] == needle) return true;
	return false;
}

void Convertor::HuffmanToFile(string outputLocation){
	string fileInfo, fileDataPiece, fileData;
	ofstream outputFile;

	outputFile.open(outputLocation, ofstream::out | ofstream::trunc);

	std::ifstream inputFile(inputLocation, ios::in | ios::binary);
	std::stringstream buffer;
	buffer << inputFile.rdbuf();

	inputFile.close();

	fileInfo = buffer.str().substr(0, (buffer.str().find("::ends")));
	fileData = buffer.str().erase(0, (buffer.str().find("::ends") + 6));

	Decoder decoder(fileInfo, fileData);

	outputFile << decoder.decodeInfo();
	outputFile.close();
}