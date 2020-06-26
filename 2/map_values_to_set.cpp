#include <iostream>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> unique_map_value;

	for (const auto& [key, value] : m)
		unique_map_value.insert(value);
	return unique_map_value;
}

int main() {
	map<int, string> m = {
    {1, "odd"},
    {2, "even"},
    {3, "odd"},
    {4, "even"},
    {5, "odd"}};

    set<string> str = BuildMapValuesSet(m);
    for (const string& s : str)
    	cout << s << endl;
}