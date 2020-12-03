#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

struct timedResult {
	long long result;
	int timeMs;
};

void printDay(int day, timedResult c1, timedResult c2);