#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	string arg = argv[1];
	string fileName = argv[2];
	
	if (arg == "-c") {
		ifstream file (fileName, ios::binary);
	
		if (!file.is_open()) {
			cerr << "Error: Could not open file" << endl;
			return 1;
		}

		file.seekg(0, ios::end);
		int fileSize = file.tellg();
		cout<<fileSize<<" "<<fileName<<endl;
		return 0;
	} else if (arg == "-l") {
		int count = 0;	
		string line;
		ifstream file (fileName);
		while (getline(file, line)) {
			count++;
		}
		cout<<count<<" "<<fileName<<endl;
		return 0;
	}
	cout<<"Invalid Arg"<<endl;
	return 1;
}
