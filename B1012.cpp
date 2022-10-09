// 백준 1012 [그래프 탐색] 배추농장에 유기농 지렁이 풀기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[51][51] = { 0, };
queue<pair<int, int>> q;
bool visit[51][51]{};
int ans = 0;
int pos[4][4] = { {-1,0},{1,0},{0,-1},{0,1} };
int M, N, n;

int Range(int x, int y) {
	if (x >= 0 && y >= 0 && x < M && y < N) return 1;
	else return 0;
}

void BFS(int x, int y) {
	q.push(pair<int, int>(x, y));
	visit[y][x] = true;

	while (!q.empty()) {
		int pos_x = q.front().first;
		int pos_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = pos_x + pos[i][0];
			int next_y = pos_y + pos[i][1];

			if (Range(next_x, next_y) == 1 && !visit[next_y][next_x] && arr[next_y][next_x] == 1) {
				q.push(pair<int, int>(next_x, next_y));
				visit[next_y][next_x] = true;
			}
		}
	}

	ans++;
}

int main() {
	ios_base::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	for (int index = 0; index < num; index++) {
		cin >> M >> N >> n;
		int a, b;

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			arr[b][a] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1 && !visit[i][j]) {
					BFS(j, i);
				}
			}
		}

		cout << ans << '\n';

		// ====== 초기화 ======
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				arr[i][j] = 0;
				visit[i][j] = false;
			}
		}
		ans = 0;
		// ====================
	}

	return 0;
}