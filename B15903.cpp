// 백준 15903 [우선순위 큐] 가장 작은 두개의 카드를 합치고, 덮어씌운 카드들의 총 합 중 가장 작은 값!
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