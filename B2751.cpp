// 백준 2751 O(nlogn) 시간이 나오는 정렬 이용!
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	vector<int> arr;

	int temp;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < num; i++) cout << arr[i] << "\n";

	return 0;
}