// ���� 1715 �켱���� ť + �׸��� �˰��� 
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	int num;
	cin >> num;

	if (num == 1) {
		cout << 0;
		return 0;
	}

	// ���� ũ�⸸ŭ �ڵ����� ������������ ���ĵȴ�.
	priority_queue<int, vector<int>, greater<int>> q; // �������� �켱���� ť

	int n;
	for (int i = 0; i < num; i++) {
		cin >> n;
		q.push(n); // n�� push
	}

	int answer = 0;
	int a, b;
	int sum = 0;

	while (q.size() != 1) {
		a = q.top(); // ���� �տ� �ִ� ��
		q.pop(); // �տ� �ִ� �� pop
		b = q.top(); 
		q.pop();

		sum = a + b;
		answer += sum;
		q.push(sum);
	}

	cout << answer;
	return 0;
}