#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int count;
	cin >> count;
	vector<string> strings(count);

	for (int i = 0; i < count; ++i)
		cin >> strings[i];

	sort(begin(strings), end(strings), [](const string& s1, const string& s2) {
		return lexicographical_compare(begin(s1), end(s1), begin(s2), end(s2), [](char a, char b) {
			return tolower(a) < tolower(b);
		});
	});

	for (const string& s : strings)
		cout << s << " ";
	cout << endl;
	return 0;
}
