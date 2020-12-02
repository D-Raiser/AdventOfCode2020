#include "Days.h"

struct day2Input {
	int minNum;
	int maxNum;
	char character;
	string password;
};

vector<day2Input> readDay2File(string filename);

timedResult Day2Challenge1() {
	vector<day2Input> input = readDay2File("d2.txt");
	auto start = high_resolution_clock::now();
	timedResult out{};

	for (int i = 0; i < input.size(); i++) {
		int cnt = count(input[i].password.begin(), input[i].password.end(), input[i].character);
		if (cnt >= input[i].minNum && cnt <= input[i].maxNum) {
			out.result += 1;
		}
	}

	out.timeMs = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
	return out;
}

timedResult Day2Challenge2() {
	vector<day2Input> input = readDay2File("d2.txt");
	auto start = high_resolution_clock::now();
	timedResult out{};

	for (int i = 0; i < input.size(); i++) {
		int cnt = count(input[i].password.begin(), input[i].password.end(), input[i].character);
		char c1 = input[i].password[input[i].minNum-1];
		char c2 = input[i].password[input[i].maxNum-1];
		if ((c1 == input[i].character && c2 != input[i].character) || (c1 != input[i].character && c2 == input[i].character)) {
			out.result += 1;
		}
	}

	out.timeMs = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
	return out;
}

vector<day2Input> readDay2File(string filename) {
	string line;
	ifstream file(filename);
	vector<day2Input> out;

	while (getline(file, line)) {
		day2Input in;
		int idx = line.find("-");
		in.minNum = stoi(line.substr(0, idx));
		line = line.substr(idx + 1);
		idx = line.find(" ");
		in.maxNum = stoi(line.substr(0,idx));
		in.character = line[idx + 1];
		in.password = line.substr(idx + 4);
		out.push_back(in);
	}
	file.close();
	return out;
}