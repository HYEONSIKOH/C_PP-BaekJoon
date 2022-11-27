// 백준 17472 [프림 + BFS] 가장 작은 다리 여러개 만들기!
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M;
int land[10][10];
bool visit[10][10]{};
int ans;
int pos[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };

queue <pair<int, int>> q;
vector<vector<pair<int, int>>> v(6);
int cnt = 0;

int land_Range(int x, int y) {
	if (x >= 0 && y >= 0 && x < M && y < N) return 1;
	else return 0;
}

void bfs(int x, int y) {
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

// ======================= 최소신장트리 =======================

priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
vector<bool> visit_prim;
vector< vector<pair<int, int>> > vec_prim;

void prim(int s) {
	visit_prim[s] = true;

	for (auto& e : vec_prim[s]) if (!visit_prim[e.first]) pq.push({ e.second,e.first });

	while (!pq.empty()) {
		pair<int, int> p = pq.top();
		pq.pop();

		if (!visit_prim[p.second]) {
			ans += p.first;
			prim(p.second);
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int min = INF;
	int price;
	pair<int, int> p1, p2;

	cin >> N >> M; // Y가 N, X가 M

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cin >> land[i][j];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (land[i][j] && !visit[i][j]) {
				bfs(j, i);
				cnt++;
			}
		}
	}

	vec_prim.resize(cnt);
	visit_prim.resize(cnt);
	bool xpos = false, ypos = false;

	int j;
	for (int i = 0; i < cnt - 1; i++) {
		for (j = i+1; j < cnt; j++) {
			min = INF;
			for (int m = 0; m < v[i].size(); m++) {
				for (int n = 0; n < v[j].size(); n++) {
					if (v[i][m].first == v[j][n].first) {
						int x = v[i][m].first;
						int y1 = v[i][m].second;
						int y2 = v[j][n].second;

						if (y1 < y2) for (int k = y1 + 1; k < y2; k++) if (land[k][x]) xpos = true;
						if (y1 > y2) for (int k = y2 + 1; k < y1; k++) if (land[k][x]) xpos = true;

						price = abs(v[i][m].second - v[j][n].second) - 1;
						if (min > price && !xpos && price != 1) {
							p1 = v[i][m];
							p2 = v[j][n];
							min = price;
						}
					}

					else if (v[i][m].second == v[j][n].second) {
						int y = v[i][m].second;
						int x1 = v[i][m].first;
						int x2 = v[j][n].first;
						if (x1 < x2) for (int k = x1 + 1; k < x2; k++) if (land[y][k]) ypos = true;
						if (x1 > x2) for (int k = x2 + 1; k < x1; k++) if (land[y][k]) ypos = true;

						price = abs(v[i][m].first - v[j][n].first) - 1;
						if (min > price && !ypos && price != 1) {
							p1 = v[i][m];
							p2 = v[j][n];
							min = price;
						}
					}
					xpos = ypos = false;
				}
			}
			if (min != INF) {
				vec_prim[i].push_back({ j,min });
				vec_prim[j].push_back({ i,min });
			}
		}
	}

	prim(0);

	for (int i = 0; i < visit_prim.size(); i++) {
		if (!visit_prim[i]) {
			cout << -1;
			return 0;
		}
	}

	cout << ans;
	return 0;
}

