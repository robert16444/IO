#include<iostream>

#include"files.h"


using namespace std;


int main() {
	vector<string> files = getFilesArray();
	vector<int> sizes = getFileSizesArray(files);

	for (int i = 0; i < files.size(); i++) {
		cout << files[i] << sizes[i] << "B" << endl;
	}

}