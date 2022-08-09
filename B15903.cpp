// ���� 15903 [�켱���� ť] ���� ���� �ΰ��� ī�带 ��ġ��, ����� ī����� �� �� �� ���� ���� ��!
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	long long num, n, p;
	cin >> num >> n;

	priority_queue<long long, vector<long long>, greater<long long>> q;

	for (long long i = 0; i < num; i++) {
		cin >> p;
		q.push(p);
	}

	long long a, b;
	for (long long i = 0; i < n; i++) {
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();

		q.push(a + b);
		q.push(a + b);
	}

	long long sum = 0;
	while (!q.empty()) {
		sum += q.top();
		q.pop();
	}

	cout << sum;
	return 0;
}