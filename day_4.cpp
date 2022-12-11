#include <bits/stdc++.h>

using namespace std;


int main() {
	ifstream input("day_4.txt");

	int total1 = 0, total2 = 0;
	string line;

	while (getline(input, line)) {
		// split string
		vector<int> w;
		int prev = 0, pos;
		while ((pos = line.find_first_of("-,", prev)) != std::string::npos) {
			if (pos > prev) w.push_back(stoi(line.substr(prev, pos-prev)));
			prev = pos+1;
		}
		if (prev < line.length()) w.push_back(stoi(line.substr(prev, std::string::npos)));

		if ((w[0] <= w[2] && w[1] >= w[3]) || (w[0] >= w[2] && w[1] <= w[3])) total1++;

		if ((w[1] >= w[2] && w[0] <= w[2]) || (w[3] >= w[0] && w[2] <= w[0])) total2++;
	}

	cout << "Part 1: " << total1 << '\n' << "Part 2: " << total2;
}	