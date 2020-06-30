#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
	string main;

public:
	ReversibleString() {}
	ReversibleString(const string& input) {
		main = input;
	}
	string Reverse() {
		reverse(main.begin(), main.end());
		return main;
	}
	string ToString() const {
		return main;
	}
};

// int main() {
//   ReversibleString s("live");
//   s.Reverse();
//   cout << s.ToString() << endl;
  
//   s.Reverse();
//   const ReversibleString& s_ref = s;
//   string tmp = s_ref.ToString();
//   cout << tmp << endl;
  
//   ReversibleString empty;
//   cout << '"' << empty.ToString() << '"' << endl;
  
//   return 0;
// }
