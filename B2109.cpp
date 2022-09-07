// ���� 2109 [�켱���� ť] ���� ���� ���� ���¹� (13904 ���� ������ �����)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector <pair<int, int>> arr;
	priority_queue<int, vector<int>, greater<int>> q;
	int num;
	cin >> num;

	int day, pay;
	for (int i = 0; i < num; i++) {
		cin >> pay >> day;
		arr.push_back(make_pair(day,pay));
	}
	sort(arr.begin(), arr.end());


	for (int i = 0; i < num; i++) {
		day = arr[i].first;
		pay = arr[i].second;

		q.push(pay);

		if (q.size() > day) q.pop();
	}

	int sum_pay = 0;
	while (!q.empty()) {
		sum_pay += q.top();
		q.pop();
	}

	cout << sum_pay;
	return 0;
}