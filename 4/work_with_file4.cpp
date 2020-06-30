#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	ifstream input("input.txt");
	int N, M, OUT;

	input >> N;
	input >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			input >> OUT;
			cout << setw(10) << OUT;
			input.ignore(1);
			if (j != M - 1)
				cout << " ";
		}
		if (i != N - 1)
			cout << endl;
	}
	return 0;
}
