#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string vector_to_string(vector<string>& buffer) {
    string hystory;
    int size = buffer.size();

    if (size > 0) {        
        hystory = buffer[size - 1];
        if (size > 1 && size < 3) {
            hystory += " (" + buffer[size - 2] + ")";
        }
        else if (size > 2) {
            hystory += " ("; 
            for (int i = size - 2; i >= 0; --i) {
                if (i != 0) {
                    hystory += buffer[i] + ", ";
                }
                else {
                    hystory += buffer[i];
                }
            }
            hystory += ")"; 
        }
    }
    return hystory;
}

string GetHystory(const map<int, string>& data, int year) {
    string hystory;
    vector<string> buffer;

    for(const auto& [key, value] : data) {
        if (key <= year){
            if (buffer.size() == 0) {
                buffer.push_back(value);
            }
            if (buffer.size() > 0 && buffer[buffer.size() - 1] != value) {
                buffer.push_back(value);
            }
        }
        else {
            break;
        }
    }
    hystory = vector_to_string(buffer);
    return hystory;
}

string GetNameOrLastname(const map<int, string>& data, int year) {
    string buffer;

    for(const auto& [key, value] : data) {
        if (key <= year){
            buffer = value;
        }
        else {
            break;
        }
    }
    return buffer;
}

class Person {
    int birth_year;
    map<int, string> names;
    map<int, string> last_names;

public:
    Person (const string& name, const string& last_name, int year) {
        birth_year = year;
        names[year] = name;
        last_names[year] = last_name;
    }

    bool check_birth_year(const map<int, string>& data, int year) const {
        auto buffer = begin(data);

        if (data.size() > 0 && buffer->first > year)
            return 0;
        return 1;
    }

    void ChangeFirstName(int year, const string& first_name) {
        auto buffer = begin(names);

        if (names.size() > 0 && buffer->first <= year) {
            names[year] = first_name;
        }
        
        // for output map names
        
        // for (const auto& [key, value] : names)
        //  cout << key << " " << value << endl;
    }

    void ChangeLastName(int year, const string& last_name) {
        auto buffer = begin(last_names);

        if (last_names.size() > 0 && buffer->first <= year) {
            last_names[year] = last_name;
        }

        // for output map last_names
        
        // for (const auto& [key, value] : last_names)
        //  cout << key << " " << value << endl;
    }

    string GetFullName(int year) const {
        string full_name;
        string name = GetNameOrLastname(names, year);
        string last_name = GetNameOrLastname(last_names, year);

        if (check_birth_year(names, year) && check_birth_year(last_names, year)) {
            if (!name.empty() && !last_name.empty()){
                full_name = name + " " + last_name;
            }
        }
        else {
            full_name = "No person";
        }

        // previous version class

        // else if ((name.empty() && !last_name.empty())){
        //     full_name = last_name + " with unknown first name";
        // }
        // else if ((!name.empty() && last_name.empty())){
        //     full_name = name + " with unknown last name";
        // }
        // else {
        //     full_name = "Incognito";
        // }
        return full_name;
    }

    string GetFullNameWithHistory(int year) const {
        string full_name;
        string name = GetHystory(names, year);
        string last_name = GetHystory(last_names, year);

        if (check_birth_year(names, year) && check_birth_year(last_names, year)) {
            if (!name.empty() && !last_name.empty()){
                full_name = name + " " + last_name;
            }
        }
        else {
            full_name = "No person";
        }

        // previous version class
        
        // else if ((name.empty() && !last_name.empty())){
        //     full_name = last_name + " with unknown first name";
        // }
        // else if ((!name.empty() && last_name.empty())){
        //     full_name = name + " with unknown last name";
        // }
        // else {
        //     full_name = "Incognito";
        // }
        return full_name;
    }
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
