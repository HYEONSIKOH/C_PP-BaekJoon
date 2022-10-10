// ���� 1697 [�׷��� Ž��] �����ִ� ���� ã�� ��������, ���� ���� ã�� ��
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> q;
bool visit[100001]{};
int ans = 100001;
int x, y;


void BFS() {
	q.push(pair<int,int>(x,0));
	visit[x] = true;

	while (!q.empty()) {
		int n = q.front().first;
		int t = q.front().second;
		q.pop();

		if (n == y) { if (ans > t) ans = t; }

		else {
			if (n - 1 >= 0 && !visit[n - 1]) {
				q.push(pair<int, int>(n - 1, t + 1));
				visit[n - 1] = true;
			}
			if (n + 1 <= 100000 && !visit[n + 1]) {
				q.push(pair<int, int>(n + 1, t + 1));
				visit[n + 1] = true;
			}
			if (2 * n <= 100000 && !visit[2 * n]) {
				q.push(pair<int, int>(n * 2, t + 1));
				visit[2 * n] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> x >> y;

	BFS();
	cout << ans;
	return 0;
}