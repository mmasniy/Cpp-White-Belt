#include <iostream>
#include <vector>

using namespace std;

void get_temperature_all_days(vector<int>& temperature) {
	for (int& t : temperature) {
		cin >> t;
	}
}

int get_average_temperature(const vector<int>& temperature) {
	int sum = 0;
	
	for (auto t : temperature)
		sum += t;

	return sum / temperature.size();
}

void print_day_more_average_temp(const vector<int>& temperature) {
	int day_more_AT = 0;
	int aver_temp = get_average_temperature(temperature);
	
	for (int t : temperature) {
		if (t > aver_temp)
			day_more_AT++;
	}
	cout << day_more_AT << endl;
	for (int i = 0; i < temperature.size(); ++i) {
		if (temperature[i] > aver_temp)
			cout << i << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> temperature(n);

	get_temperature_all_days(temperature);
	print_day_more_average_temp(temperature);
	return 0;
}