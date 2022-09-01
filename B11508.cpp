// ���� 11508 [�׸��� �˰���] ����ǰ 2+1 �ּҰ���!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	vector<int> arr(num);

	int n;
	for (int i = 0; i < num; i++) {
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end(), greater<int>());

	int count = 0;
	int ans = 0;
	for (int i = 0; i < num; i++) {
		if (count != 2) {
			ans += arr[i];
			count++;
		}
		else
			count = 0;
	}

	cout << ans;
}