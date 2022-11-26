// 백준 2146 [BFS] 가장 작은 다리 한개 만들기!
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int land[101][101];
bool visit[101][101]{};
int ans = 987654321;
int pos[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };

queue <pair<int, int>> q;
vector<vector<pair<int,int>>> v;
vector<pair<int, int>> vec;
int cnt = 0;

int land_Range(int x,int y) {
	if (x >= 0 && y >= 0 && x < N && y < N) return 1;
	else return 0;
}

void bfs(int x,int y) {
	q.push({ x,y });
	visit[y][x] = true;
	v[cnt].push_back({ x,y });

	while (!q.empty()) {
		int pos_x = q.front().first;
		int pos_y = q.front().second;
		visit[pos_y][pos_x] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = pos_x + pos[i][0];
			int next_y = pos_y + pos[i][1];

			if (land_Range(next_x, next_y) == 1 && land[next_y][next_x] == 1 && !visit[next_y][next_x]) {
				visit[next_y][next_x] = true;
				q.push({ next_x,next_y });
				v[cnt].push_back({ next_x,next_y });
			}
		}
	}
}

void bfs_length(int x, int y) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (land[j][i] && !visit[j][i]) {
				int length = abs(y - j) + abs(x - i);
				if (ans > length) ans = length;
			}
		}
	}
}

void init() {
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) visit[i][j] = false;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	v.resize(N * N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> land[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && land[i][j]) {
				vec.push_back({ j,i });
				bfs(j, i);
				cnt++;
			}
		}
	}

	init();

	for (int i = 0; i < cnt; i++) {
		bfs(vec[i].first, vec[i].second);
		for (int j = 0; j < v[i].size(); j++) {
			bfs_length(v[i][j].first, v[i][j].second);
		}
		init();
	}
	
	cout << ans - 1;
	return 0;
}