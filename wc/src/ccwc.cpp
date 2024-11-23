#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	string arg = argv[1];
	string fileName = argv[2];
	
	ifstream file (fileName, ios::binary);
	
	if(!file.is_open()) {
		cerr << "Error: Could not open file" << endl;
		return 1;
	}

	file.seekg(0, ios::end);
	int fileSize = file.tellg();
	cout<<fileSize<<endl;
	return 0;
}
