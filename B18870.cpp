//백준 18870 중복되는 좌표값을 제거 후, 자신보다 작은 좌표값을 카운팅하는 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	vector<int> arr;

	int n;
	for (int i = 0; i < num; i++) {
		cin >> n;
		arr.push_back(n);
	}

	vector<int> copy = arr;
	sort(copy.begin(), copy.end());
	copy.erase(unique(copy.begin(), copy.end()), copy.end()); // 중복되는 값을 제거한다.

	int count = 0;

	// 이진탐색인데 이게 왜 이진탐색인지.....
	for (auto&& x : arr) cout << lower_bound(copy.begin(), copy.end(), x) - copy.begin() << ' ';

	return 0;
}