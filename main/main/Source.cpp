#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>
#include <time.h>

#include "Convertor.h"
#include "Huffman.h"

using namespace std;

int main(){

	cout << " ===========================" << endl;
	cout << "  HUFFMAN TEXT COMPRESSION " << endl;
	cout << " ===========================" << endl;
	cout << " (a) Compress" << endl;
	cout << " (b) Decompress" << endl;

	char mode = 'x';
	while (mode == 'x'){
		
		cout << "\n Choose mode (a/b): ";
		cin >> mode;
	
		if (mode == 'a'){
			mode = 'a';
			char playAgain = 'y';
			while (playAgain == 'y'){

				clock_t start, finish;

				//

				int fullCount, compressedCount;
				string inputLabel, outputLabel;

				bool run = false;

				while (!run){
					cout << "\n enter input location: ";
					cin >> inputLabel;

					if (inputLabel.size() > 4 && inputLabel.substr((inputLabel.size() - 4), 4) == ".txt")run = true;
					else {
						cout << "\n File can only be a .txt file \n";
						run = false;
					}
				}

				run = false;

				while (!run){
					cout << " enter output location: ";
					cin >> outputLabel;

					if (outputLabel.size() > 4 && outputLabel.substr((outputLabel.size() - 4), 4) == ".txt")run = true;
					else {
						cout << "\n File can only be a .txt file\n";
						run = false;
					}
				}

				cout << endl << " compressing....." << endl;

				start = clock();

				Convertor convertor(inputLabel);
				fullCount = convertor.getFileSize(inputLabel);
				convertor.FileToHuffman(outputLabel);
				compressedCount = convertor.getFileSize(outputLabel);

				if (compressedCount > 0) cout << endl << " Compressed your file with: " << (fullCount - compressedCount) / (fullCount / 100) << "%" << endl;

				//

				finish = clock();
				cout << " program ran for: " << (double(finish - start) / CLOCKS_PER_SEC) << "s";

				cout << "\n\n Try again? (y/n) ";
				cin >> playAgain;

				if (playAgain != 'y'){
					cout << "\n\nExiting program.";
					playAgain = 'n';
					mode = 'a';
				}
			}

		} else if (mode == 'b'){
			mode = 'b';
			char playAgain = 'y';
			while (playAgain == 'y'){

				clock_t start, finish;

				//

				string inputLabel, outputLabel;

				bool run = false;

				while (!run){
					cout << "\n enter input location: ";
					cin >> inputLabel;

					if (inputLabel.size() > 4 && inputLabel.substr((inputLabel.size() - 4), 4) == ".txt")run = true;
					else {
						cout << "\n File can only be a .txt file \n";
						run = false;
					}
				}

				run = false;

				while (!run){
					cout << " enter output location: ";
					cin >> outputLabel;

					if (outputLabel.size() > 4 && outputLabel.substr((outputLabel.size() - 4), 4) == ".txt")run = true;
					else {
						cout << "\n File can only be a .txt file\n";
						run = false;
					}
				}

				cout << endl << " Decompressing....." << endl;

				start = clock();

				Convertor convertor(inputLabel);
				convertor.HuffmanToFile(outputLabel);

				cout << endl << " File succesfull decompressed" << endl;

				//

				finish = clock();
				cout << " program ran for: " << (double(finish - start) / CLOCKS_PER_SEC) << "s";

				cout << "\n\n Try again? (y/n) ";
				cin >> playAgain;

				if (playAgain != 'y'){
					cout << "\n\nExiting program.";
					playAgain = 'n';
					mode = 'a';
				}
			}
		} else {
			mode = 'x';
		}

		cin.ignore();
	}
	return 0;
}