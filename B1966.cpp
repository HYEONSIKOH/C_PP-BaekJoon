// ���� 1966 �켱������ �ִ� �����ͱ�! �� �����͹��� ���°�� ���ñ�...?
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;
	queue<pair<int, int>> q;
	priority_queue<int> ord;
	int ans = 1;
	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < a; j++) {
			int n;
			cin >> n;
			q.push(pair<int, int>(j, n));
			ord.push(n);
		}

		while (1) {
			if (q.front().second == ord.top() && q.front().first == b) {
				cout << ans << '\n';
				ans = 1;
				break;
			}
			else if (q.front().second == ord.top() && q.front().first != b) {
				q.pop();
				ord.pop();
				ans++;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}

		while (!q.empty()) q.pop();
		while (!ord.empty()) ord.pop();
	}

	return 0;
}