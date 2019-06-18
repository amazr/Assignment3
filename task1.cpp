#include <iostream>
using namespace std;

bool is_prime(int num) {
	if (num < 2) {
		return false;
	}
	else if (num == 2) {
		return true;
	}

	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int L = 5;
	int ar[5];

	for (int i = 0; i < L; i++) {
		cout << "Enter array value " << (i + 1) << "/" << L << ": ";
		cin >> ar[i];
	}

	cout << endl;

	for (int i = 0; i < L; i++) {

		cout << ar[i];

		if (is_prime(ar[i])) {
			cout << " is prime.";
		}
		else {
			cout << " is not prime.";
		}

		cout << endl;
	}


}