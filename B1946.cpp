// ���� 1946 [�׸��� �˰���] ���հ��ڸ� �ɷ�����!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	int n, cnt;

	for (int i = 0; i < num; i++) {
		cin >> n;
		cnt = 0;
		vector<pair<int, int>> arr(n);

		for (int j = 0; j < n; j++) cin >> arr[j].first >> arr[j].second;

		sort(arr.begin(), arr.end());

		int temp = arr[0].second;
		for (int j = 0; j < n; j++) {
			if (temp >= arr[j].second) {
				cnt++;
				temp = arr[j].second;
			}
		}

		cout << cnt << endl;
		arr.clear();
	}
}