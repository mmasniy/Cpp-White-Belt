#include <iostream>
#include <vector>

using namespace std;

int main() {
	int number;
	vector<int> binary;

	cin >> number;
	if (number == 0)
		cout << "0" << endl;
	while (number > 0) {
		binary.push_back(number % 2);
		number /= 2;
	}
	for (int i = binary.size() - 1; i >= 0; --i)
		cout << binary[i];
	return 0;
}
