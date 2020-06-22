#include <iostream>
#include <string>

using namespace std;

int main() {
	string first;
	string second;
	string third;

	cin >> first >> second >> third;
	if (first <= second && first <= third) {
		cout << first << endl;
	}
	else if (second <= first && second <= third) {
		cout << second << endl;
	}
	else
		cout << third << endl;
	return 0;
}
