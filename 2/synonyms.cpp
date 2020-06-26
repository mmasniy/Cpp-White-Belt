#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
	int iter;
	map<string, set<string>> synonyms;

	cin >> iter;
	for(; iter > 0; --iter) {
		string operation;

		cin >> operation;
		if (operation == "ADD") {
			string first, second;

			cin >> first >> second;
			synonyms[first].insert(second);
			synonyms[second].insert(first);
		}
		else if (operation == "COUNT") {
			string word;

			cin >> word;
			cout << synonyms[word].size() << endl;
		}
		else if (operation == "CHECK") {
			string first, second;

			cin >> first >> second;
			if (synonyms[first].count(second) == 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}