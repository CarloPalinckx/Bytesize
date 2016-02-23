#include <string>
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <sstream>
#include "Decoder.h"
#include "Huffman.h"

using namespace std;

#ifndef Convertor_H
#define Convertor_H

class Convertor {
public:
	Convertor(string inputLocation = "null");
	void FileToBinary(string outputLocation = "null");
	void FileToHuffman(string outputLocation = "null");
	void HuffmanToFile(string outputLocation = "null");
	int getFileSize(string location = "");
private:
	string inputLocation;
};

#endif
