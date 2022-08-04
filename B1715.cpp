// 백준 1715 우선순위 큐 + 그리디 알고리즘 
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

	// 값의 크기만큼 자동으로 오름차순으로 정렬된다.
	priority_queue<int, vector<int>, greater<int>> q; // 오름차순 우선순위 큐

	int n;
	for (int i = 0; i < num; i++) {
		cin >> n;
		q.push(n); // n을 push
	}

	int answer = 0;
	int a, b;
	int sum = 0;

	while (q.size() != 1) {
		a = q.top(); // 가장 앞에 있는 값
		q.pop(); // 앞에 있는 값 pop
		b = q.top(); 
		q.pop();

		sum = a + b;
		answer += sum;
		q.push(sum);
	}

	cout << answer;
	return 0;
}