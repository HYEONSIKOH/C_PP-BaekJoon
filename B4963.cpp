// 백준 4963 [그래프 탐색] 바다에 무인도가 몇개가 있을까요~?
#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int x;
	int y;
}pos;
int w, h;
int land[51][51] = { 0, };
bool visit[51][51]{};
int ans = 0;
queue <pos> q;

int range(pos p) {
	if (p.x > 0 && p.y > 0 && p.x <= w && p.y <= h) return 1;
	else return 0;
}

int a[8][2] = { {-1,0},{1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1} };

void init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			land[i][j] = 0;
			visit[i][j] = false;
		}
	}
	ans = 0;
}

void bfs(int x, int y) {
	pos P = { x,y };
	q.push(P);
	visit[y][x] = true;

	while (!q.empty()) {
		pos p = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			pos next;
			next.x = p.x + a[i][1];
			next.y = p.y + a[i][0];

			if (range(next) == 1 && !visit[next.y][next.x] && land[next.y][next.x] == 1) {
				q.push(next);
				visit[next.y][next.x] = true;
			}
		}
	}
	ans++;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++) cin >> land[i][j];
		
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++) if (land[i][j] == 1 && !visit[i][j]) bfs(j,i);

		cout << ans << '\n';
		init();
	}

	return 0;
}