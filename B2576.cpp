#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[7];
	int min = 101;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < 7; i++) {
		cin >> arr[i];

		if (arr[i] % 2 == 1) {
			sum += arr[i];
			count++;

			if (min > arr[i]) min = arr[i];
		}
	}

	if (count != 0) {
		cout << sum << "\n";
		cout << min;
	}
	else cout << -1;

	return 0;
}