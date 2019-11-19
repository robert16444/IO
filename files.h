#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<filesystem>

namespace fs = std::filesystem;

std::vector<std::string> getFilesArray() {

	auto dir = ".";
	std::vector<std::string> filesList;
	for (auto item : fs::recursive_directory_iterator(dir))
	{
		if (!fs::is_regular_file(item.path()) || item.path().extension() != ".cpp" && item.path().extension() != ".h" && item.path().extension() != ".hpp")
			continue;
		filesList.push_back(item.path().string().substr(2));
	}

	return filesList;
}

std::vector<int> getFileSizesArray(std::vector<std::string> files) {
	std::vector<int> Sizes;

	for (auto i = 0; i < files.size(); i++) {
		Sizes.push_back(fs::file_size(files[i]));
	}

	return Sizes;
}

void genCfg(std::vector<std::string> filesList){
	std::fstream file;
	file.open("files.txt",std::ios::out);
	for (auto i = 0; i < filesList.size(); i++) {
		file << filesList[i]<<std::endl;
	}
	file.close();
}

