#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");

	if (input) {
		string out;
		while (getline(input, out)) {
			output << out << endl;
		}
	}
	return 0;
}
