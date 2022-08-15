// ���� 13904 ȿ�������� ���� ���� ȹ���ϱ�
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	vector <pair<int, int>> arr;
	priority_queue<int,vector<int>,greater<int>> q;
	int num;
	cin >> num;

	// �ϴ� ���Ϳ� ������ ��, ������ ������ �������� ����!
	int day,grade;
	for (int i = 0; i < num; i++) {
		cin >> day >> grade;
		arr.push_back(make_pair(day, grade));
	}
	sort(arr.begin(), arr.end());
	
	// ��������(�ּ���) �켱���� ť�� ���� �����鼭,
	for (int i = 0; i < num; i++) {
		day = arr[i].first;
		grade = arr[i].second;

		q.push(grade);

		// size�� ������ �� ���� �� ����, �� �ϼ����� ���� ���� �� ������ �ȵȴ�
		// ������ �Ϸ翡 �Ѱ����� �� �� �ִ�.
		// �ּڰ� �ƹ��ų� pop�� �ص� �Ǵ� ������, ��¥�� ������ ������ �������� �߱� ������!
		if (q.size() > day) q.pop();
	}

	int sum_grade = 0;
	while (!q.empty()) {
		sum_grade += q.top();
		q.pop();
	}

	cout << sum_grade;
	return 0;
}