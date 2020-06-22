#include <iostream>

using namespace std;

int main() {
	int yes = 0;
	string f;

	cin >> f;
	for (int i = 0; i < f.size(); ++i) {
		if (f[i] == 'f' && yes == 1){
			cout << i << endl;
			yes++;
			break;
		}
		if (f[i] == 'f' && yes == 0)
			yes++;
	}
	if (yes == 1)
		cout << "-1" << endl;
	if (yes == 0)
		cout << "-2" << endl;
	return 0;
}
