#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void add_stops(map<vector<string>, int>& stops, const vector<string>& input) {
	int size = stops.size();

	if (size == 0) {
		stops[input] = 1;
		cout << "New bus 1" << endl;
	}
	else {
		if (stops.count(input) == 0){
			stops[input] = size + 1;
			cout << "New bus " << (size + 1) << endl;
		}
		else
			cout << "Already exists for " << stops[input] << endl;
	}
}

int main() {
	int iter;
	map<vector<string>, int> stops;

	cin >> iter;
	for (; iter > 0; --iter) {
		int count_stop;
		cin >> count_stop;
		vector<string> input(count_stop);

		for (int i = 0; i < count_stop; ++i)
			cin >> input[i];
		add_stops(stops, input);
	}
	return 0;
}
