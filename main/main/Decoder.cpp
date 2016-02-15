#include "Decoder.h"
#include <sstream>
#include <utility>
#include <bitset>
#include <algorithm>
#include <bitset>
#include <sstream>

Decoder::Decoder(string fileInfo, string fileData) {
	Decoder::fileInfo = fileInfo;
	Decoder::fileData = fileData;
}

string Decoder::decodeInfo() {
	vector <string> Translations;
	string tempInfo = fileInfo.substr((fileInfo.find("::") + 2), (fileInfo.size() - fileInfo.find("::")));
	int modulo = stoi(fileInfo.substr((fileInfo.find(",") + 2), ((fileInfo.find("::") - fileInfo.find(",")) - 2)));
	stringstream returnData;

	while (tempInfo.size() > 0){
		Translations.push_back(tempInfo.substr(0, tempInfo.find("|*|")));
		tempInfo.erase(0, (tempInfo.find("|*|") + 3));
	}

	string dataToBits = decodeData(modulo);
	string tempOutput = dataToBits;

	while (tempOutput.size() > 0) {
		for (size_t i = 0; i < Translations.size(); i++){
			int translationStringSize = (Translations[i].size() - 1);
			string translationString = Translations[i].substr(1, Translations[i].size());
			string translationChar = Translations[i].substr(0, 1);

			string tempOutputPiece = tempOutput.substr(0, translationStringSize);
			if (translationString == tempOutputPiece){
				returnData << translationChar;
				tempOutput.erase(0, translationStringSize);
			}
		}
	}

	return returnData.str();
}

string Decoder::decodeData(int modulo) {
	stringstream returnData;
	string test;
	for (size_t i = 0; i < (fileData.size() - modulo); i++){
		bitset <8> bitset = fileData[i];
		returnData << bitset.to_string();
	}

	returnData << fileData.substr((fileData.size() - modulo),fileData.size());
	return returnData.str();
}