#include "Utils.h"

void printDay(int day, timedResult c1, timedResult c2) {
	cout << "Day " << day << endl;
	cout << "\t1: " << c1.result << " (" << c1.timeMs << "us)" << endl;
	cout << "\t2: " << c2.result << " (" << c2.timeMs << "us)" << endl;
	return;
}

vector<int> readFile(string filename) {
	string line;
	ifstream file(filename);
	vector<int> out;

	while (getline(file, line)) {
		out.push_back(stoi(line));
	}
	file.close();
	return out;
}