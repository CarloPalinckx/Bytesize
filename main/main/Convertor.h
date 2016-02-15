#include <string>
#include <vector>

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
	bool in_vector(vector <string> haystack, string needle);
private:
	string inputLocation;
};

#endif
