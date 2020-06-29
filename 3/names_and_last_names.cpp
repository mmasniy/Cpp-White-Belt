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
    map<int, string> names;
    map<int, string> last_names;

public:
    void ChangeFirstName(int year, const string& first_name) {
        names[year] = first_name;
        // for (const auto& [key, value] : names)
        //  cout << key << " " << value << endl;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
        // for (const auto& [key, value] : last_names)
        //  cout << key << " " << value << endl;
    }

    string GetFullName(int year) {
        string full_name;
        string name = GetNameOrLastname(names, year);
        string last_name = GetNameOrLastname(last_names, year);

        if (!name.empty() && !last_name.empty()){
            full_name = name + " " + last_name;
        }
        else if ((name.empty() && !last_name.empty())){
            full_name = last_name + " with unknown first name";
        }
        else if ((!name.empty() && last_name.empty())){
            full_name = name + " with unknown last name";
        }
        else {
            full_name = "Incognito";
        }
        return full_name;
    }

    string GetFullNameWithHistory(int year) {
        string full_name;
        string name = GetHystory(names, year);
        string last_name = GetHystory(last_names, year);

        if (!name.empty() && !last_name.empty()){
            full_name = name + " " + last_name;
        }
        else if ((name.empty() && !last_name.empty())){
            full_name = last_name + " with unknown first name";
        }
        else if ((!name.empty() && last_name.empty())){
            full_name = name + " with unknown last name";
        }
        else {
            full_name = "Incognito";
        }
        return full_name;
    }
};

// int main() {
//   Person person;

//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeFirstName(1965, "Appolinaria");

//   person.ChangeLastName(1965, "Sergeeva");
//   person.ChangeLastName(1965, "Volkova");
//   person.ChangeLastName(1965, "Volkova-Sergeeva");

//   for (int year : {1964, 1965, 1966}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }

//   return 0;
// }
