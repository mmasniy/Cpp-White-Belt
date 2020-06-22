#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (auto s : source)
		destination.push_back(s);
	source.clear();
}

// int main() {
// 	vector<string> a = {"a", "b", "c"};
// 	vector<string> b = {"y", "x", "z"};

// 	MoveStrings(a, b);
// 	if (a.empty()) {
// 		cout << "a is empty" << endl;
// 	}
// 	for (auto i : b)
// 		cout << i << endl;
// 	return 0;
// }
