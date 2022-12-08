// 백준 1158 [queue] 요세푸스
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int cnt = 0;

	queue <int> q;

	for (int i = 1; i <= N; i++) q.push(i);

	cout << "<";
	while (!q.empty()) {
		cnt++;
		if (cnt == K) {
			cout << q.front();
			cnt = 0;
			q.pop();
			if (!q.empty()) cout << ", ";
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}
	cout << ">";

	return 0;
}