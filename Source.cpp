#include<iostream>

#include"files.h"


using namespace std;


int main() {
	vector<string> files = getFilesArray();

	for (int i = 0; i < files.size(); i++) {
		cout << files[i] << endl;
	}

	genCfg(files);
}