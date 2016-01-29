#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>
#include <time.h>

using namespace std;

int main()
{
	clock_t start, finish;
	start = clock();



	finish = clock();
	cout << "program ran for: " << (double(finish - start) / CLOCKS_PER_SEC) << "s";

	return 0;
}

void buildFileBytes() {

	/* TODO: FILE SELECT */

	char letter = ' ';
	vector<bitset<8>> binaryList;

	string inputData, outputData, inputLine;
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open("input.txt");
	outputFile.open("output.txt", ofstream::out | ofstream::trunc);

	while (!inputFile.eof()){
		getline(inputFile, inputLine);
		inputData += inputLine;
	}

	for (int i = 0; i < inputData.size(); i++){
		letter = inputData[i];
		bitset <8> binary = letter;
		binaryList.push_back(binary);
	}

	for (int i = 0; i < binaryList.size(); i++){
		outputData += binaryList[i].to_string<char, string::traits_type, string::allocator_type>();
	}

	outputFile << outputData;
	outputFile.close();

	if (inputFile.fail()){
		cerr << "Error opening text file" << endl;
		exit(1);
	}
}