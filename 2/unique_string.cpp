#include <iostream>
#include <set>

using namespace std;

int main() {
	int iter;
	set<string> unique;

	cin >> iter;
	for(; iter > 0; --iter) {
		string input;

		cin >> input;
		unique.insert(input);
	}
	cout << unique.size() << endl;
	return 0;
}