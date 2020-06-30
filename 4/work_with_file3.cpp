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
			cout << fixed << setprecision(3);
			cout << stod(out) << endl;
		}
	}
	return 0;
}
