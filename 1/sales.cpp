#include <iostream>

using namespace std;

int main() {
	double N, A, B, X, Y;

	cin >> N >> A >> B >> X >> Y;

	if (N <= A && N <= B)
		cout << N << endl;
	else if (N > B)
		cout << (N - (N * Y / 100)) << endl;
	else if (N > A)
		cout << (N - (N * X / 100)) << endl;
}
