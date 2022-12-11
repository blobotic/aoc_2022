#include <bits/stdc++.h>

using namespace std;


int main() {
	ifstream input("day_2.txt");

	// A,X = rock
	// B,Y = paper
	// C,Z = scissors

	// X = lose
	// Y = draw
	// Z = win

	int total1 = 0, total2 = 0;
	char a, b;

	while (input >> a >> b) {
		// the shape you selected
		total1 += b - 'W';

		total2 += (a - 'A' + b - 'Y' + 3)%3 + 1;

		// outcome of the round
		// draw: gain 3 points
		if (b - 'X' == a - 'A') total1 += 3;
		// win: gain 6 points
		else if (b - 'X' == (a - 'A' + 1)%3) total1 += 6;

		total2 += 3 * (b - 'X');
	}

	cout << "Part 1: " << total1 << '\n' << "Part 2: " << total2;

}	