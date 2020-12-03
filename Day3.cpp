#include "Days.h"

vector<vector<bool>> readDay3File(string filename);

timedResult Day3Challenge1() {
	vector<vector<bool>> input = readDay3File("d3.txt");
	auto start = high_resolution_clock::now();
	timedResult out{ 0 };

	int posX = 0;
	int width = input[0].size();

	for (int posY = 0; posY < input.size(); posY++) {
		out.result += input[posY][posX];
		posX = (posX + 3) % width;
	}

	out.timeMs = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
	return out;
}

timedResult Day3Challenge2() {
	vector<vector<bool>> input = readDay3File("d3.txt");
	auto start = high_resolution_clock::now();
	timedResult out{ 0 };

	int width = input[0].size();

	int movementX[5] = { 1,3,5,7,1 };
	int movementY[5] = { 1,1,1,1,2 };

	int posX[5] = { 0 };
	int posY[5] = { 0 };

	long long treeCount[5] = { 0 };

	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (i % movementY[j] != 0) {
				continue;
			}
			treeCount[j] += input[posY[j]][posX[j]];

			posX[j] = (posX[j] + movementX[j]) % width;
			posY[j] += movementY[j];
		}
	}

	out.result = 1;
	for (int j = 0; j < 5; j++) {
		out.result *= treeCount[j];
	}

	out.timeMs = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
	return out;
}

// false: no tree
// true: tree
vector<vector<bool>> readDay3File(string filename) {
	string line;
	ifstream file(filename);
	vector<vector<bool>> out;

	while (getline(file, line)) {
		vector<bool> row;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '.') {
				row.push_back(false);
			}
			else {
				row.push_back(true);
			}
		}
		out.push_back(row);
	}
	file.close();
	return out;
}