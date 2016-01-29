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

	while (tempInfo.size() > 0){
		Translations.push_back(tempInfo.substr(0, tempInfo.find("|*|")));
		tempInfo.erase(0, (tempInfo.find("|*|") + 3));
	}

	cout << "printed from decoder" << endl;

	for (size_t i = 0; i < Translations.size(); i++){
		cout << Translations[i] << endl;
	}

	string dataToBits = decodeData(modulo);

	cout << dataToBits << endl;

	return "";
}

string Decoder::decodeData(int modulo) {
	stringstream returnData;

	for (size_t i = 0; i < (fileData.size() - (modulo) + 1); i++){
		bitset <8> binary = fileData[i];
		returnData << binary.to_string();
	}

	return returnData.str();
}

/*
int encryptedCount = stoi(fileInfo.substr(1, (fileInfo.find(",")) - 1)), modulo = stoi(fileInfo.substr((fileInfo.find(",") + 2), ((fileInfo.find("::") - fileInfo.find(",")) - 2)));
string temp,tempOutput, dataBitsToString, encryptedLetters = fileInfo.substr((fileInfo.find("::") + 2), (fileInfo.size() - fileInfo.find("::"))), decodedInfo = fileData;
vector <string> Translations;

// loop through encrypted letters
temp = encryptedLetters;

while (temp.size() > 0){
Translations.push_back(temp.substr(0, temp.find("|*|")));
temp.erase(0, (temp.find("|*|") + 3));
}

vector <string> dataToBits = decodeData(modulo);

for (size_t i = 0; i < dataToBits.size(); i++){
dataBitsToString += dataToBits[i];
}

tempOutput = dataBitsToString;

while (tempOutput.size() > 0) {
for (size_t i = 0; i < Translations.size(); i++){
int translationStringSize = (Translations[i].size() - 1);
string translationString = Translations[i].substr(1, Translations[i].size());
string translationChar = Translations[i].substr(0, 1);

string tempOutputPiece = tempOutput.substr(0, translationStringSize);
if (translationString == tempOutputPiece){
cout << endl << "MATCH, letter: " << translationChar << " ERASE: " << tempOutput.substr(0, translationStringSize) << endl;
tempOutput.erase(0, translationStringSize);
}
}
}

return decodedInfo; */