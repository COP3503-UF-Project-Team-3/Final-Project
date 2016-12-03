#include <fstream>
#include <iostream>
#include "json-util.h"

using namespace std;

JSON jsonFromFile(string path) {
	// Serialize the entire file into a string
	string str = "";
	string line;
	ifstream file(path);
	if (file.is_open()) {
		while (getline(file, line)) {
			str += line + "\n";
		}
		file.close();
	}
	JSON json = JSON::parse(str); // parse requires raw string of JSON
	return json;
}

bool writeJSON(JSON obj, string path) {
	ofstream file(path);
	file << obj.dump(4); // arg is number of spaces per indent
	file.close();
	return !file.bad();
}