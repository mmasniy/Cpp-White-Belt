#include <iostream>
#include <string>
#include <map>

using namespace std;

bool BuildCharCounters(const string& one, const string& two) {
	map<char, int> one_str;
	map<char, int> two_str;

	for (const char& c : one)
		++one_str[c];
	// for (const auto& [key, value] : one_str)
	// 	cout << key << ": " << value << endl;
	for (const char& c : two)
		++two_str[c];
	// for (const auto& [key, value] : two_str)
	// 	cout << key << ": " << value << endl;
	if (one_str == two_str)
		return 1;
	else
		return 0;
}

int main() {
	int iter;
	string one, two;

	cin >> iter;
	for (; iter > 0; iter--){
		cin >> one >> two;
		if (BuildCharCounters(one, two))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
