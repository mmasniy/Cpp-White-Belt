#include <iostream>
#include <string>
#include <map>

using namespace std;

void dump_info(const map<string, string>& country) {
	if (country.empty())
		cout << "There are no countries in the world" << endl;
	else {
		for (const auto& [key, value] : country)
			cout << key << "/" << value << " ";
		cout << endl; 
	}
}

void about_country(const map<string, string>& country, const string& name_country) {
	if (country.find(name_country) == country.cend())
		cout << "Country " << name_country << " doesn't exist" << endl;
	else {
		cout << "Country " << name_country << " has capital " << country.at(name_country) << endl;
	}
}

void rename_country(map<string, string>& country, const string& old_name, const string& new_name) {
	if (country.find(old_name) != country.cend()) {
		if (country.find(new_name) == country.cend()) {
			cout << "Country " << old_name << " with capital " << country[new_name];
			cout << " has been renamed to " << new_name << endl;
			country[new_name] = country[old_name];
			country.erase(old_name);
		}
		else
			cout << "Incorrect rename, skip" << endl;
	}
	else 
		cout << "Incorrect rename, skip" << endl;
}

void change_capital(map<string, string>& country, const string& name_country, const string& new_capital) {
	auto old_capital = country.find(name_country);

	if (old_capital != country.cend()) {
		if (old_capital->second != new_capital) {
			cout << "Country " << name_country << " has changed its capital from ";
			cout << old_capital->second << " to " << new_capital << endl;
			country.erase(name_country);
			country[name_country] = new_capital;
		}
		else {
			cout << "Country " << name_country << " hasn't changed its capital" << endl;
		}
	}
	else {
		country[name_country] = new_capital;
		cout << "Introduce new country " << name_country << " with capital " << new_capital << endl;
		// for (const auto& [key, value] : country) {
		// 	cout << key << ": " << value << endl;
		// }
	}
}

int main() {
	int iter;
	map<string, string> country;

	cin >> iter;
	for (; iter > 0; --iter) {
		string operation;

		cin >> operation;
		if (operation == "DUMP") {
			dump_info(country);
		}
		else if (operation == "ABOUT") {
			string name;

			cin >> name;
			about_country(country, name);
		}
		else if (operation == "RENAME") {
			string old_name, new_name;

			cin >> old_name >> new_name;
			rename_country(country, old_name, new_name);
		}
		else if (operation == "CHANGE_CAPITAL") {
			string name_country, new_capital;

			cin >> name_country >> new_capital;
			change_capital(country, name_country, new_capital);
		}
	}
	return 0;
}
