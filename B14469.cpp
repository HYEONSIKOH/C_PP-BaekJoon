// 백준 14469 [그리디 알고리즘] 우리 동네 소 안전하게 건너게 하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num, enter,spend;
	cin >> num;
	vector<pair<int,int>> arr;

	for (int i = 0; i < num; i++) {
		cin >> enter >> spend;
		arr.push_back(make_pair(enter,spend));
	}

	int pre = 0;
	sort(arr.begin(), arr.end());

	for (int i = 0; i < num; i++) {
		if (pre <= arr[i].first) {
			pre = arr[i].first;
			pre += arr[i].second;
		}
		else pre += arr[i].second;
	}

	cout << pre;
	return 0;
}