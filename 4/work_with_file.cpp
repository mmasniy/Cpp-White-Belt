#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	ifstream input ("input.txt");
	if (input) {
		string out;
		while (getline(input, out)) {
			cout << out << endl;
		}
	}
	return 0;
}
