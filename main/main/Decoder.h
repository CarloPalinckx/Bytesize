#include <string>
#include <vector>
#include <utility>
#include <bitset>
#include <algorithm>
#include <sstream>
#include "Book.h"

using namespace std;

#ifndef Decoder_H
#define Decoder_H

class Decoder {
public:
	Decoder(string fileInfo,string fileData);
	string decodeInfo();
private:
	string fileInfo;
	string fileData;
	string decodeData(int);
};

#endif
