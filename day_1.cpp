#include <bits/stdc++.h>

using namespace std;


int main() {
	ifstream input("day_1.txt");

	int total = 0;
	vector<int> calories; 
	string line;

	while (getline(input, line)) {
		if (line.size() < 2) {
			calories.push_back(total);
			total = 0;
		}
		else total += stoi(line);
	}

	sort(calories.begin(), calories.end(), greater<int>());

	std::cout << 	"Part 1: " << calories[0] << '\n' << 
					"Part 2: " << calories[0] + calories[1] + calories[2];
}	