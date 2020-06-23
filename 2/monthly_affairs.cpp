#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int q, day, month_num = 0;
	string action, work;
	vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> affairs(months[month_num]);

	for (cin >> q; q > 0; --q) {
		cin >> action;
		if (action == "NEXT") {
			month_num++;
		}
		else if (action == "DUMP"){
			cin >> day;
			cout << affairs[day - 1].size() << " ";
			for (const auto& d : affairs[day - 1])
				cout << d << " ";
			cout << endl;
		}
		else if (action == "ADD") {
			cin >> day >> work;
			affairs[day - 1].push_back(work);
		}
	}
	// for (const auto& day : affairs) {
	// 	for (const auto& duty : day) {
	// 		cout << duty << " ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}
