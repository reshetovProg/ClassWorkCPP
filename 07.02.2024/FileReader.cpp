
#include "FileReader.h"
#include "fstream"
#include <string>

Lines FileReader::read(string path)
{
	Lines lines;
	string buf;
	ifstream in(path);
	if (in.is_open()) {
		while (getline(in, buf)) {
			lines.push_back(buf);
		}
	}
	in.close();
	return lines;
}
