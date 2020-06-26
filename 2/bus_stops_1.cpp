#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void add_new_bus_in_buses(map<string, vector<string>>& bus, const string& name_bus,
											const vector<string>& stops_for_bus){
	for (const string& s : stops_for_bus){
		bus[name_bus].push_back(s);
	}
	// for (const auto& [key, value] : bus) {
	// 	cout << key << ": ";
	// 	for (const auto& v : value)
	// 		cout << v << " ";
	// 	cout << endl;
	// }
 }

void add_new_stop_in_stops(map<string, vector<string>>& stops, const string& name_bus,
											const vector<string>& stops_for_bus) {
	for (const string& s : stops_for_bus)
		stops[s].push_back(name_bus);
	// for (const auto& [key, value] : stops) {
	// 	cout << key << ": ";
	// 	for (const auto& v : value)
	// 		cout << v << " ";
	// 	cout << endl;
	// }
}

void cout_buses_for_stop(const map<string, vector<string>>& stops, const string& stop) {
	if (stops.count(stop) != 0) {
		for (const string& s : stops.at(stop))
			cout << s << " ";
		cout << endl;
	}
	else cout << "No stop" << endl;
}

void cout_stops_for_bus(const map<string, vector<string>>& stops,
						const map<string, vector<string>>& buses, const string& name_bus) {
	// for (const auto& [key, value] : stops) {
	// 	cout << key << ": ";
	// 	for (const auto& v : value)
	// 		cout << v << " ";
	// 	cout << endl;
	// }
	if (buses.count(name_bus) != 0) {	
		for (const auto& stop : buses.at(name_bus)) {
			cout << "Stop " << stop << ": ";
			for (const auto& bus : stops.at(stop)) {
				if (stops.at(stop).size() != 0 && bus != name_bus)
					cout << bus << " ";
				else if (stops.at(stop).size() == 1)
					cout << "no interchange";
			}
			cout << endl;
		}
	}
	else cout << "No bus" << endl;
}

void cout_all_buses(const map<string, vector<string>>& buses) {
	if (buses.empty())
		cout << "No buses" << endl;
	else {
		for (const auto& [key, value] : buses) {
			cout << "Bus " << key << ": ";
			for (const auto& v : value){
				cout << v << " ";
			}
			cout << endl;
		}
	}
}

int  main() {
	int iter;
	map<string, vector<string>> buses;
	map<string, vector<string>> stops;

	cin >> iter;
	for (; iter > 0; iter--) {
		string operation;

		cin >> operation;
		if (operation == "NEW_BUS") {
			int stops_count;
			string name_bus;
			cin >> name_bus >> stops_count;
			vector<string> stops_for_bus(stops_count);
			
			for (int i = 0; i < stops_count; ++i)
				cin >> stops_for_bus[i];
			// for (const auto& s : stops_for_bus)
			// 	cout << s << " ";
			// cout << endl;
			// cout << "INPUT IS VALID" << endl;
			add_new_bus_in_buses(buses, name_bus, stops_for_bus);
			add_new_stop_in_stops(stops, name_bus, stops_for_bus);
		}
		else if (operation == "BUSES_FOR_STOP") {
			string stop;

			cin >> stop;
			cout_buses_for_stop(stops, stop);
			// if (stops.count(stop) != 0) {
			// 	for (const string& s : stops[stop])
			// 		cout << s << " ";
			// 	cout << endl;
			// }
			// else cout << "No stop" << endl;
		}
		else if (operation == "STOPS_FOR_BUS") {
			string name_bus;

			cin >> name_bus;
			cout_stops_for_bus(stops, buses, name_bus);
			// if (buses.count(name_bus) != 0) {
			// 	for (const auto& stop : buses[name_bus]) {
			// 		cout << "Stop " << stop << ": ";
			// 		for (const auto& bus : stops.at(stop)) {
			// 			if (stops[stop].size() != 0 && bus != name_bus)
			// 				cout << bus << " ";
			// 			else if (stops[stop].size() == 1)
			// 				cout << "no interchange";
			// 		}
			// 		cout << endl;
			// 	}
			// }
			// else cout << "No bus" << endl;
		}
		else if (operation == "ALL_BUSES") {
			cout_all_buses(buses);
		}
	}
	return 0;
}

