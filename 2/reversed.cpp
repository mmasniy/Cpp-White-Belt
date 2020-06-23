#include <iostream>
#include <vector>

using namespace std;

static void Reverse(vector<int>& v){
	int tmp;
	
	if (v.size() > 1) {
		for (int i = 0; i <= (v.size() / 2) - 1; ++i) {
			tmp = v[i];
			v[i] = v[v.size() - i - 1];
			v[v.size() - i - 1] = tmp;
		}
	}
}

vector<int> Reversed(const vector<int>& v) {
	vector<int> duplicate;

	for (auto i : v)
		duplicate.push_back(i);
	Reverse(duplicate);
	return duplicate;
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5, 6};
	vector<int> v1;
	
	v1 = Reversed(v);
	for (auto i : v1)
		cout << i << " ";
	cout << endl; 
	return 0;
}
