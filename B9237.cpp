// 백준 9237 [그리디 알고리즘] 심은 묘목은 며칠만에 다 커질까?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num;
	cin >> num;

	int n;
	vector<int> arr;
	for (int i = 0; i < num; i++) {
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end(),greater<int>());

	int max = 0;
	for (int i = 0; i < num; i++) {
		arr[i] += i + 2;
		if (max < arr[i]) max = arr[i];
	}
	cout << max;
	return 0;
}