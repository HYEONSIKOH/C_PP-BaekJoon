// 백준 1758 팁을 최대로 많이 받는법
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	long long num, n, sum = 0;
	vector<long long> arr;
	cin >> num;
	for (long long i = 0; i < num; i++) {
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end(), greater<int>());

	for (long long i = 0; i < num; i++) {
		arr[i] = arr[i] - i;
		if (arr[i] > 0) sum += arr[i];
	}
	cout << sum;
}