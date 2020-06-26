#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void add_stops(map<set<string>, int>& stops, const set<string>& input) {
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
	map<set<string>, int> stops;

	cin >> iter;
	for (; iter > 0; --iter) {
		int count_stop;
		cin >> count_stop;
		set<string> input;

		for (int i = 0; i < count_stop; ++i){
			string new_stop;
			cin >> new_stop;
			input.insert(new_stop);
		}
		add_stops(stops, input);
	}
	return 0;
}
