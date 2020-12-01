#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

struct timedResult {
	int result;
	int timeMs;
};

void printDay(int day, timedResult c1, timedResult c2);
vector<int> readFile(string name);