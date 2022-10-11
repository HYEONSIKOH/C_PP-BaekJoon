// 백준 2178 [그래프 탐색] 여기 미로에 사람있어요!! 살려주세요....
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
	int x;
	int y;
}pos;

int M, N;
int maze[101][101];
bool visit[101][101]{};
int ans = 0;
queue<pair<pos,int>> q;

int a[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

int range(int x, int y) {
	if (x > 0 && y > 0 && x <= N && y <= M) return 1;
	else return 0;
}

void BFS() {
	ans = M * N;
	pos start;
	start.x = 1, start.y = 1;
	q.push(pair<pos, int>(start, 1));
	visit[1][1] = true;

	while (!q.empty()) {
		pos value;
		value.x = q.front().first.x;
		value.y = q.front().first.y;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			pos next_value;
			next_value.x = value.x + a[i][0];
			next_value.y = value.y + a[i][1];
			if (next_value.x == N && next_value.y == M) { if (ans > cnt) ans = cnt; }

			else if (range(next_value.x, next_value.y) == 1 && !visit[next_value.y][next_value.x] && maze[next_value.y][next_value.x] == 1) {
				q.push(pair<pos,int>(next_value, cnt + 1));
				visit[next_value.y][next_value.x] = true;
			}
		}
	}
}

int main() {
	scanf("%d %d", &M, &N);
	int x, y;
	for (int i = 1; i <= M; i++) for (int j = 1; j <= N; j++) scanf("%1d", &maze[i][j]);

	BFS();
	printf("%d", ans+1);
	return 0;
}