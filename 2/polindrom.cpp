#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string pol) {
	if (pol.empty())
		return true;
	for (int i = 0, j = pol.size() - 1; (i < pol.size() / 2); ++i, --j) {
		if (pol[i] != pol[j])
			return false;
	}
	return true;
}

int main(){
	string word;

	cin >> word;
	cout << IsPalindrom(word);
	return 0;
}