#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v){
	int tmp;
	
	if (v.size() > 1) {
		for (int i = 0; i <= (v.size() / 2) - 1; ++i) {
			tmp = v[i];
			v[i] = v[v.size() - i - 1];
			v[v.size() - i - 1] = tmp;
		}
	}
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	Reverse(v);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	return 0;
}
