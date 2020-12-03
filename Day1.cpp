#include "Days.h"

vector<int> readFile(string name);

timedResult Day1Challenge1() {
	vector<int> input = readFile("d1.txt");
	auto start = high_resolution_clock::now();
	timedResult out{};

	set<int> inputSet;

	for (int i = 0; i < input.size(); i++) {
		int v1 = input[i];
		auto pos = inputSet.find(2020 - v1);
		if (pos != inputSet.end()) {
			out.result = *pos * v1;
			break;
		}
		inputSet.insert(v1);
	}

	out.timeMs = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
	return out;
}

timedResult Day1Challenge2() {
	vector<int> input = readFile("d1.txt");
	auto start = high_resolution_clock::now();
	timedResult out{};

	set<int> inputSet;
	bool found = false;

	for (int i = 0; !found && i < input.size(); i++) {
		int v1 = input[i];
		for (set<int>::iterator itr = inputSet.begin(); itr != inputSet.end(); ++itr) {
			int v2 = *itr;
			
			if (v1 + v2 >= 2020) {
				break;
			}

			auto pos = inputSet.find(2020 - v1 - v2);
			if (pos != inputSet.end()) {
				out.result = *pos * v1 * v2;
				found = true;
				break;
			}
		}
		inputSet.insert(v1);
	}

	out.timeMs = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
	return out;
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