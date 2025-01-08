#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <codecvt>

using namespace std;

void getBytes(string fileName);
void getLines(string fileName);
void getChars(string fileName);
void getWords(string fileName);
void printFileName(string fileName);

int main(int argc, char *argv[]) {
	string arg = argv[1];
	string fileName = argv[2];

	if (arg == "-c") {
		getBytes(fileName);
	} else if (arg == "-l") {
		getLines(fileName);
	} else if (arg == "-w") {
		getWords(fileName);
	} else if (arg == "-m") {
		getChars(fileName);
	} else {
		getBytes(fileName);
		getLines(fileName);
		getWords(fileName);
		getChars(fileName);
	}
	printFileName(fileName);
	return 0;
}

void getBytes(string fileName) {
	ifstream file (fileName, ios::binary);
	
	if (!file.is_open()) {
	cerr << "Error: Could not open file" << endl;
	//	return 1;
	}

	file.seekg(0, ios::end);
	int fileSize = file.tellg();
	cout<<fileSize<<" ";
}

void getLines(string fileName) {
	int count = 0;	
	string line;
	ifstream file (fileName);
	while (getline(file, line)) {
		count++;
	}
	cout<<count<<" ";
}

void getWords(string fileName) {
	string word;
	int wordCount = 0;
	ifstream file (fileName);
	while (file >> word) {
		wordCount++;
	}
	cout<<wordCount<<" ";
}

void getChars(string fileName) {
	// Setting the locale
  setlocale(LC_ALL, "");

	char ch;
	int charCount = 0;
	ifstream file (fileName);
	/*
	while (file.get(ch)) {
		charCount++;
	}
	*/	
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	std::wstring wcontent = converter.from_bytes(content);
	cout<<wcontent.length()<<" ";
}

void printFileName(string fileName) {
	cout<<fileName<<endl;
}
