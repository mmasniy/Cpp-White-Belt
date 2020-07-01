#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Year {
	int value;
	explicit Year(int new_value) {
		value = new_value;
	}
};

struct Month {
	int value;
	explicit Month(int new_value) {
		value = new_value;
	}
};

struct Day {
	int value;
	explicit Day(int new_value) {
		value = new_value;
	}
};

struct Name {
	string value;
	explicit Name(const string& new_value) {
		value = new_value;
	}
};

struct LName {
	string value;
	explicit LName(const string& new_value) {
		value = new_value;
	}
};

// struct Date {
	// int day;
	// int month;
	// int year;
// 	// Date() {}
// 	Date(const Day& new_day, const Month& new_month, const Year& new_year) {
// 		day = new_day.value;
// 		month = new_month.value;
// 		year = new_year.value;
// 	}
// };

struct Student {
	string name;
	string last_name;
	int day;
	int month;
	int year;
	Student () {}
	Student(const Name& new_name, const LName& new_last_name, const Day& new_day,
			const Month& new_month, const Year& new_year) {
		name = new_name.value;
		last_name = new_last_name.value;
		day = new_day.value;
		month = new_month.value;
		year = new_year.value;
	}
};

Student GetStudent() {
	int day, month, year;
	string name, last_name;

	cin >> name >> last_name;
	cin >> day >> month >> year;
	return {Name(name), LName(last_name), Day(day), Month(month), Year(year)};
}

int main() {
	size_t n, m;
	string operation;
	map<int, Student> students;

	cin >> n;
	for (size_t i = 1; i <= n; ++i) {
		students[i] = GetStudent();
	}
	cin >> m;

	for (; m > 0; --m) {
		cin >> operation >> n;
		if (operation == "name" && n > 0 && n <= students.size()) {
			cout << students[n].name << " " << students[n].last_name << endl;
		}
		else if (operation == "date" && n > 0 && n <= students.size()) {
			cout << students[n].day << "." << students[n].month << ".";
			cout << students[n].year << endl;
		}
		else {
			cout << "bad request" << endl;
		}
	}
	// cout << "---------------------------" << endl;
	// for (const auto& [key, value] : students) {
	// 	cout << key << ": " << value.name << " " << value.last_name << " ";
	// 	cout << value.day << "." << value.month << "." << value.year << endl;
	// }
	return 0;
}























