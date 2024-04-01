#include "FileManager.h"

vector<string> FileManager::readFile(string path)
{
	ifstream in(path);
	string buf;
	vector<string> array;
	if (in.is_open()) {
		while (getline(in, buf)) {
			array.push_back(buf);
		}
	}
	in.close();
	return array;
}

void FileManager::writeFile(string path, vector<string> str)
{
	ofstream out(path);
	for (auto el : str) {
		out << el <<endl;
	}
	out.close();
}

vector<string> FileManager::split(string str, char div)
{
	vector<string> array;
	string buf = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == div) {
			array.push_back(buf);
			buf = "";
		}
		else {
			buf += str[i];
		}
	}
	return array;
}
