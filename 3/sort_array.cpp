#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int count;
	cin >> count;
	vector<int> numbers(count);
	for (int i = 0; i < count; ++i)
		cin >> numbers[i];
	sort(begin(numbers), end(numbers), [](int a, int b) {return abs(a) < abs(b);});
	for (const auto& n : numbers)
		cout << n << " ";
	cout << endl;
	return 0;
}