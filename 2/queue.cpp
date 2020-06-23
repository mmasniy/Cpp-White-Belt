#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int number, iteration;
	string input;
	vector<bool> persons;

	for (cin >> iteration; iteration > 0; --iteration) {
		cin >> input;
		if ("WORRY_COUNT" == input)
			cout << count(persons.begin(), persons.end(), 1) << endl;
		else {
			cin >> number;
			if ("WORRY" == input)
				persons[number] = 1;
			else if ("QUIET" == input)
				persons[number] = 0;
			else if ("COME" == input)
				persons.resize(persons.size() + number, 0);
		}
	}
	return 0;
}
