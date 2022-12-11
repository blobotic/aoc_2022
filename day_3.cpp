#include <bits/stdc++.h>

using namespace std;

int gp(char a) {
	if (islower(a)) return a - 'a' + 1;
	else return a - 'A' + 26 + 1;
}

int get_common(string a, string b, string c = "") {
	int map1[53] = {0}, map2[53] = {0}, map3[53] = {0}; 

	for (int i = 0; i < a.size(); i++) {
		map1[gp(a[i])]++;
	}
	for (int i = 0; i < b.size(); i++) {
		map2[gp(b[i])]++;
	}
	for (int i = 0; i < c.size(); i++) {
		map3[gp(c[i])]++;
	}

	for (int i = 1; i < 53; i++) {
		if (min(min(map1[i], map2[i]),map3[i]) != 0 || (min(map1[i],map2[i]) != 0 && c == "")) return i;
	}

	return 1000000;
}

int main() {
	ifstream input("day_3.txt");

	int total1 = 0, total2 = 0, mod3 = 0;
	string rucksack;
	vector<string> groups(3);

	while (input >> rucksack) {
		string a = rucksack.substr(0, rucksack.length()/2), b = rucksack.substr(rucksack.length()/2);
		total1 += get_common(a,b);

		groups[mod3] = rucksack;
		if (mod3 == 2) total2 += get_common(groups[0], groups[1], groups[2]);
		mod3 = (mod3+1)%3;
	}

	cout << "Part 1: " << total1 << '\n' << "Part 2: " << total2;
}	