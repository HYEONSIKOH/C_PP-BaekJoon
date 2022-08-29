// 백준 16435 [그리디 알고리즘] 무럭무럭 자라는 뱀의 최대 길이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num,len;
	cin >> num >> len;

	vector<int> arr;
	int n;
	for (int i = 0; i < num; i++) {
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < num; i++) {
		if (arr[i] <= len) len++;
		else {
			cout << len;
			return 0;
		}
	}

	cout << len;
	return 0;
}