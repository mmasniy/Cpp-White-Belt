#include <iostream>
#include <exception>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Date {
    int day;
    int month;
    int year;

public:
    void PrintDate() const{
        cout << setw(4) << setfill('0') << GetYear() << "-" 
             << setw(2) << setfill('0') << GetMonth() << "-"
             << setw(2) << setfill('0') << GetDay();
    }

    Date() {}

    Date(int new_day, int new_month, int new_year) {
        year = new_year;
        if (new_day < 1 || new_day > 31) {
            throw invalid_argument("Day value is invalid: " + to_string(new_day));
        }
        else {
            day = new_day;
        }
        if (new_month < 1 || new_month > 12) {
            throw invalid_argument("Month value is invalid:" + to_string(new_month));
        }
        else {
            month = new_month;
        }
    }

    int GetYear() const {
        return year;
    }
    
    int GetMonth() const {
        return month;
    }
    
    int GetDay() const {
        return day;
    }
};

bool operator==(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() == rhs.GetDay();
        }
        return false;
    }
    return false;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth()== rhs.GetMonth()){
            return lhs.GetDay() < rhs.GetDay();
        }
        else {
            return lhs.GetMonth() < rhs.GetMonth();
        }
    }
    else {
        return lhs.GetYear() < rhs.GetYear();
    }
}

class Database {
    map<Date, set<string>> events;

public:
    void AddEvent(const Date& date, const string& event) {
        events[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event) {
        if (events.find(date) != events.cend()
            && events[date].count(event) != 0) {
            events[date].erase(event);
            return true;
        }
        return false;
    }

    int  DeleteDate(const Date& date) {
        int events_count = 0;

        if (events.count(date) != 0) {
            events_count = events[date].size();
        }
        events.erase(date);
        return events_count;
    }
    void Find(const Date& date) const {
        set<string> finded = events.at(date);

        for (const string& f : finded) {
            cout << f << endl;
        }
    }
  
    void Print() const {
        for (const auto& [key, value] : events) {
            cout << key.GetYear()<< '-' << key.GetMonth() << "-" << key.GetDay() << ": ";
            for (const string& v : value) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

Date input_Date(const string& new_date) {
    int day = 0, month = 0, year = 0;
    Date date;
    stringstream input(new_date);

    if (!(input >> year)) {
        string error = "Wrong date format: " + new_date;
        throw invalid_argument(error);
    }
    input.ignore(1);
    if (!(input >> month)) {
        string error = "Wrong date format: " + new_date;
        throw invalid_argument(error);
    }
    input.ignore(1);
    if (!(input >> day)) {
        string error = "Wrong date format: " + new_date;
        throw invalid_argument(error);
    }
    if ((input.peek() != EOF)) {
        string error = "Wrong date format: " + new_date;
        throw invalid_argument(error);
    }
    return date = Date(day, month, year);
}

void GetStrings(const string& command, vector<string>& data) {
    stringstream input(command);
    input >> data[0] >> data[1] >> data[2];
}

int main() {
    Database db;
    string command;

    while (getline(cin, command)) {
        vector<string> input(3);
        Date date;

        GetStrings(command, input);
        if (input[0].size() == 0) {
            continue;
        }
        try {
            date = input_Date(input[1]);
            if (input[0] == "Add") {
                db.AddEvent(date, input[2]);
            }
            else if (input[0] == "Del") {
                if (input[2].empty()) {
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                }
                else {
                    if (db.DeleteEvent(date, input[2])) {
                        cout << "Deleted successfully" << endl;
                    }
                    else {
                        cout << "Event not found" << endl;
                    }
                }
            }
            else if (input[0] == "Find") {
                db.Find(date);
            }
            else if (input[0] == "Print") {
                db.Print();
            }
            else {
                cout << "Unknown command: " << command << endl;
                return 0;
            }
        }
        catch(invalid_argument& er) {
            cout << er.what() << endl;
            return 0;
        }
    }
    return 0;
}
