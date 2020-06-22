#include <iostream>
#include <string>
#include <vector>

using namespace std;

static bool IsPalindrom(string pol) {
	if (pol.empty())
		return true;
	for (int i = 0, j = pol.size() - 1; (i < pol.size() / 2); ++i, --j) {
		if (pol[i] != pol[j])
			return false;
	}
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> contain;

	for (auto w : words) {
		if (w.size() >= minLength && IsPalindrom(w))
			contain.push_back(w);
	}
	return contain;
}

int main(){
	vector<string> words = {"weew", "bro", "code", "meem", "tadat", "", "tut a tut"};
	vector<string> v;
	int len;

	cin >> len;

	v = PalindromFilter(words, len);
	for (auto x : v)
		cout << x << " ";
	cout << endl;
	return 0;
}
